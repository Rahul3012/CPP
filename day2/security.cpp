// #include <iostream>
// #include <span>
// #include <expected>
// #include <string>
// #include <vector>

// using namespace std;

// class SecureData
// {
// public:
//     SecureData(span<const char> data)
//     {
//         if (data.size() > maxSize)
//         {
//             throw length_error("Data exceed limit");
//         }

//         this->data.assign(data.begin(), data.end());
//     }

//     expected<string, string> getData() const
//     {
//         if (data.empty())
//         {
//             return unexpected("no data available");
//         }
//         return string(data.begin(), data.end());
//     }

// private:
//     static constexpr size_t maxSize = 100;
//     vector<char> data;
// };

// int main()
// {
//     try
//     {
//         const char sensitiveInfo = "Sensitive Information";
//         SecureData secureData(span<const char>(sensitiveInfo, strlen(sensitiveInfo)));

//         auto result = secureData.getData();
//         if (result)
//         {
//             cout << "Retrieved Data: " << result << endl;
//         }
//         else
//         {
//             cerr << "Error: " << result.error() << endl;
//         }
//     }
//     catch (const exception &e)
//     {
//         cerr << "Exception: " << e.what() << endl;
//     }
// }
#include <span>
#include <iostream>

void print_chars(std::span<const char> text_span) {
    for (const char c : text_span) {
        std::cout << c;
    }
    std::cout << std::endl;
}

int main() {
    const char message[] = "Hello, World!";
    std::span<const char> message_span(message, sizeof(message) - 1); // Exclude null terminator

    print_chars(message_span); // Output: Hello, World!

    // Using a subspan
    std::span<const char> subspan = message_span.subspan(7);
    print_chars(subspan); // Output: World!

    return 0;
}
