#include <iostream>
#include <span>
#include <expected> // Using expected
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class SecureData {
public:
    SecureData(span<const char> data) {
        if (data.size() > maxSize) {
            throw length_error("Data exceed limit");
        }
        this->data.assign(data.begin(), data.end());
    }

    expected<string, string> getData() const { // Using expected
        if (data.empty()) {
            return unexpected("No data available"); // Using unexpected
        }
        return string(data.begin(), data.end());
    }

private:
    static constexpr size_t maxSize = 100;
    vector<char> data;
};

int main() {
    try {
        const char* sensitiveInfo = "Sensitive Information";
        SecureData secureData(span<const char>(sensitiveInfo, strlen(sensitiveInfo)));

        auto result = secureData.getData();
        if (result.has_value()) { // Checking if a value is present
            cout << "Retrieved Data: " << result.value() << endl; // Accessing the value
        } else {
            cerr << "Error: " << result.error() << endl; // Accessing the error
        }
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
}
