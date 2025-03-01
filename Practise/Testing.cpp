#include <iostream>
using namespace std;
int main()
{
    // unsigned int a = 10;
    // int b = 20;
    // if (b > a)
    // {
    //     cout << "Greator";
    // }
    // else
    // {
    //     cout << "lesser";
    // }

    // bool x = true;
    // bool y = false;

    // if (~x || y)
    // {
    //     cout << "part a";
    // }
    // else
    // {
    //     cout << "part b";
    // }

    // float b1 = 100.90;
    // void *ptr = &b1;
    // void *ctr;

    // cout << *(float *)ptr;

    // int q = 5, f = 2;
    // if (q & f)
    // {
    //     cout << "PARTA";
    // }
    // else
    // {
    //     cout << "PARTB";
    // }
    // cout << endl;
    // cout << (q & f);

    string str = "sample for testing";
    int index = 30;
    int i = str.length();

    for (int j = 17; j >= 0; j--)
    {
        if (str[i] == 's')
        {
            str[index] = 's';
            str[index - 1] = 's';
            index = index - 2;
        }
        else
        {
            str[index] = str[j];
            index--;
        }
    }

    for (int i = 0; i < str.length(); i++)
    {
        cout << str[i];
    }
    cout << endl;

    return 0;
}