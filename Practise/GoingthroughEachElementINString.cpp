#include <iostream>
using namespace std;

int main()
{
    string str = "TestOneTwoThreeFour";

    cout << str.length();

    for (auto &ch : str)
        cout << ch;

    return 0;
}