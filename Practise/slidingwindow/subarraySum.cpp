#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr={1,2,3,4,5,6,7,8,9};
    vector<int> sumArr;
    sumArr.push_back(arr[0]+arr[1]+arr[2]);
    for(int j=1;j<arr.size();j++)
    {
        if(j+1 < arr.size() && j+2 < arr.size())
        {
            sumArr.push_back(sumArr[sumArr.size()-1]+arr[j+2]-arr[j-1]);
        }
        if(j+1 == arr.size() || j+2 == arr.size()) break;
    }
    
    for (int i=0;i<sumArr.size();i++)
    {
        cout << sumArr[i]<<endl;
    }
    return 0;
}
