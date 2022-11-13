#include <iostream>
using namespace std;

class A
{
public:
    ~A()
    {
        cout << "A destroyed" << endl;
    }
    virtual int get()
    {
        return 100;
    }
};

class C : virtual public A
{
public:
    ~C()
    {
        cout << "C destroyed" << endl;
    }
    int get()
    {
        return 10;
    }
};

class B : virtual public A
{
public:
    ~B()
    {
        cout << "B destroyed" << endl;
    }
    int get()
    {
        return 5;
    }
};
class D : public virtual C, public virtual B
{
public:
    ~D()
    {
        cout << "D Destroyed" << endl;
    }
    int get()
    {
        cout << C::get() << endl;
        return 55;
    }
};

void print(A *a)
{
    cout << typeid(a).name() << " " << a->get() << endl;
}

int main()
{
    A a;
    B b;
    D d;
    // cout << b.get() << endl;
    print(&a); // 100
    print(&b); // 5
    print(&d); // 10
}