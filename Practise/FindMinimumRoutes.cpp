#include <iostream>
#include <vector>
using namespace std;

int sqrtAddition(vector<int> a)
{
    int additionresult = 0;
    // can use loop here if there are more than 2 member in array
    additionresult = a[0] * a[0] + a[1] * a[1];
    return additionresult;
}

void swap(vector<int> &a, vector<int> &b)
{
    vector<int> temp = a;
    a = b;
    b = temp;
}

void pivot(vector<vector<int>> &a, int low, int high)
{
    if (sqrtAddition(a[low]) < sqrtAddition(a[high]))
    {
        swap(a[low], a[high]);
    }
}

int partition(vector<vector<int>> &a, int low, int high)
{
    int i, j, val;
    i = low;
    j = high + 1;
    pivot(a, low, high - 1);
    val = sqrtAddition(a[i]);
    do
    {
        do
        {
            ++i;
        } while (sqrtAddition(a[i]) < val);
        do
        {
            --j;
        } while (sqrtAddition(a[j]) > val);
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    } while (i < j);
    swap(a[j], a[low]);
    return j;
}
void quickSort(vector<vector<int>> &a, int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main()
{
    vector<vector<int>> arr = {{2, 3}, {5, 3}, {6, 3}, {1, 1}, {2, 4}, {3, 3}, {6, 8}};
    quickSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
