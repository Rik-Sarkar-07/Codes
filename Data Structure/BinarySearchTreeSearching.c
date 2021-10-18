#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* CreateNode(int data)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    if(n == NULL)
    {
        printf("Node is Not created\n");
        exit(1);
    }
    else
    {
        n->data = data;
        n->left = NULL;
        n->right = NULL;
        return (n);
    }
}
void InOrderTravertion(struct node* root)
{
    if(root != NULL)
    {
        InOrderTravertion(root->left);
        printf("%d\t",root->data);
        InOrderTravertion(root->right);
    }
}
int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!= NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
struct node * BSTsearch(struct node* root, int val){
    if(root==NULL){
        return NULL;
    }
    if(val ==root->data){
        return root;
    }
    else if(val<root->data){
        return BSTsearch(root->left, val);
    }
    else{
        return BSTsearch(root->right, val);
    }
}
struct node* BSTsearchIteration(struct node* root,int data)
{
    while (root != NULL)
    {
       if(root->data == data)
       {
           return root;
       } 
       else if(root->data > data)
       {
           root = root->left;
       }
       else
       {
           root = root->right;
       }
    }
    return (NULL);
}
int main(int argc, char const *argv[])
{
    struct node* root = CreateNode(10);
    struct node* t1 = CreateNode(4);
    struct node* t2 = CreateNode(11);
    struct node* t3 = CreateNode(2);
    struct node* t4 = CreateNode(7);
    struct node* t5 = CreateNode(5);
    struct node* t6 = CreateNode(8);
    struct node* t7 = CreateNode(19);
    struct node* t8 = CreateNode(14);

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

    InOrderTravertion(root);
    if(isBST(root))
    {
        printf("\n This is a BST\n");
    }
    else
    {
        printf("\n It is not BST \n");
    }
    struct node* p = BSTsearchIteration(root,14);
    if(p->data == 14)
    {
        printf("Searching is done !! \n");
    }
    else
    {
        printf("Searching is failed \n");
    }
    return 0;
}
