#include<stdio.h>
#include<stdlib.h>
    //Doubly Linked List
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
    // Doubly Linked List Traversion
void LinkedTravertion(struct Node* head)
{
    struct Node* p = head;
    while (p != NULL) {
        printf("\t%d",p->data);
        p = p->next;
    }
    printf("\n Traversion is done \n");
}
    // Insertion at First Node
struct Node* InsertionAtFirst(struct Node* head,int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof (struct Node));
    ptr->next = head;
    ptr->prev = NULL;
    head->prev = ptr;
    ptr->data = data;
    head = ptr;
    return (head);
}
    // Insertion at last Node
struct Node* InsertionAtLast(struct Node* head,int data)
{
    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
   struct Node* ptr = (struct Node*)malloc(sizeof (struct Node));
   ptr->data = data;
   p->next = ptr;
   ptr->prev = p;
   ptr->next = NULL;
   return (head);
}
  // Insertion at any Index
struct Node* InsertionAtAnyIndex(struct Node* head,int data,int index)
{
    int i = 0;
    struct Node* p = head;
    struct Node* ptr = (struct Node*)malloc(sizeof (struct Node));
    ptr->data = data;
    while ((index-1)>i) {
        i++;
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->prev = p;
    return (head);
}
int main()
{
    struct Node* head = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f1 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f2 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f3 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f4 = (struct Node*)malloc(sizeof (struct Node));

    head->prev = NULL;  head->data = 10;    head->next = f1;
    f1->prev = head;    f1->data = 15;      f1->next = f2;
    f2->prev = f1;      f2->data = 20;      f2->next = f3;
    f3->prev = f2;      f3->data = 25;      f3->next = f4;
    f4->prev = f3;      f4->data = 30;      f4->next = NULL;

    LinkedTravertion(head);
    head = InsertionAtFirst(head,5);
    LinkedTravertion(head);
    head = InsertionAtLast(head,35);
    LinkedTravertion(head);
    head = InsertionAtAnyIndex(head,40,7);
    LinkedTravertion(head);
    return 0;
}
