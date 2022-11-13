#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "bbtablud";
    int size = str.size();
    int startindex = 0;
    int count = 0;
    int tempcount = 1;
    for (int i = 1; i < size; i++)
    {
        tempcount = 1;
        cout << "starting of loop startIndex:" << startindex << endl;
        for (int k = startindex; k < i; k++)
        {
            if (str[k] == str[i])
            {
                startindex = k + 1;
                cout << "startIndex changes" << endl;
            }
            else
            {
                tempcount++;
            }
        }
        cout << "after second of loop startIndex:" << startindex << "Tempcount" << tempcount << endl;
        if (count < tempcount)
            count = tempcount;
    }
    cout << count;
}
