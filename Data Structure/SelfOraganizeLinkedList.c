#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;
struct SpacialNode
{
    int data;
    int count;
    struct SpacialNode *next;
};
typedef struct SpacialNode snode;
node *CreatNode(int data)
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
        new->next = NULL;
        return (new);
    }
}
void Print(node *head)
{
    if (head == NULL)
    {
        printf("Linked List is Empty \n");
        return;
    }
    else
    {
        node *p = head;
        while (p != NULL)
        {
            printf("%d\t", p->data);
            p = p->next;
        }
        printf("\n\n");
    }
}
void InsertAtEnd(node **head, int data)
{
    node *new = CreatNode(data);
    node *p = *head;
    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = new;
    }
}
void SelfOrganizeUsingSwap(node **head, int data)
{
    if (*head == NULL && (*head)->next == NULL)
    {
        return;
    }
    if((*head)->data == data)
    {
        return;
    }
    node *p = *head;
    while (p != NULL && data != (p->next)->data)
    {
        p = p->next;
    }
    node *s = p->next;
    node *headnxt = (*head)->next;
    p->next = *head;
    (*head)->next = s->next;
    s->next = headnxt;
    *head = s;
}
void SelfOrganizeUsingTranspose(node **head, int data)
{
    if (*head == NULL && (*head)->next == NULL)
    {
        printf("Empty \n");
        return;
    }
    if((*head)->data == data)
    {
        return;
    }
    if((*head)->next->data == data)
    {
        node* p = (*head)->next;
        (*head)->next = p->next;
        p->next = *head;
        *head = p;
        return;
    }
    node *p = *head;
    while (p != NULL && data != ((p->next)->next)->data)
    {
        p = p->next;
    }
    node *pre = p->next;
    node *curr = pre->next;
    p->next = curr;
    pre->next = curr->next;
    curr->next = pre;
}
void SelfOrganizationUsingCount(snode **head, int data)
{
    snode *p = *head;
    if (p == NULL && p->next == NULL)
    {
        printf("Error \n");
    }
    else
    {
        if((*head)->data == data)
        {
            (*head)->count++;
            return;
        }
        while (p != NULL && (p->next)->data != data)
        {
            p = p->next;
        }
        snode *q = p->next;
        q->count++;
        if ((*head)->count <= q->count)
        {
            p->next = q->next;
            q->next = *head;
            *head = q;
        }
    }
}
void InsertAtEndForSpacialNode(snode **head, int data)
{
    snode *new = (snode *)malloc(sizeof(snode));
    new->data = data;
    new->count = 0;
    new->next = NULL;
    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        snode *p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = new;
    }
}
void PrintSpacialNode(snode* head)
{
    if(head==NULL)
    {
        printf("Empty List\n");
        return;
    }
    else
    {
        snode* p = head;
        printf("\tData \t Count\n\n");
        while(p != NULL)
        {
            printf("\t %d \t %d\n",p->data,p->count);
            p = p->next;
        }
        printf("\n");
    }
}
int main(int argc, char const *argv[])
{
    node *head = NULL;
    for (int i = 0; i <= 10; i++)
    {
        InsertAtEnd(&head, (10 + i));
    }
    Print(head);
    SelfOrganizeUsingSwap(&head, 17);
    Print(head);
    SelfOrganizeUsingSwap(&head, 18);
    Print(head);
    SelfOrganizeUsingTranspose(&head, 14);
    Print(head);
    SelfOrganizeUsingTranspose(&head, 14);
    Print(head);
    SelfOrganizeUsingTranspose(&head, 14);
    Print(head);
    SelfOrganizeUsingTranspose(&head, 14);
    Print(head);
    printf("\n\n\t\t For Spacial Linked List \n\n");
    snode *HEAD = NULL;
    for (int i = 0; i <= 10; i++)
    {
        InsertAtEndForSpacialNode(&HEAD,(10+i));
    }
    PrintSpacialNode(HEAD);
    SelfOrganizationUsingCount(&HEAD, 15);
    PrintSpacialNode(HEAD);
    SelfOrganizationUsingCount(&HEAD, 15);
    PrintSpacialNode(HEAD);
    SelfOrganizationUsingCount(&HEAD, 13);
    PrintSpacialNode(HEAD);
    SelfOrganizationUsingCount(&HEAD, 13);
    PrintSpacialNode(HEAD);
    return 0;
}
