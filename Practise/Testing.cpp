#include <iostream>
using namespace std;
int main()
{
    unsigned int a = 10;
    int b = 20;
    if (b > a)
    {
        cout << "Greator";
    }
    else
    {
        cout << "lesser";
    }

    bool x = true;
    bool y = false;

    if (~x || y)
    {
        cout << "part a";
    }
    else
    {
        cout << "part b";
    }

    float b1 = 100.90;
    void *ptr = &b1;
    void *ctr;

    cout << *(float *)ptr;

    int q = 5, f = 2;
    if (q & f)
    {
        cout << "PARTA";
    }
    else
    {
        cout << "PARTB";
    }
    cout << endl;
    cout << (q & f);

    return 0;
}