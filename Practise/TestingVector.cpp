#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> *a, vector<int> *b)
{
    vector<int> temp = *a;
    *a = *b;
    *b = temp;
}
void update(vector<int> &a)
{
    a[0] = 1234;
}

void add(vector<int> &a)
{
    a[0] = 123;
    update(a);
}

int main()
{
    vector<vector<int>> a = {{1, 1}, {2, 2}};

    add(a[0]);
    cout << a[0][0] << endl;

    vector<vector<int>> b;

    cout << b.size() << endl;
    return 0;
}