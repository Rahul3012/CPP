#include "crow_all.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <boost/filesystem.hpp>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/oid.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;
using mongocxx::cursor;

using namespace std;
using namespace crow;
using namespace crow::mustache;

string getView(const string &filename, context &x)
{
  return load("../public/" + filename + ".html").render(x);
}

void sendFile(response &res, string filename, string contentType)
{
  ifstream in("../public/" + filename, ifstream::in);
  if (in)
  {
    ostringstream contents;
    contents << in.rdbuf();
    in.close();
    res.set_header("Content-Type", contentType);
    res.write(contents.str());
  }
  else
  {
    res.code = 404;
    res.write("Not found");
  }
  res.end();
}

void sendHtml(response &res, string filename)
{
  sendFile(res, filename + ".html", "text/html");
}

void sendImage(response &res, string filename)
{
  sendFile(res, "images/" + filename, "image/jpeg");
}

void sendScript(response &res, string filename)
{
  sendFile(res, "scripts/" + filename, "text/javascript");
}

void sendStyle(response &res, string filename)
{
  sendFile(res, "styles/" + filename, "text/css");
}

int main(int argc, char *argv[])
{
  crow::SimpleApp app;
  set_base(".");

  mongocxx::instance inst{};
  string mongoConnect = std::string(getenv("MONGODB_URI"));
  mongocxx::client conn{mongocxx::uri{mongoConnect}};
  auto collection = conn["heroku_f2rk7vwn"]["contacts"];

  CROW_ROUTE(app, "/styles/<string>")
  ([](const request &req, response &res, string filename)
   { sendStyle(res, filename); });

  CROW_ROUTE(app, "/scripts/<string>")
  ([](const request &req, response &res, string filename)
   { sendScript(res, filename); });

  CROW_ROUTE(app, "/images/<string>")
  ([](const request &req, response &res, string filename)
   { sendImage(res, filename); });

  CROW_ROUTE(app, "/about")
  ([](const request &req, response &res)
   { sendHtml(res, "about"); });

  CROW_ROUTE(app, "/contact/<string>")
  ([&collection](string email)
   {
      auto doc = collection.find_one(make_document(kvp("email", email)));
      return crow::response(bsoncxx::to_json(doc.value().view())); });

  CROW_ROUTE(app, "/contacts")
  ([&collection]()
   {
      mongocxx::options::find opts;
      opts.skip(9);
      opts.limit(10);
      auto docs = collection.find({}, opts);
      crow::json::wvalue dto;
      vector<crow::json::rvalue> contacts;
      contacts.reserve(10);

      for(auto doc : docs){
        contacts.push_back(json::load(bsoncxx::to_json(doc)));
      }
      dto["contacts"] = contacts;
      return getView("contacts", dto); });

  CROW_ROUTE(app, "/")
  ([](const request &req, response &res)
   { sendHtml(res, "index"); });

  char *port = getenv("PORT");
  uint16_t iPort = static_cast<uint16_t>(port != NULL ? stoi(port) : 18080);
  cout << "PORT = " << iPort << "\n";
  app.port(iPort).multithreaded().run();
}
