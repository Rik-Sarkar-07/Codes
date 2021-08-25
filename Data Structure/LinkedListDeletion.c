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
    // Linked list - delete first node
struct Node* DeleteFirstNode(struct Node* head)
{
    struct Node* ptr = head;
    head = ptr->next;
    free(ptr);
    return (head);
}
  // Linked list - delete last node
struct Node* DeleteLastNode(struct Node* head)
{
    struct Node* ptr = head;
     struct Node* p = head->next;
    while (p->next != NULL) {
       ptr = ptr->next;
       p = p->next;
    }
    ptr->next = NULL;
    free(p);
    return (head);
}
    // Linked list - delete any index node
struct Node* DeleteAnyIndexNode(struct Node* head,int index)
{
    struct Node* ptr = head;
    struct Node* ptrNext = head->next;
    int i = 0;
    while (i<(index-1)) {
        i++;
        ptr = ptr->next;
        ptrNext = ptrNext->next;
    }
   ptr->next = ptrNext->next;
    free(ptrNext);
    return (head);
}
    // Linked list - delete value'th node
struct Node* DeleteValuethNode(struct Node * head, int value){
    struct Node *ptr = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }

    if(q->data == value){
        ptr->next = q->next;
        free(q);
    }
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
   head = DeleteValuethNode(head,14);
    Traversion(head);
    return 0;
}
