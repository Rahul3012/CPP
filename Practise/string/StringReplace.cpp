#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1 = "This is C language";
    for (int i = 0; i < str1.length(); i++)
    {
        str1[i] == 'C' ? str1[i] = 'c' : str1[i] = str1[i];
    }
    cout << str1;
    return 0;
}