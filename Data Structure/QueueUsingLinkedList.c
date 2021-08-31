#include<stdio.h>
#include<stdlib.h>
struct NodeQueue* r = NULL;
struct NodeQueue* f = NULL;
    // Queue Representation on LinkedList
struct NodeQueue
{
    int data;
    struct NodeQueue* next;
};
    // Traversion on LinkedList
void TraversionQueue(struct NodeQueue* str)
{
    struct NodeQueue* p= str;
    while (p != NULL) {
        printf("\t%d",p->data);
    }
    printf("\n\n");
}
    // EnQueue Operation
void Enqueue(int value)
{
    struct NodeQueue* p = (struct NodeQueue*)malloc(sizeof (struct NodeQueue));
    if(p==NULL)
    {
        printf("Queue is Full -- Operation is Failed \n\n");
        exit(1);
    }
    else {
        p->data = value;
        p->next = NULL;
        if(f==NULL)
        {
            r = f = p;
        }
        else {
            r->next = p;
            r = p;
        }
    }
}
    // DeQueue Operation
int DeQueue()
{
    int val = -1;
    struct NodeQueue* p = f;
    if(f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        f = f->next;
        val = p->data;
        free(p);
    }
    return val;
}
int main()
{

    for(int i=0;i<=10;i++)
    {
        Enqueue(10+i);
    }
    for(int i=0;i<=10;i++)
    {
        printf("%d \t",DeQueue());
    }
    printf("\n\n");
    return 0;
}
