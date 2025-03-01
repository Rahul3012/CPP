#include <iostream>
using namespace std;

class A
{
public:
    void show()
    {
        cout << "Hello from A \n";
    }
};

class B : public virtual A
{
public:
    void show2()
    {
        cout << "Hello from B \n";
    }
};

class C : public virtual A
{
public:
    void show()
    {
        cout << "Hello from C \n";
    }
};

class D : public virtual B, public virtual C
{
};

int main()
{
    D object;
    object.show();
}