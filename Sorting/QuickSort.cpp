#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    cout << "swap " << *a << " " << *b;
    int t = *a;
    *a = *b;
    *b = t;
}

void pivot(int *a, int low, int high)
{
    cout << "check pivot " << a[low] << " " << a[high] << endl;
    if (a[low] < a[high])
    {
        swap(a + low, a + high);
    }
}
int partition(int a[], int low, int high)
{
    int i, j, val;
    i = low;
    j = high;
    pivot(a, low, high - 1);
    val = a[i];
    cout << endl
         << "val" << val << endl;
    cout << "i " << i << "j " << j << endl;
    do
    {
        do
        {
            ++i;
        } while (a[i] < val);
        cout << "\n"
             << "i " << i << endl;
        do
        {
            --j;
        } while (a[j] > val);
        cout << "\n"
             << "j " << j << endl;
        if (i < j)
        {
            swap(a + i, a + j);
        }
    } while (i < j);
    swap(a + j, a + low);
    cout << endl;
    return i;
}
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);

        cout << endl
             << "pivot index" << pi << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << a[i] << " ";
        }
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}
int main()
{
    int a[6] = {24, 9, 29, 14, 19, 27};

    // int pivotfixposition = partition(a, 0, 6);
    // cout << "\n"
    //      << pivotfixposition << endl;

    quickSort(a, 0, 6);
    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}