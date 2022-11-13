#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> primes;

    primes.push_back({100, 100});

    vector<vector<int>> *pt = &primes;

    cout << pt;
    return 0;
}