#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "saaasaas";
    bool palindrome = true;
    for (int i = 0; i < str.size() / 2; i++)
    {
        cout << str[i] << " == " << str[(str.size() - 1) - i] << "?" << endl;
        if (str[i] != str[(str.size() - 1) - i])
        {
            palindrome = false;
            break;
        }
    }
    if (palindrome)
    {
        cout << "string palindrome";
    }
    else
    {
        cout << "not palindrome";
    }
    return 0;
}