// run time
#include <bits/stdc++>

using namespace std;

class base
{
public:
    virtual void print()
    {
        cout << "Hello base print" << endl;
    }
};

class derived : public base
{
public:
    void print()
    {
        cout << "Hello derived" << endl;
    }
};

int main()
{
    base *ptr;
    derived d;
    ptr = &d;

    ptr->print();
    return 0;
}