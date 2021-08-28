#include<stdio.h>
#include<stdlib.h>
    // Stack Node
struct stackNode
{
    int data;
    struct stackNode* next;
};
int isEmpty(struct stackNode* top)
{
    if(top == NULL)
    {
        return 1;
    }
    else {
        return 0;
    }
}
int isFull(struct stackNode* top)
{
    struct stackNode* newNode = (struct stackNode*)malloc(sizeof (struct stackNode));
    if(newNode == NULL) // if memory full then we can not created any node
    {
        return 1;
    }
    else {
        return 0;
    }
}
    // Push Oparation on Stack
struct stackNode* Push(struct stackNode* top,int data)
{
    if(isFull(top))
    {
        printf("Stack is Full -- Oparation Failed !! \n");
        return (top);
    }
    else {
         struct stackNode* n = (struct stackNode*)malloc(sizeof (struct stackNode));
         n->data = data;    n->next = top;
         top = n;
         return (top);
    }
}
    // Pop Oparation on Stack
int Pop(struct stackNode** top)
{
    if(isEmpty(*top))
    {
        printf("Stack is Empty -- Oparation Failed !! \n");
        return -1;
    }
    else
    {
        struct stackNode* n = *top;
        int value = n->data;
        *top=(*top)->next;
        free(n);
        return value;
    }
}
    // Peek Oparation on Stack
int Peek(struct stackNode* top,int index)
{
    struct stackNode* p = top;
    for(int i=0;(i<index-1 && p != NULL);i++)
    {
        p = p->next;
    }
    if(p != NULL)
    {
        return (p->data);
    }
    else
    {
        return -1;
    }
}
    // Print all Elements of Stack
void Traversion(struct stackNode* top)
{
    struct stackNode* p = top;
    while (p != NULL) {
       printf("\t%d",p->data);
       p = p->next;
    }
    printf("\t Traversion is Done \n\n");
}
    // TopStack Element
int TopStack(struct stackNode* top)
{
    if(isEmpty(top))
    {
        printf("Stack is Empty -- Oparation Failed !! \n");
        return -1;
    }
    else
    {
        return (top->data);
    }
}
// BottumStack Element
int BottumStack(struct stackNode* top)
{
    if(isEmpty(top))
    {
        printf("Stack is Empty -- Oparation Failed !! \n");
        return -1;
    }
    else
    {
       struct stackNode* p = top;
       while (p->next != NULL) {
           p = p->next;
       }
       return (p->data);
    }
}
int main()
{
    struct stackNode* top = NULL;
    top = Push(top,5);
    top = Push(top,10);
    top = Push(top,20);
    top = Push(top,30);
    top = Push(top,40);
    top = Push(top,50);
    top = Push(top,60);
    top = Push(top,70);
    Traversion(top);
    printf("Top Element of the Stack => \t%d\n",TopStack(top));
    printf("Bottum Element of the Stack => \t%d\n",BottumStack(top));
    printf("First Pop Element of the Stack => \t%d\n",Pop(&top));
    printf("Second Pop Element of the Stack => \t%d\n",Pop(&top));
    Traversion(top);
    return 0;
}
