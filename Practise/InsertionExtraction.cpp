#include <iostream>
using namespace std;
class A
{
    private:
        int a, b;
    public:
        void read(istream& is, A& a)
        {
            is >> a.a >> a.b;
        }
        
        void print(ostream& os, A& a)
        {
            os << a.a << " "<<a.b;
        }
};

template<typename T>
istream& operator >> (istream& is, T& a)
{
   a.read(is,a);
            return is; 
}

template<typename T2>
ostream& operator << (ostream& os, T2& a)
        {
            a.print(os,a);
            return os;
        }

int main() {
    A a;
    cin >> a;
    cout << a <<endl;
    return 0;
}
