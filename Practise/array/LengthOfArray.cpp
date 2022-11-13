#include <iostream>

using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << (sizeof(a) / sizeof(int)) << endl;
    return 0;
}