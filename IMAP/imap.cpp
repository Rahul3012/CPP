#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main()
{
    try
    {
        boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query("rahullokhande3012@gmail.com", "imap");
        tcp::socket socket(io_service);
        boost::asio::connect(socket, resolver.resolve(query));
        boost::asio::streambuf request;
        std::ostream request_stream(&request);
        request_stream << "rahullokhande3012@gmail.com 301216973012rlrl\r\n";
        boost::asio::write(socket, request);
        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\r\n");
        std::istream response_stream(&response);
        std::string tag, response_code;
        response_stream >> tag >> response_code;
        if (response_code != "OK")
        {
            throw std::runtime_error("Login failed");
        }
        request_stream << "tag SELECT INBOX\r\n";
        boost::asio::write(socket, request);
        boost::asio::read_until(socket, response, "\r\n");
        response_stream.clear();
        response_stream.str("");
        boost::asio::read_until(socket, response, "\r\n");
        response_stream.str(boost::asio::buffer_cast<const char *>(response.data()));
        std::cout << response_stream.str();
        boost::asio::read_until(socket, response, "\r\n");
        response_stream.clear();
        response_stream.str("");
        while (boost::asio::read_until(socket, response, "\r\n") != 0)
        {
            response_stream.str(boost::asio::buffer_cast<const char *>(response.data()));
            std::cout << response_stream.str();
            response.consume(response.size());
        }
        request_stream << "tag LOGOUT\r\n";
        boost::asio::write(socket, request);
        boost::asio::read_until(socket, response, "\r\n");
        response_stream.clear();
        response_stream.str("");
        boost::asio::read_until(socket, response, "\r\n");
        response_stream.str(boost::asio::buffer_cast<const char *>(response.data()));
        std::cout << response_stream.str();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
