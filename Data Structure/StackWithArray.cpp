#include <iostream>
#define MAX 5

using namespace std;

typedef struct stack
{
    int arr[MAX];
    int top;
} STK;

void init(STK *p)
{
    p->top = -1;
}

void push(STK *p, int elem)
{
    if (p->top == MAX - 1)
    {
        cout << "overflow" << endl;
        return;
    }
    p->top++;
    p->arr[p->top] = elem;
}

void pop(STK *p)
{
    if (p->top == -1)
    {
        cout << "Underflow" << endl;
        return;
    }
    p->top--;
}

void display(STK *p)
{
    int i = 0;
    if (p->top == -1)
    {
        cout << "Stack Empty" << endl;
        return;
    }

    cout << "Stack Data:";

    for (i = p->top; i >= 0; i--)
    {
        cout << " " << p->arr[i];
    }
    cout << endl;
}

int main()
{
    STK p;
    init(&p);

    push(&p, 12);
    push(&p, 13);
    push(&p, 14);
    push(&p, 15);

    display(&p);

    pop(&p);
    pop(&p);

    display(&p);

    return 0;
}