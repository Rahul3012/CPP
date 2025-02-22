#include <iostream>
#include <span>
#include <expected>
#include <string>
#include <vector>

using namespace std;

class SecureData
{
public:
    SecureData(span<const char> data)
    {
        if (data.size() > maxSize)
        {
            throw length_error("Data exceed limit");
        }

        this->data.assign(data.begin(), data.end());
    }

    expected<string, string> getData() const
    {
        if (data.empty())
        {
            return unexpected("no data available");
        }
        return string(data.begin(), data.end());
    }

private:
    static constexpr size_t maxSize = 100;
    vector<char> data;
};

int main()
{
    try
    {
        const char sensitiveInfo = "Sensitive Information";
        SecureData secureData(span<const char>(sensitiveInfo, strlen(sensitiveInfo)));

        auto result = secureData.getData();
        if (result)
        {
            cout << "Retrieved Data: " << result << endl;
        }
        else
        {
            cerr << "Error: " << result.error() << endl;
        }
    }
    catch (const exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
}
