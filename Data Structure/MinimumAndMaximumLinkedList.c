#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    int data;
    char* name;
    struct Node* next;
};
typedef struct Node node;
node* CreateNode(int data,char* name)
{
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->name = name;
    new->next = NULL;
    return (new);
}
void Print(node* head)
{
    if(head == NULL)
    {
        printf("Empty \n");
        return;
    }
    else
    {
        node* p = head;
        while (p != NULL)
        {
           printf("Name = %s\t Data = %d\n",p->name,p->data);
            p = p->next;
        }
        printf("\n\n");
    }
}
void MaxAndMin(node* head)
{
    node* p = head;
    node* max = head;
    node* min = head;
    for(p=head;p->next != NULL;p=p->next)
    {
        if(max->data < p->data)
        {
            max = p;
        }
    }
    printf("The Maximun Number is = %d\t And The Name of Node is = %s\n ",max->data,max->name);
    for(p=head;p->next != NULL;p=p->next)
    {
        if(min->data > p->data)
        {
            min = p;
        }
    }
    printf("The Minimun Number is = %d\t And The Name of Node is = %s\n ",min->data,min->name);
}
int main(int argc, char const *argv[])
{
    node* head = CreateNode(10,"1st Node");
    node* f1 = CreateNode(2,"2nd Node");
    node* f2 = CreateNode(20,"3rd Node");
    node* f3 = CreateNode(15,"4th Node");
    node* f4 = CreateNode(17,"5th Node");
    head->next = f1;
    f1->next = f2;
    f2->next = f3;
    f3->next = f4;
    f4->next = NULL;
    Print(head);
    MaxAndMin(head);
    return 0;
}
