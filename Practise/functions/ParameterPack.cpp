// C++ program to demonstrate working of
// Variadic function Template
#include <iostream>
using namespace std;

// To handle base case of below recursive
// Variadic function Template
void print()
{
    cout << "I am empty function and "
            "I am called at last.\n";
}

// Variadic function Template that takes
// variable number of arguments and prints
// all of them.
template <typename T> //, typename... T2>
void print(T var1, auto... var2)
{
    cout << var1 << endl;

    print(var2...);
}

// Driver code
int main()
{
    print(1, 2, 3.14,
          "Pass me any "
          "number of arguments",
          "I will print\n");

    return 0;
}
