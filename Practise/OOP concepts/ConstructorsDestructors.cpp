#include <bits/stdc++.h>

using namespace std;

class Person
{
    int _salary;
    string _name;

public:
    Person()
    {
        _name = "Default";
        _salary = 10;
    }
    Person(string name, int salary)
    {
        _name = name;
        _salary = salary;
    }
    ~Person() {}
    void Details()
    {
        cout << "Person name is " << _name << endl;
        cout << "Person salary is " << _salary << endl;
    }
};

int main()
{
    Person employee;
    employee.Details();

    Person boss("Chris", 45);
    boss.Details();
    return 0;
}