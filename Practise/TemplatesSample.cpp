#include <iostream>

class Person
{
public:
    void print(std::string className)
    {
        std::cout << className << std::endl;
    }
    void print(int number)
    {
        std::cout << number << std::endl;
    }
};

class Manager : public Person
{
};

class Employee : public Person
{
};

template <class T>
class C
{
public:
    void say(T obj)
    {
        obj.print(typeid(obj).name());
        obj.print(typeid(obj).hash_code());
        // If T::print() were static, you could call it like that instead.
    }
};

int main()
{
    Manager a;
    Employee b;
    C<Manager> c; // template for C demands a class, not an object!
                  // in practice this would mean you write 'A' instead of 'a' here
    c.say(a);
    C<Employee> d; // same here
    d.say(b);
}