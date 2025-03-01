#include <iostream>
#include <crtdbg.h>

using namespace std;
#define _CRTDBG_MAP_ALLOC

class A
{
public:
    virtual ~A()
    {
        cout << "A destroyed" << endl;
    }
    int get()
    {
        return 100;
    }
};

class C : public A
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
        // cout << C::get() << endl;
        return 55;
    }
};

void print(A *a)
{
    cout << typeid(a).name() << " " << a->get() << endl;
}

int main()
{
    A *a = new C();
    // cout << b.get() << endl;
    print(a); // 100
    delete a;
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
}