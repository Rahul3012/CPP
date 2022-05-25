#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "abcbe";
    int size = str.size();
    string temp;
    int startindex = 0;
    temp += str[0];
    int flag = 0,
        count = 0;
    int tempcount = 1;
    for (int i = 1; i < size; i++)
    {
        tempcount = 1;
        if (flag == 0)
        {
            for (int k = startindex; k < i; k++)
            {
                temp += str[k];
            }
            cout << "Unique: " << temp << " Count: " << temp.size() << endl;
        }
        int j = 0;
        cout << "str[i]:" << str[i] << " " << endl;
        for (; temp[j] != '\0'; j++)
        {
            cout << "temp[j]:" << temp[j] << endl;
            if (str[i] == temp[j])
            {
                flag = 1;
                cout << "Found " << temp << endl;
                temp = "";
                break;
            }
            else
            {
                tempcount++;
            }
        }
        if (i == str.size() - 1 && temp[j] != str[i])
        {
            if (temp.size() + 1 >= count)
            {
                count = temp.size() + 1;
                cout << "End count:" << count << endl;
            }
        }
        if (flag == 1)
        {
            startindex = j + 1;
            flag = 0;
        }
        if (tempcount > count)
        {
            count = tempcount;
        }
        temp = "";
    }
    cout << count;
}