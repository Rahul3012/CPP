#include <stdio.h>
#include <iostream>
using namespace std;
const int MAX = 1000;
int replaceSpaces(char str[])
{
    int space_count = 0, i;
    for (i = 0; str[i]; i++)
        if (str[i] == ' ')
            space_count++;

    while (str[i - 1] == ' ')
    {
        space_count--;
        i--;
    }

    int new_length = i + space_count * 2 + 1;
    cout << new_length << endl;
    if (new_length > MAX)
        return -1;

    int index = new_length - 1;

    str[index--] = '\0';
    int k = 0;

    for (int j = i - 1; j >= 0; j--)
    {
        if (str[j] == ' ')
        {
            str[index] = '0';
            cout << "str[" << index << "]:"
                 << "0\t" << endl;
            // cout << "str[" << j << "]:" << str[j] << endl;
            str[index - 1] = '2';
            cout << "str[" << index - 1 << "]:"
                 << "2\t" << endl;
            // cout << "str[" << j << "]:" << str[j] << endl;
            str[index - 2] = '%';
            cout << "str[" << index - 2 << "]:"
                 << "%\t" << endl;
            // cout << "str[" << j << "]:" << str[j] << endl;
            index = index - 3;
        }
        else
        {
            str[index] = str[j];
            cout << "str[" << index << "]:" << str[index] << '\t';
            cout << "str[" << j << "]:" << str[j] << endl;
            index--;
        }
    }

    return new_length;
}

int main()
{
    char str[MAX] = "Replacing spaces with %20";

    int new_length = replaceSpaces(str);
    cout << "new length" << new_length << endl;
    for (int i = 0; i < new_length; i++)
        printf("%c", str[i]);
    return 0;
}
