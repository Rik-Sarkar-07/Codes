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

    return 0;
}
