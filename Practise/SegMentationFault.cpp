#include <iostream>

using namespace std;
// segmentation fault
int *function_ref()
{
    int n = 100;
    return &n;
}

int main()
{
    cout << *function_ref() << endl;
    return 0;
}