#include <iostream>

using namespace std;

int main()
{
    int pointerArraySize = 0;
    cin >> pointerArraySize;
    int *arr = new int[pointerArraySize];
    for (int i = 0; i < pointerArraySize; i++)
    {
        int size = 0;
        cin >> size;
        arr[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = j;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        delete (arr[i]);
    }
}