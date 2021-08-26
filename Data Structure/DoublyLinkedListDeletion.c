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
    // Delete at First Node
struct Node* DeleteAtFirstNode(struct Node* head)
{
    struct Node* p = head;
    head = head->next;
    free(p);
    head->prev = NULL;
    return (head);
}
    // Delete at last Node
struct Node* DeleteAtLastNode(struct Node* head)
{
    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
   struct Node* q = p->prev;
   q->next = NULL;
   free(p);
   return (head);
}
  // Delete at any Index Node
struct Node* DeleteAtAnyIndexNode(struct Node* head,int index)
{
    int i = 0;
    struct Node* p = head;
    while ((index)>i) {
        i++;
        p = p->next;
    }
    struct Node* q = p->prev;
    q->next = p->next;
    free(p);
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
  // head = DeleteAtFirstNode(head);
  // LinkedTravertion(head);
  // head = DeleteAtLastNode(head);
  // LinkedTravertion(head);
    head = DeleteAtAnyIndexNode(head,4);
    LinkedTravertion(head);
    return 0;
}
