#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    int salary;

    void printName()
    {
        cout << "Person name is " << name << endl;
    }
    void printSalary();
};

void Person::printSalary()
{
    cout << "Person salary is " << salary << endl;
}

int main()
{
    Person employee;

    employee.name = "Rahul";
    employee.salary = 30;

    employee.printName();
    employee.printSalary();
    return 0;
}