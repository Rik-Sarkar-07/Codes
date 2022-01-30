#include<stdio.h>
#include<stdlib.h>
struct Tree
{
    int data;
    struct Tree* left;
    struct Tree* right;
};
typedef struct Tree node;
node* CreateNode(int data){
    node* n = (node*)malloc(sizeof(node));
    if(n == NULL)
    {
        printf("Memory error\n");
        return NULL;
    }
    else
    {
        n->data = data;
        n->left = n->right = NULL;
        return n;
    }
}
int Hight(node* root)
{
    if(root == NULL)
    return 0;
    else
    {
        int lhight = Hight(root->left);
        int rhight = Hight(root->right);
        if(rhight > lhight)
        return (rhight+1);
        else
        return (lhight+1);
    }
}
void PrintCurrentLevel(node* root,int level)
{
    if(root == NULL)
    return;
    if(level == 1)
    printf("\t%d",root->data);
    else
    {
        PrintCurrentLevel(root->left,level-1);
        PrintCurrentLevel(root->right,level-1);
    }
}
void LevelOrderTravertion(node* root)
{
    int h = Hight(root);
    for(int i=1;i<=h;i++)
    PrintCurrentLevel(root,i);
}
int main(int argc, char const *argv[])
{
    node* h = CreateNode(20);
    node* f1 = CreateNode(30);
    node* f2 = CreateNode(10);
    node* f3 = CreateNode(5);
    node* f4 = CreateNode(40);
    node* f5 = CreateNode(7);
    node* f6 = CreateNode(401);


        //             h

        //       f1            f2


        //  f3         f4              f5

        //                  f6  

h->left = f1;
h->right = f2;
f1->left = f3;
f1->right = f4;
f4->right = f6;
f2->right = f5;

LevelOrderTravertion(h);
printf("\n");
             
    return 0;
}
