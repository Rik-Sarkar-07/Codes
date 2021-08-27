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
//  Circular Linked list Delete at first node
struct Node* DeleteFirstNode(struct Node* head)
{

  struct Node* p = head;
  while (p->next != head) {
      p = p->next;
  }
   p->next = head->next;
   free(head);
   head = p->next;
  return (head);
}
    // Circular Linked list Delete last node
struct Node* DeleteLastNode(struct Node* head)
{

  struct Node* p = head->next;
  struct Node* q = head;
  while (p->next != head) {
      p = p->next;
      q = q->next;
  }
  q->next = p->next;
  free(p);
  return (head);
}
    // Circular Linked list Delete any node point
struct Node* DeleteAnyNode(struct Node* head,int index)
{
     struct Node* p = head;
     struct Node* q = head->next;
     int i = 0;
     while ((index-1)>i) {
         p = p->next;
         q = q->next;
         i++;
     }
     p->next = q->next;
     free(q);
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
//    head = DeleteFirstNode(head);
//    Traversion(head);
//    head = DeleteLastNode(head);
      head = DeleteAnyNode(head,3);
    Traversion(head);
    return 0;
}
