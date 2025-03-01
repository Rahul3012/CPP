#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long size;
    cin>>size;
    vector<int> arr(size);
    for(int& nm: arr)
    {
       cin>>nm;
    }
    long no_of_searches;
    cin>>no_of_searches;
    int query{};
    while (no_of_searches--) {
        cin >> query;
        auto it = lower_bound(begin(arr), end(arr), query);
        bool equal = *it == query;
        cout << (equal ? "Yes" : "No") << " " << it - begin(arr) + 1 << endl;
    }
    return 0;
}
