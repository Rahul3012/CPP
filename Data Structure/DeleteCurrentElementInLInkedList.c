#include <stdio.h>
#include <stdlib.h>
// using namespace std;
typedef struct Node
{
    int value;
    struct Node *next;
} NODE;

NODE *head = NULL;

NODE *CreateNode(NODE *nd, int value)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->value = value;
    node->next = NULL;

    if (nd == NULL)
    {
        nd = node;
    }
    else
    {
        nd->next = node;
        nd = nd->next;
    }
    return nd;
}

void traverse(NODE *nd)
{
    while (nd->next != NULL)
    {
        printf("%d ", nd->value);
        nd = nd->next;
    }
    printf("%d\n", nd->value);
}

void DeleteCurrent(NODE *nd, int counter)
{
    int position = 0;
    while (position++ < counter)
    {
        nd = nd->next;
    }
    if (nd->next == NULL)
    {
        free(nd);
    }
    else
    {
        NODE *temp = nd->next;
        if (temp->next == NULL)
        {
            nd->value = temp->value;
            nd->next = NULL;
        }
        else
        {
            nd->next = temp->next;
            nd->value = temp->value;
        }
        free(temp);
    }
}

int main(int argv[])
{
    NODE *nd = CreateNode(NULL, 10);
    head = nd;
    nd->next = CreateNode(nd, 20);
    nd = nd->next;
    nd->next = CreateNode(nd, 30);
    nd = nd->next;
    nd->next = CreateNode(nd, 40);
    nd = nd->next;
    nd->next = CreateNode(nd, 50);

    traverse(head);

    DeleteCurrent(head, argv[0]);
    traverse(head);

    return 0;
}