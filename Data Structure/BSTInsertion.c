#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node node;
node *CreateNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("\tMemory Error !! \n");
        return NULL;
    }
    else
    {
        new->data = data;
        new->left = NULL;
        new->right = NULL;
        return (new);
    }
}
void InOrderTraversion(node *root)
{
    if (root != NULL)
    {
        InOrderTraversion(root->left);
        printf("\t%d", root->data);
        InOrderTraversion(root->right);
    }
}
void Insert(node* root,int data)
{
    node* prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if(data == root->data)
        {
            printf("\t %d Data is Already Present \n",data);
           return;
        }
        else if(data < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    node* new = CreateNode(data);
    if(prev->data > data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }   
}
int main(int argc, char const *argv[])
{
    node *root = CreateNode(10);
    node *t1 = CreateNode(4);
    node *t2 = CreateNode(11);
    node *t3 = CreateNode(2);
    node *t4 = CreateNode(7);
    node *t5 = CreateNode(5);
    node *t6 = CreateNode(8);
    node *t7 = CreateNode(19);
    node *t8 = CreateNode(14);

    /*

                                10
                            /           \
                    4                          11
                /          \                           \
            2               7                              19
                        /       \                        /
                    5               8                 14

    */

    root->left = t1;
    root->right = t2;
    t1->left = t3;
    t1->right = t4;
    t4->left = t5;
    t4->right = t6;
    t2->right = t7;
    t7->left = t8;

    InOrderTraversion(root);
    printf("\n");
    Insert(root,1);
    Insert(root,15);
    printf("\n --- After Insert 1 & 15 --- \n");
    InOrderTraversion(root);
    printf("\n");
    return 0;
}
