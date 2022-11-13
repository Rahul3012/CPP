#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    string str = "asamples";
    sort(str.begin(), str.end());
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == str[i + 1])
        {
            cout << endl
                 << "duplicate found" << endl;
        }
        cout << str[i] << " ";
    }
    return 0;
}