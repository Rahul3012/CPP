#include <iostream>
using namespace std;

class Person
{
    int id;
    char name[100];

public:
    void setPersionDetails()
    {
        cout << "Enter person id:";
        cin >> id;
        fflush(stdin);
        cout << "\nEnter Person name:";
        cin.get(name, 100);
    }

    void deisplayPersonDetails()
    {
        cout << "Person Name:" << name << endl;
    }
};

class Employee : public Person
{
    int salary;

public:
    void setEmployeeDetails()
    {
        setPersionDetails();
        fflush(stdin);
        cout << "Enter Salary:";
        cin >> salary;
    }
    void displayEmployeeDeails()
    {
        deisplayPersonDetails();
        cout << "\nSalary:" << salary << endl;
    }
};

int main()
{
    Employee emp;
    emp.setEmployeeDetails();
    emp.displayEmployeeDeails();
    return 0;
}
