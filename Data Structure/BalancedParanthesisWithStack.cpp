#include <iostream>

using namespace std;

typedef struct stack
{
    int top;
    char opr[10];
} STK;

void init(STK *p)
{
    p->top = -1;
}

void push(STK *p, char ch)
{
    if (p->top == 9)
    {
        cout << "Overflow" << endl;
        return;
    }
    p->top++;
    p->opr[p->top] = ch;
}

void pop(STK *p)
{
    if (p->top == -1)
    {
        cout << "Overflow" << endl;
        return;
    }
    p->top--;
}

int main()
{
    char *s;
    int i = 0, flag = 0;
    STK p;
    init(&p);

    cout << "Enter Expression" << endl;
    cin >> s;

    while (s[i] != '\0')
    {
        if (s[i] == '(')
        {
            flag = 1;
            push(&p, s[i]);
        }
        else
        {
            if (s[i] == ')')
            {
                if (p.top == -1)
                {
                    break;
                }
                pop(&p);
            }
        }
        i++;
    }

    if (flag == 0)
    {
        cout << "No Paranthesis" << endl;
    }
    else
    {
        if (s[i] == '\0')
        {
            if (p.top == -1)
            {
                cout << "Balanced Paranthesis" << endl;
            }
            else
            {
                cout << "Extra at left" << endl;
            }
        }
        else
        {
            cout << "Extra at right" << endl;
        }
    }
}