#include <stdio.h>
using namespace std;
#define M 5

struct queue
{
    int arr[M];
    int fr, rr;
} q;

void init()
{
    q.rr = -1;
    q.fr = 0;
}

void insert(int d)
{
    if (q.rr == M - 1)
    {
        printf("\nOverflow");
    }
    ++q.rr;
    q.arr[q.rr] = d;
}
void removequeue()
{
    if (q.rr < q.fr)
    {
        printf("\nUnderflow");
        return;
    }
    ++q.fr;
}

void display()
{
    int i = q.fr;

    if (q.rr < q.fr)
    {
        printf("empty queue");
        return;
    }
    printf("\nData\n");
    for (i = q.fr; i <= q.rr; i++)
    {
        printf("%4d", q.arr[i]);
    }
    return;
}

int main()
{
    int opt, d;
    init();
    while (1)
    {
        printf("\nQueue Array\n Menu \n 1.Insert \n 2.Remove \n 3.Display \n options: ");
        scanf("%d", &opt);
        if (opt > 3)
            break;
        switch (opt)
        {
        case 1:
            printf("\nEnter Data");
            scanf("%d", &d);
            insert(d);
            break;
        case 2:
            removequeue();
            break;
        case3:
            display();
            break;
        }
    }
    return 0;
}