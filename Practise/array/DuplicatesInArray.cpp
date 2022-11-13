#include <iostream>
using namespace std;

int main()
{
    int N = 9;
    // cin>>N;
    int arr[N] = {1, 1, 2, 3, 2, 4, 5, 5, 4};
    // for(int i=0;i<N;i++)
    // {
    //     cin>>a[i];
    // }
    int counter = 0;
    int *duplicate;
    duplicate = (int *)malloc(sizeof(int));
    for (int j = 0; j < N - 1; j++)
    {
        for (int k = j + 1; k < N; k++)
        {
            if (arr[j] == arr[k])
            {
                int flag = 0;
                for (int h = 0; h < counter; h++)
                {
                    if (duplicate[h] == arr[k])
                    {
                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    duplicate[counter++] = arr[k];
                    duplicate = (int *)realloc(duplicate, sizeof(int) * counter);
                }
                flag = 0;
            }
        }
    }

    if (counter == 0)
    {
        cout << -1;
    }
    for (int g = 0; g < counter; g++)
    {
        cout << duplicate[g] << " ";
    }
    free(duplicate);
    return 0;
}
