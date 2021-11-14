#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
typedef struct node node;
void Print(node* head)
{
    if(head == NULL)
    {
        printf("Empty\n");
        return;
    }
    else
    {
        node* p =head;
        while (p != NULL)
        {
            printf("%d\t",p->data);
            p = p->next;
        }

    }
}
node* CreateNode(int data)
{
    node* n = (node*)malloc(sizeof(node));
    n->data;
    n->next = NULL;
}
int main(int argc, char const *argv[])
{
    node* head = (node*)malloc(sizeof(node));
    head->data = 100;
    node* f1 = (node*)malloc(sizeof(node));
    f1->data = 10;
    node* f2 = (node*)malloc(sizeof(node));
    f2->data = 50;
    node* f3 = (node*)malloc(sizeof(node));
    f3->data = 90;

    head->next = f1;
    f1->next = f2;
    f2->next = f3;
    f3->next = NULL;
   node* i = head;
   node* j = head;

   Print(head);

   printf("\nAfter Sort\n");

   for(i=head;i->next != NULL;i = i->next)
   {
       for(j=head;j->next != NULL;j = j->next)
       {
           if(j->data > (j->next)->data )
           {
               int temp = j->data;
               j->data = j->next->data;
               j->next->data = temp;
           }
       }
   }

    Print(head);
    return 0;
}
