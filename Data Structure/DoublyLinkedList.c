#include <stdio.h>
#include <stdlib.h>
struct DoublyLinkedList
{
    int data;
    struct DoublyLinkedList *next;
    struct DoublyLinkedList *prev;
};
typedef struct DoublyLinkedList node;
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
        new->prev = NULL;
        new->next = NULL;
        return (new);
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
    printf("\n");
}
node *InsertionAtFirst(node *head, int data)
{
    if (head == NULL)
    {
        head = CreateNode(data);
        return (head);
    }
    else
    {
        node *new = CreateNode(data);
        new->next = head;
        head->prev = new;
        head = new;
        return (head);
    }
}
node *InsertionAtLast(node *head, int data)
{
    if (head == NULL)
    {
        head = CreateNode(data);
        return (head);
    }
    else
    {
        node *new = CreateNode(data);
        node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = new;
        new->prev = p;
        return (head);
    }
}
node *InsertionAtAnyPoint(node *head, int pos, int data)
{
    if (head == NULL)
    {
        head = CreateNode(data);
        return head;
    }
    else
    {
        int i = 1;
        node *p = head;
        node *new = CreateNode(data);
        while (i < pos - 1 && p->next != NULL)
        {
            p = p->next;
            i++;
        }
        if (p->next == NULL)
        {
            head = InsertionAtLast(head, data);
            printf("Indexing Overflow ,So Inserting at end position\n");
        }
        else
        {
            node *q = p->next;
            new->prev = q->prev;
            q->prev = new;
            new->next = q;
            p->next = new;
        }
        return (head);
    }
}
node *DeleteNodeFirst(node *head)
{
    if (head == NULL)
    {
        printf("Linked List is Empty \n");
        return (NULL);
    }
    else if (head->next == NULL)
    {
        int val = head->data;
        node *p = head;
        head = p->next;
        printf("Value of %d was Deleted\n", val);
        free(p);
        return (head);
    }
    else
    {
        node *p = head;
        int val = p->data;
        head = p->next;
        head->prev = NULL;
        printf("Value of %d was Deleted\n", val);
        free(p);
        return head;
    }
}
node *DeleteNodeLast(node *head)
{
    if (head == NULL)
    {
        printf("List is Empty \n");
        return (NULL);
    }
    else if (head->next == NULL)
    {
        int val = head->data;
        node *p = head;
        head = p->next;
        printf("Value of %d was Deleted\n", val);
        free(p);
        return (head);
    }
    else
    {
        node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        node *q = p->prev;
        q->next = NULL;
        int val = p->data;
        printf("Value of %d was Deleted\n", val);
        free(p);
        return (head);
    }
}
node *DeleteAnyNode(node *head, int pos)
{
    if (head == NULL)
    {
        printf("List is Empty \n");
        return (NULL);
    }
    else if (head->next == NULL)
    {
        int val = head->data;
        node *p = head;
        head = p->next;
        printf("Value of %d was Deleted\n", val);
        free(p);
        return (head);
    }
    else
    {
        int i = 1;
        node *p = head;
        while (p->next != NULL && i < pos - 1)
        {
            p = p->next;
            i++;
        }
        node *q = p->next;
        p->next = q->next;
        (q->next)->prev = p;
        int val = q->data;
        printf("Value of %d was Deleted\n", val);
        free(q);
        return (head);
    }
}
node *Reverse(node *head)
{
    node *temp = NULL;
    node *p = head;
    while (p != NULL)
    {
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;

        p = p->prev;
    }
    head = temp->prev;
    return (head);
}
int main(int argc, char const *argv[])
{
    node *head = NULL;
    for (int i = 0; i <= 10; i++)
    {
        head = InsertionAtLast(head, (10 + i));
    }
    Print(head);
    printf("\tAfter Insert at 6th Position \n");
    head = InsertionAtAnyPoint(head, 6, 2000);
    Print(head);
    head = Reverse(head);
    printf("\t After Reverse all Node \n");
    Print(head);
    for (int i = 0; i <= 5; i++)
    {
        head = DeleteNodeLast(head);
    }
    Print(head);
    printf("After Delete 2nd node\n");
    head = DeleteAnyNode(head, 2);
    Print(head);
    return 0;
}
