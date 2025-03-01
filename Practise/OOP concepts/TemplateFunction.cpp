#include <iostream>
using namespace std;

template <typename T>
T Max(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    cout << Max<int>(8, 9) << endl;
    cout << Max<string>("ab", "bad") << endl;
    cout << Max<float>(10.10, 10.05) << endl;
    return 0;
}