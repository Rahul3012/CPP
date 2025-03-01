// compile time
#include <iostream>
using namespace std;

class Complex
{
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    Complex operator+(Complex const &obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;

        return res;
    }

    void print()
    {
        cout << imag << "    " << real << endl;
    }
};

int main()
{
    Complex c1(10, 20), c2(30, 40);
    Complex c3 = c1 + c2;
    c3.print();
}