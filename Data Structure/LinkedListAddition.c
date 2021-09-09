#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void Travertion(struct Node* head)
{
    struct Node* p = head;
    while (p != NULL) {
        printf("%d\t",p->data);
        p = p->next;
    }
    printf("\n \t Print Operation is Done !!!\n");
}
struct Node* Add(struct Node* head1,struct Node* head2)
{
    if(head1 == NULL || head2 == NULL)
    {
        printf("Failed !!! \n");
        exit(1);
    }
    else
    {
        struct Node* p = head1;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = head2;
        return (head1);
    }
    printf("Addition Operation is Done \n");
}

int main()
{
    struct Node* head = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f1 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f2 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f3 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f4 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f5 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f6 = (struct Node*)malloc(sizeof (struct Node));
    head->data = 10;        head->next = f1;
    f1->data = 20;          f1->next = f2;
    f2->data = 30;          f2->next = f3;
    f3->data = 40;          f3->next = f4;
    f4->data = 50;          f4->next = f5;
    f5->data = 60;          f5->next = f6;
    f6->data = 70;          f6->next = NULL;

    Travertion(head);

    struct Node* head1 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f11 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f21 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f31 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f41 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f51 = (struct Node*)malloc(sizeof (struct Node));
    struct Node* f61 = (struct Node*)malloc(sizeof (struct Node));
    head1->data = 110;        head1->next = f11;
    f11->data = 120;          f11->next = f21;
    f21->data = 130;          f21->next = f31;
    f31->data = 140;          f31->next = f41;
    f41->data = 150;          f41->next = f51;
    f51->data = 160;          f51->next = f61;
    f61->data = 170;          f61->next = NULL;

   Travertion(head1);

   head = Add(head,head1);
   Travertion(head);
    return 0;
}
