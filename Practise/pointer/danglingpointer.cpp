#include <iostream>

using namespace std;

int main()
{
    int *p = (int *)malloc(sizeof(int));
    {
        int x = 10;
        p = &x;
        *p = 42;
    }
    cout << *p << endl;
    return 0;
}