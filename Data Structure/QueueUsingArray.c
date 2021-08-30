#include<stdio.h>
#include<stdlib.h>
    // Queue Representation using array
struct Queue
{
    int size;
    int f,r;
    int* arr;
};
int isEmpty(struct Queue* str)
{
    if(str->f == str->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Queue* str)
{
    if(str->r == (str->size-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
    // DeQueue Operation on Queue
int Dequeue(struct Queue* str)
{
    if(isEmpty(str))
    {
        printf("Queue is Empty -- Operation Failed \n\n");
        exit(1);
    }
    else
    {
        str->f++;
        int a = str->arr[str->f];
        return (a);
    }
}
   // EnQueue Operation on Queue
void EnQueue(struct Queue* str,int data)
{
    if(isFull(str))
    {
        printf("Queue is Full -- Operatin is Failed !! \n");
        exit(1);
    }
    else
    {
        str->r++;
        str->arr[str->r] = data;
    }
}
int main()
{
    struct Queue que;
    que.size = 20;
    que.f = que.r = -1;
    que.arr = (int*)malloc(sizeof (int)*que.size);

    for(int i=0;i<=10;i++)
    {
        EnQueue(&que,10+i);
    }
    for(int i=0;i<=10;i++)
    {
       printf("De-Queue no %d is => \t %d\n",(i+1),Dequeue(&que));
    }
    printf("\n\n");
    return 0;
}

