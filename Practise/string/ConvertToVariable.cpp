#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char ch[] = "thisIsEnvironmentVariable"; // for cpp variable pass this_is_environment_variable
    // for (int i = 0; i < 256; i++)
    // {
    //     printf("%d : %c \n", i, i);
    // }
    bool cppVariable = false;
    for (int l = 0; l < sizeof(ch); l++)
    {
        if (ch[l] == '_')
        {
            cppVariable = true;
            break;
        }
    }
    int j = 0;
    if (cppVariable)
    {
        char converted[sizeof(ch)];
        for (int i = 0; i < sizeof(ch); i++)
        {
            if (ch[i] == '_')
            {
                converted[j++] = ch[i + 1] - 32;
                i++;
            }
            else
            {
                converted[j++] = ch[i];
            }
        }
        cout << converted;
    }
    else
    {
        char *converted;
        converted = (char *)calloc(sizeof(ch), sizeof(char));
        for (int i = 0; i < sizeof(ch); i++)
        {
            if (ch[i] >= 65 && ch[i] <= 90)
            {
                converted[j++] = '_';
                converted[j++] = ch[i] + 32;
                converted = (char *)realloc(converted, (sizeof(converted) + sizeof(char)));
            }
            else
            {
                converted[j++] = ch[i];
            }
        }
        cout << converted;
    }

    return 0;
}