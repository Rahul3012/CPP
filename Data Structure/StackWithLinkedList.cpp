#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} NODE;

typedef struct stack
{
    NODE *top;
} STK;

void init(STK *p)
{
    p->top = NULL;
}

NODE *createnode(int d)
{
    NODE *a = (NODE *)malloc(sizeof(NODE));
    a->data = d;
    a->next = NULL;
    return a;
}

void push(STK *p, int d)
{
    NODE *a = createnode(d);
    a->next = p->top;
    p->top = a;
}

void pop(STK *p)
{
    NODE *a = p->top;
    if (p->top == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    p->top = a->next;
    free(a);
}

void display(STK *p)
{
    NODE *a = p->top;
    if (p->top == NULL)
    {
        cout << "Stack Empty" << endl;
        return;
    }
    cout << "Stack" << endl;
    while (a != NULL)
    {
        cout << a->data << " ";
        a = a->next;
    }
    cout << endl;
    return;
}

int main()
{
    STK p;
    init(&p);

    push(&p, 10);
    push(&p, 12);
    push(&p, 14);
    push(&p, 11);
    push(&p, 13);
    push(&p, 16);

    display(&p);

    pop(&p);
    pop(&p);
    pop(&p);
    pop(&p);

    display(&p);
    return 0;
}
