#include <stdio.h>
#include <stdlib.h>
struct DoublyCircularLinkedlist
{
    int data;
    struct DoublyCircularLinkedlist *next;
    struct DoublyCircularLinkedlist *prev;
};
typedef struct DoublyCircularLinkedlist node;
node *CreateNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Memory Error\n");
        return (NULL);
    }
    else
    {
        new->data = data;
        new->next = new->prev = NULL;
        return (new);
    }
}
void Print(node *head)
{
    if (head == NULL)
    {
        printf("Linked list Empty \n");
    }
    else
    {
        node *p = head;
        while (p->next != head)
        {
            printf("%d\t", p->data);
            p = p->next;
        }
        printf("%d\t", p->data);
        printf("\n\n");
    }
}
void InsertAtFirst(node **head, int data)
{
    node *new = CreateNode(data);
    if (*head == NULL)
    {
        *head = new;
        new->next = new;
        new->prev = new;
    }
    else
    {
        node *p = *head;
        node *q = (*head)->prev;
        new->prev = p->prev;
        new->next = p;
        p->prev = new;
        q->next = new;
        *head = new;
    }
}
node *InsertAtLast(node **head, int data)
{
    node *new = CreateNode(data);
    if (*head == NULL)
    {
        *head = new;
        new->next = new;
        new->prev = new;
    }
    else
    {
        node *p = *head;
        while (p->next != *head)
        {
            p = p->next;
        }
        node *h = p->next;
        p->next = new;
        new->prev = p;
        new->next = h;
        h->prev = new;
    }
}
void InsertAtAnyPosition(node **head, int pos, int data)
{
    node *new = CreateNode(data);
    int i = 1;
    node *p = *head;
    node *q;
    if (*head == NULL)
    {
        *head = new;
        new->next = new;
        new->prev = new;
    }
    if (pos == 1)
    {
        InsertAtFirst(head, data);
    }
    else
    {
        while (p->next != *head && i < pos - 1)
        {
            p = p->next;
            i++;
        }
        if (p->next == *head)
        {
            printf("Invalid Index \n");
            return;
        }
        else
        {
            q = p->next;
            p->next = new;
            new->prev = p;
            new->next = q;
            q->prev = new;
        }
    }
}
void DeleteFirstNode(node **head)
{
    if (*head == NULL)
    {
        printf("Empty \n");
        return;
    }
    else
    {
        node *p = *head;
        node *q = p->prev;
        *head = (*head)->next;
        (*head)->prev = q;
        q->next = *head;
        int val = p->data;
        free(p);
        printf("The first node has been Deleted So, %d value has Delete\n", val);
    }
}
void DeleteLastNode(node **head)
{
    if (*head == NULL)
    {
        printf("Empty \n");
        return;
    }
    else
    {
        node *h = *head;
        node *p = h->prev;
        node *q = p->prev;
        int val = p->data;
        h->prev = q;
        q->next = h;
        free(p);
        printf("The last node has been Deleted So, %d value has Delete\n", val);
    }
}
void DeleteAtPos(node **head, int pos)
{
    if (*head == NULL && pos < 0)
    {
        printf("Error \n");
        return;
    }
    if (pos == 1)
    {
        DeleteFirstNode(head);
    }

    else
    {
        int i = 1;
        node *p = *head;
        while (p->next != *head && i < pos - 1)
        {
            p = p->next;
            i++;
        }
        if (p->next == *head)
        {
            printf("Invalid index \n");
            return;
        }
        node *q = p->next;
        node *k = q->next;
        p->next = k;
        k->prev = p;
        int val = q->data;
        free(q);
        printf("The %d th node has been Deleted So, %d value has Delete\n", pos, val);
    }
}
int main(int argc, char const *argv[])
{
    node *head = NULL;
    int i = 0;
    for (i = 0; i < 10; i++)
        InsertAtFirst(&head, (10 + i));
    Print(head);
    for (i = 0; i < 10; i++)
        InsertAtLast(&head, (20 + i));
    Print(head);
    InsertAtAnyPosition(&head, 3, 600);
    Print(head);
    DeleteFirstNode(&head);
    Print(head);
    DeleteLastNode(&head);
    Print(head);
    DeleteAtPos(&head, 5);
    Print(head);
    return 0;
}
