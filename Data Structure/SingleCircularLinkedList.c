#include <stdio.h>
#include <stdlib.h>
struct SingleCircularLinkedList
{
    int data;
    struct SingleCircularLinkedList *next;
};
typedef struct SingleCircularLinkedList node;
node *CreateNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Memory Error \n");
        return (NULL);
    }
    else
    {
        new->data = data;
        return (new);
    }
}
void InsertAtLast(node **head, node **last, int data)
{
    node *new = CreateNode(data);
    if (*head == NULL)
    {
        *head = *last = new;
    }
    else
    {
        (*last)->next = new;
        (*last) = new;
    }
    (*last)->next = *head;
}
void InsertAtFirst(node **head, node **last, int data)
{
    node *new = CreateNode(data);
    if (*head == NULL)
    {
        *head = *last = new;
    }
    else
    {
        new->next = *head;
        *head = new;
    }
    (*last)->next = *head;
}
void InsertAtAnyPosition(node **head, node **last, int pos, int data)
{
    int i = 1;
    node *p = *head;
    node *new = CreateNode(data);
    while (p->next != *head && i < pos - 1)
    {
        p = p->next;
        i++;
    }
    if (p->next == *head)
    {
        printf("Position is Invalid \n");
    }
    else
    {
        new->next = p->next;
        p->next = new;
    }
}
void DeleteFirstNode(node **head, node **tail)
{
    if (*head == NULL)
    {
        printf("Linked list is Empty \n");
    }
    else
    {
        node *p = *head;
        int val = p->data;
        *head = (*head)->next;
        (*tail)->next = *head;
        free(p);
        printf("The Head value %d was deleted \n", val);
    }
}
void DeleteLastNode(node **head, node **tail)
{
    if (*head == NULL)
    {
        printf("Linked list is Empty \n");
    }
    else
    {
        node *p = *head;
        while (p->next != *tail)
        {
            p = p->next;
        }
        node *q = *tail;
        int val = q->data;
        *tail = p;
        (*tail)->next = *head;
        free(q);
        printf("The Tail value %d was deleted \n", val);
    }
}
void DeleteAnyNode(node **head, node **tail, int pos)
{
    if (*head == NULL && pos < 0)
    {
        printf("Error \n");
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
            printf("Invalid Index \n");
        }
        else
        {
            node *q = p->next;
            p->next = q->next;
            int val = q->data;
            free(q);
            printf("The %d position value %d was deleted \n", pos, val);
        }
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
int main(int argc, char const *argv[])
{
    node *head = NULL;
    node *tail = NULL;
    for (int i = 0; i < 10; i++)
    {
        InsertAtLast(&head, &tail, (10 + i));
    }
    printf("\t After Insert at Last \n");
    Print(head);
    for (int i = 0; i < 10; i++)
    {
        InsertAtFirst(&head, &tail, (20 + i));
    }
    printf("\t After Insert at First \n");
    Print(head);
    InsertAtAnyPosition(&head, &tail, 2, 1000);
    Print(head);
    DeleteFirstNode(&head, &tail);
    Print(head);
    DeleteLastNode(&head, &tail);
    Print(head);
    DeleteAnyNode(&head, &tail, 10);
    Print(head);
    return 0;
}
