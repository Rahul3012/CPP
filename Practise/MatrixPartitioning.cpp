#include <iostream>
using namespace std;

int main()
{
    int x = 20, y = 20;
    int arr[x][y];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            arr[i][j] = j + 1;
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    int arr11[x][10];
    for (int i = 0; i < x; i++)
    {
        arr11[i][0] = arr[i][0];
        int changed = 0;
        for (int j = 0; j < y; j += 2)
        {
            arr11[i][changed++] = arr[i][j];
        }
    }

    cout << "Sliced vertically" << endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < (y / 2); j++)
        {
            cout << arr11[i][j] << "\t";
        }
        cout << endl;
    }

    int arr12[x][10];
    for (int i = 0; i < x; i++)
    {
        arr12[i][0] = arr[i][0];
        int changed = 0;
        for (int j = 1; j < y; j += 2)
        {
            arr12[i][changed++] = arr[i][j];
        }
    }

    cout << "Sliced vertically part2" << endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < (y / 2); j++)
        {
            cout << arr12[i][j] << "\t";
        }
        cout << endl;
    }

    int arr111[10][10]; // this would be array sliced to array 11 horizontaly with even positions
    int arr112[10][10]; // with odd positions

    int arr121[10][10]; // this would be array sliced to array 12 horizontly with even positions
    int arr122[10][10]; // with odd positions

    int changed = 0;
    for (int i = 0; i < x; i += 2)
    {
        for (int j = 0; j < 10; j++)
        {
            arr111[changed][j] = arr11[i][j];
        }
        changed++;
    }

    changed = 0;
    for (int i = 1; i < x; i += 2)
    {
        for (int j = 0; j < 10; j++)
        {
            arr112[changed][j] = arr11[i][j];
        }
        changed++;
    }

    cout << "Horizontaly sliced arr11 part1" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr111[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Horizontaly sliced arr11 part2" << endl;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr112[i][j] << "\t";
        }
        cout << endl;
    }

    changed = 0;
    for (int i = 0; i < x; i += 2)
    {
        for (int j = 0; j < 10; j++)
        {
            arr121[changed][j] = arr12[i][j];
        }
        changed++;
    }

    changed = 0;
    for (int i = 1; i < x; i += 2)
    {
        for (int j = 0; j < 10; j++)
        {
            arr122[changed][j] = arr12[i][j];
        }
        changed++;
    }

    cout << "Horizontaly sliced arr12 part1" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr121[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Horizontaly sliced arr12 part2" << endl;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr122[i][j] << "\t";
        }
        cout << endl;
    }

    //---------------------------------------------------------------------
    // int arr2[10][y];
    // int changedI = 0;
    // for (int i = 0; i < x; i += 2)
    // {
    //     for (int j = 0; j < y; j++)
    //     {
    //         arr2[changedI][j] = arr[i][j];
    //     }
    //     changedI++;
    // }
    // cout << "Sliced flat" << endl;

    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < y; j++)
    //     {
    //         cout << arr2[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    // changedI = 0;
    // int arr21[10][y];
    // for (int i = 1; i < x; i += 2)
    // {
    //     for (int j = 0; j < y; j++)
    //     {
    //         arr21[changedI][j] = arr[i][j];
    //     }
    //     changedI++;
    // }

    // cout << "Sliced flat part2" << endl;

    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < y; j++)
    //     {
    //         cout << arr2[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
}