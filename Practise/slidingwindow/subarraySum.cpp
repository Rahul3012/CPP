// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Write C++ code here
    vector<int> arr={1,2,3,4,5,6,7,8,9};
    vector<int> sumArr;
    sumArr.push_back(arr[0]+arr[1]+arr[2]);
    int cnt=0;
    int arrSize = arr.size();
    for(int j=1;j<arrSize;j++)
    {
        if(j+1 < arrSize && j+2 < arrSize)
        {
            sumArr.push_back(sumArr[cnt++]+arr[j+2]-arr[j-1]);
        }else break;
    }
    
    for (int i=0;i<sumArr.size();i++)
    {
        cout << sumArr[i]<<endl;
    }
    return 0;
}
