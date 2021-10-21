#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
typedef struct Node node;
void Print(node* head)
{
    if(head == NULL)
    {
        printf("Linked List is Empty \n");
    }
    else
    {
        node* p = head;
        while (p != NULL)
        {
            printf("%d\t",p->data);
            p = p->next;
        }
        printf("\n");
    }
}
node* CreateNode(int data)
{
    node* new = (node*)malloc(sizeof(node));
    if(new == NULL)
    {
        printf("Mwmory Error\n");
        return NULL;
    }
    else
    {
        new->data = data;
        new->next = NULL;
    }
}
node* ReverseLinkedList(node* head)
{
    node* prev = NULL;
    node* current = head;
    node* nextptr;
    while (current != NULL)
    {
        nextptr = current->next;
        current->next = prev;
        prev = current;
        current = nextptr;
    }
    head = prev;
    return (head);
}
node* InsertNode(node* head,int data)
{
    node* new = CreateNode(data);
    if(head == NULL)
    {
        head = new;
    }
    else
    {
        new->next = head;
        head = new;
    }
    return(head);
}
int main(int argc, char const *argv[])
{
    node* head = NULL;
    for(int i=0;i<=10;i++)
    {
       head =  InsertNode(head,(10+i));
    }
    printf("\tBefore the Reverse Linked List \n");
    Print(head);
    printf("\tAfter the Reverse Linked List \n");
    head = ReverseLinkedList(head);
    Print(head);
    return 0;
}
