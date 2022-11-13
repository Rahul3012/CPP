#include <stack>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    string str = "bbtablud";
    stack<string> stk;
    int count = 0;
    for (char ch : str)
    {
        stk.push(ch);
        count = stk.size();
        for (int i = stk.size(); i >= 0; i--)
        {
            if (stk[i] == ch)
            {
                stk = new stack<string>();
            }
        }
    }
    printf("%d", count);
    return count;
}