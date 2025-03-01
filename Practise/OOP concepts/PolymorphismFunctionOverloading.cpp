// compile time
#include <bits/stdc++.h>

using namespace std;

class FunctionOverloading
{
public:
    void func(int x)
    {
        cout << "x" << x << endl;
    }
    void func(float x)
    {
        cout << "x" << x << endl;
    }

    void func(double x)
    {
        cout << "x" << x << endl;
    }
};

int main()
{
    FunctionOverloading fn;
    fn.func(10);
    fn.func(10.10f);
    fn.func(10.10);
    return 0;
}
