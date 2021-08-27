#include<stdio.h>
#include<stdlib.h>
    // Linked List
struct Node
{
    int data;
    struct Node* next;
};
//  Circular Linked list Traversion
void Traversion(struct Node* head)
{
    struct Node* p = head;
    do{
        printf("\t%d",p->data);
        p = p->next;
    }while (p != head);

    printf("\n Traversion is Done \n");
}
//  Circular Linked list Insertion at first
struct Node* InsertionAtFirst(struct Node* head,int data)
{
  struct Node* ptr = (struct Node*)malloc(sizeof (struct Node));
  struct Node* p = head;
  while (p->next != head) {
      p = p->next;
  }
    p->next = ptr;
    ptr->data = data;
    ptr->next = head;
     head = ptr;
  return (head);
}
    // Circular Linked list Insertion at last
struct Node* InsertionAtLast(struct Node* head,int data)
{
  struct Node* ptr = (struct Node*)malloc(sizeof (struct Node));
  struct Node* p = head;
  while (p->next != head) {
      p = p->next;
  }
    p->next = ptr;
    ptr->data = data;
    ptr->next = head;
  return (head);
}
    // Circular Linked list Insertion at any point
struct Node* InsertionAtAnyPoint(struct Node* head,int data,int index)
{
     struct Node* ptr = (struct Node*)malloc(sizeof (struct Node));
     ptr->data = data;
     struct Node* p = head;
     int i = 0;
     while ((index-1)>i) {
         p = p->next;
         i++;
     }
     ptr->next = p->next;
     p->next = ptr;
     return (head);
}
int main()
{
    struct Node* head = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f1 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f2 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f3 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f4 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f5 = (struct Node*)malloc(sizeof (struct Node));
    head->data = 10;    head->next = f1;
    f1->data = 15;      f1->next = f2;
    f2->data = 16;      f2->next = f3;
    f3->data = 20;      f3->next = f4;
    f4->data = 25;      f4->next = f5;
    f5->data = 30;      f5->next = head;

    Traversion(head);
    head = InsertionAtFirst(head,5);
    Traversion(head);
    head = InsertionAtLast(head,35);
    Traversion(head);
    head = InsertionAtAnyPoint(head,12,3);
    Traversion(head);
    return 0;
}
