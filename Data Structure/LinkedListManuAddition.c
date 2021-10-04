#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node node;
node* head = NULL;
void Print()
{
    if(head == NULL)
    {
        printf("Linked list is Empty\n");
    }
    else
    {
        node* p = head;
        while (p != NULL)
        {
            printf("%d\t",p->data);
            p = p->next;
        }
        printf("\n\n");
    }
}
void Insertion()
{
    int val,ch;
    while (1)
    {
        printf("Enter the value of  = ");
        scanf("%d",&val);
        printf("\t -- Enter Your Choice -- \n");
        printf("1-> for insert at first\n2-> for insert at last\n3-> insert at index point\n4-> Exit()\n \t Choice Enter = ");
        scanf("%d",&ch);
        node* n = (node*)malloc(sizeof(node));
        n->data = val;
        n->next = NULL;
        if(ch == 1)
        {
            n->next = head;
            head = n;
            printf("after insertion at first -- \n");
            Print();
        }
        else if(ch == 2)
        {
            node* p = head;
            if(p == NULL)
            {
                n->next = head;
                head = n;
            }
            else
            {
                while (p->next != NULL)
                {
                    p = p->next;
                }
                p->next = n;
            }
            printf("after insertion at last -- \n");
            Print();
        }
        else if(ch == 3)
        {
            int index,i = 1,j=1;
            node* p = head,*q = head;
            printf("Enter the index = ");
            scanf("%d",&index);   
            while (p != NULL)
            {
                p = p->next;
                i++;
            }
            if(index < 0 && i < index)
            {
                printf("Index is not valid\n");
            }
            else if(index == 1)
            {
                n->next = head;
                head = n;
            }
            else
            {
                while (j<index-1)
                {
                  q = q->next;
                  j++;  
                }
                n->next = q->next;
                q->next = n;
            }
            printf("after insertion at %d index -- \n",index);
            Print();
        }
        else if(ch == 4)
        {
            printf("Linked List is --\n");
            Print();
            printf("\t Exit() !! \n");
            exit(0);
        }
        else
        {
            printf("Wrong Choice !!\n");
        }
    }
}
int main(int argc, char const *argv[])
{
    Insertion();
    return 0;
}
