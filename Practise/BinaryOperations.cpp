#include <iostream>
using namespace std;

int main()
{
    // print number as binary

    int a = 8;
    cout << endl
         << "a:" << ((a << 4) & 1)
         << ((a << 3) & 1)
         << ((a << 2) & 1)
         << ((a << 1) & 1);
    cout << endl;
    for (int i = 31; i >= 0; i--)
        cout << ((a >> i) & 1);
    cout << endl;
    for (int i = 31; i >= 0; i--)
        cout << "i:" << i << ":" << ((a >> i)) << "\t" << ((a >> i) & 1) << endl;

    // print 2's power
    cout << "2 to the power 3:" << (2 << 3) << endl;

    // still working on binary operation
    return 0;
}