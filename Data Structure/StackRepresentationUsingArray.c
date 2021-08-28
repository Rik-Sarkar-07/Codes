#include<stdio.h>
#include<stdlib.h>
        // STACK [ LIFO ]
struct stack
{
    int size;
    int top;
    int* arr;
};
int isEmpty(struct stack* ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack* ptr)
{
    if(ptr->top == (ptr->size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
    // Push Operation on Stack
void Push(struct stack* ptr,int data)
{
    if(isFull(ptr))
    {
        printf("Stack is Full -- Operation Failed !! \n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}
    // Pop Operation on Stack
int Pop(struct stack* ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack is Empty -- Oparation Failed");
        return 0;
    }
    else
    {
        int val;
        val = ptr->arr[ptr->top];
        ptr->top--;
        return (val);
    }
}
    // Peek Oparation on Stack
int Peek(struct stack* ptr,int i)
{
    int arrIndex = ptr->top-1-i;
    if(arrIndex<0)
    {
        printf("Some things Wrong -- Oparation Failed !! \n");
        return -1;
    }
    else
    {
        return (ptr->arr[arrIndex]);
    }
}
    // StackTop Oparation on Stack
int StackTop(struct stack* ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack is Empty -- Oparation Failed !!\n ");
        return -1;
    }
    else
    {
        return (ptr->arr[ptr->top]);
    }
}
    // StackBottom Oparation on Stack
int StackBottom(struct stack* ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack is Empty -- Oparation Failed !!\n ");
        return -1;
    }
    else
    {
        return (ptr->arr[0]);
    }
}
int main()
{
    struct stack* s;
    s->size = 50;       // Random size
    s->top = -1;
    s->arr = (int*)malloc(sizeof (int)*s->size);    // Array size 50

    Push(s,10);
    Push(s,40);
    Push(s,60);
    Push(s,70);
    Push(s,20);
    Push(s,50);
    Push(s,80);
    Push(s,90);

    printf("First POP => %d \t Second POP => %d \n",Pop(s),Pop(s));
    printf("Stack TOP => %d \t Stack Bottom => %d \n",StackTop(s),StackBottom(s));

//    if(isEmpty(s))
//    {
//        printf("The Stack is Empty \n");
//    }
//    else
//    {
//        printf("Stact is not Empty \n");
//    }
//    if(isFull(s))
//    {
//        printf("The Stack is Full \n");
//    }
//    else
//    {
//        printf("Stack is not Full \n");
//    }



    return 0;
}
