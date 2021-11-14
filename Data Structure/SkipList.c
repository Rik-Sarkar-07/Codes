#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *down;
    int toss;
};
typedef struct Node node;
int Random()
{
    static int i = 1;
    if (i > 200)
    {
        i--;
    }
    else
    {
        i++;
    }
    time_t t = time(0);
    int d = t % i;
    return (d % 2);
}
node *CreateNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    new->down = NULL;
}
node *Reffers(node *head, int data)
{
    node *p = head;
    if (p->data == data)
        return (p);
    else
    {
        while (p->data != data && p->next != NULL)
        {
            p = p->next;
        }
        if (p->data == data)
            return (p);
        else
            return (NULL);
    }
}
void InsertNode(node **head, int data)
{
    if (*head == NULL)
    {
        *head = CreateNode(data);
    }
    else
    {
        node *p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = CreateNode(data);
    }
}
void InsertNodeLevel(node **head, node *link, int data)
{
    if (*head == NULL)
    {
        *head = CreateNode(data);
        (*head)->down = link;
    }
    else if (link == NULL)
        return;
    else
    {

        node *p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        node *q = CreateNode(data);

        p->next = q;
        q->down = link;
    }
}
void Print(node *head)
{
    node *p = head;
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n\n");
}
node *Searching(node *head, int data)
{

    if (head->data == data)
    {
        return head;
    }
    else
    {
        node *p = head;
        while (p->data != data && p->next != NULL)
        {
            p = p->next;
        }
        if (p->data == data)
        {
            return (p);
        }
        else
        {
            head = head->down;
            return (Searching(head, data));
        }
    }
}
int main(int argc, char const *argv[])
{
    node *head[2];
    // Level 0 ....
    head[0] = NULL;
    for (int i = 0; i <= 20; i++)
        InsertNode(&head[0], (10 + i));
    printf("\t Main Linked list \n");
    Print(head[0]);
    // Level 1 ....
    head[1] = NULL;
    node *linking[21];
    for (int i = 0; i <= 20; i++)
    {
        if (Random() == 1)
        {
            linking[i] = Reffers(head[0], (10 + i));
            InsertNodeLevel(&head[1], linking[i], (10 + i));
        }
    }
    printf("\t Level 1 Linked list \n");
    Print(head[1]);
    // Level 2
    head[2] = NULL;
    node *link[21];
    for (int i = 0; i <= 20; i++)
    {
        if (Random() == 1)
        {
            link[i] = Reffers(head[1], (10 + i));
            InsertNodeLevel(&head[2], link[i], (10 + i));
        }
    }
    printf("\t Level 2 Linked list \n");
    Print(head[2]);
    int sh;
    printf("Enter Element = ");
    scanf("%d", &sh);

    node *f = Searching(head[2], sh);
    printf("%d\n", f->data);

    return 0;
}
