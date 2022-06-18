#include <iostream>
#include <cstdlib>

using namespace std;

struct stack
{
    char opr[40];
    int top;
} s;

void push(char ch)
{
    if (ch == '(')
        return;
    s.top++;
    s.opr[s.top] = ch;
    cout << s.opr[0] << " " << s.opr[1] << endl;
}

void pop()
{
    --s.top;
}

int isEmpty()
{
    cout << "test" << endl;
    return s.top == -1;
}

int preced(char stk, char opr)
{
    if (stk != '(' && stk == ')')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char istr[] = "a+b*";
    char pstr[40];

    int i = 0, j = 0;
    char ch;
    s.top = -1;
    cout << "Enter infix expression" << endl;
    // cin >> istr;
    cout << istr << endl;
    while (istr[i] != '\0')
    {
        if (isalpha(istr[i]))
        {
            pstr[j++] = istr[i];
        }
        else
        {
            while (!isEmpty() && preced(s.opr[s.top], istr[i]))
            {
                ch = s.opr[s.top];
                pstr[j++] = ch;
                pop();
            }
            if (isEmpty() || istr[i] != ')')
            {
                push(istr[i]);
            }
            // else
            // {
            //     pop();
            // }
        }
        i++;
    }

    while (!isEmpty())
    {
        ch = s.opr[s.top];
        pstr[j++] = ch;
        pop();
    }
    pstr[j] = '\0';
    cout << "PostFix expression" << endl;
    cout << pstr;
}