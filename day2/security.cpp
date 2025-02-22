#include <iostream>
#include <span>
#include <optional> // Changed from expected
#include <string>
#include <vector>
#include <cstring> // Added cstring

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

    optional<string> getData() const // Changed to optional
    {
        if (data.empty())
        {
            return nullopt; // Changed from unexpected
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
        const char* sensitiveInfo = "Sensitive Information"; // Corrected the type
        SecureData secureData(span<const char>(sensitiveInfo, strlen(sensitiveInfo)));

        auto result = secureData.getData();
        if (result)
        {
            cout << "Retrieved Data: " << *result << endl; // Dereference optional
        }
        else
        {
            cerr << "Error: No data available" << endl; // Changed from result.error()
        }
    }
    catch (const exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
}
