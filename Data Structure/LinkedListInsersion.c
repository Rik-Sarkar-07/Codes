#include<stdio.h>
#include<stdlib.h>
    // Linked list
struct Node{
   int data;
   struct Node* next;
};
    // Linked list Traversion
void Traversion(struct Node* head)
{
    struct Node* p = head;
    while (p != NULL) {
        printf("\t %d",p->data);
        p = p->next;
    }
    printf("\nTraversion is Completed\n");
}
    // Linked list Insertion at first
struct Node* InsertionAtFirst(struct Node* head,int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof (struct Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}
   // Linked list Insertion at last
struct Node* InsertionAtLast(struct Node* head,int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof (struct Node));
    ptr->data = data;
    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
   // Linked list Insertion at any index
struct Node* InsertionAtIndex( struct Node* head,int data,int index)
{
     struct Node* ptr = (struct Node*)malloc(sizeof (struct Node));
     struct Node* p = head;
     int i = 0;
     while (i<index-1) {
         p = p->next;
         i++;
     }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return (head);
}
struct Node* InsertionAtanyPiont(struct Node* head,int data,struct Node* prev)
{
   struct Node* ptr = (struct Node*)malloc(sizeof (struct Node));
   ptr->data = data;
   ptr->next = prev->next;
   prev->next = ptr;
   return head;
}
int main()
{
    struct Node* head = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f1 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f2 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f3 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f4 = (struct Node*)malloc(sizeof (struct Node));

    head->data = 10;        head->next = f1;
    f1->data = 12;          f1->next = f2;
    f2->data = 14;          f2->next = f3;
    f3->data = 20;          f3->next = f4;
    f4->data = 25;          f4->next = NULL;

    Traversion(head);
    head = InsertionAtFirst(head,8);
    Traversion(head);
    head = InsertionAtLast(head,24);
    Traversion(head);
    head = InsertionAtIndex(head,9,3);
    Traversion(head);
    head = InsertionAtanyPiont(head,50,f4);
    Traversion(head);

    return 0;
}
