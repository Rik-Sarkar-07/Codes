#include <stdc.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;
node *CreateNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Memory Error\n");
        exit(1);
    }
    new->data = data;
    new->left = new->right = NULL;
    return (new);
}
node *Insert(node *root, int data)
{
    if (root == NULL)
    {
        root = CreateNode(data);
    }
    else if (root->data > data)
    {
        root->left = Insert(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = Insert(root->right, data);
    }
    else if (root->data == data)
    {
        printf("Same data can't be added in BST \n");
        return NULL;
    }
    return (root);
}
void Insert_element(node **root, int data)
{
    if (*root == NULL)
        *root = CreateNode(data);
    node *curr = *root;
    node *father = *root;
    node *new = CreateNode(data);
    while (curr != NULL)
    {
        father = curr;
        if(data == curr->data)
        return;
        if (data < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    if (father->data > data)
    {
        father->left = new;
    }
    else
    {
        father->right = new;
    }
}
void InOrder(node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("\t%d", root->data);
        InOrder(root->right);
    }
}
node* Search(node* root,int data)
{
    node* curr = root;
    int flag = 1;
    
    while (curr != NULL)
    {
        printf("Path [%d] -> \t",curr->data);
        if(curr->data == data)
        {
            flag = 0;
            printf("Path (final Node) [%d]\t",curr->data);
            return (curr);
        }
        else if(curr->data > data)
        {
            curr = curr->left;
           // printf("Path (left) [%d] -> \t",curr->data);
            continue;
        }
        else
        {
            curr = curr->right;
           // printf("Path (right) [%d] -> \t",curr->data);
            continue;
        }
    }
    if(flag)
    {
        printf("Element is not Found \n");
        return (NULL);
    }
}
int main(int argc, char const *argv[])
{
    node *root = NULL;

    // Inserting sequence 10 , 20 ,40 , 25 , 12 , 24 , 42 , 18
    Insert_element(&root, 10);
    Insert_element(&root, 20);
    Insert_element(&root, 40);
    Insert_element(&root, 25);
    Insert_element(&root, 12);
    Insert_element(&root, 24);
    Insert_element(&root, 42);
    Insert_element(&root, 18);
    InOrder(root);
    printf("\n\n");
    node* temp = Search(root,18);
    printf("\nData is Found = %d\n",temp->data);
    return 0;
}
