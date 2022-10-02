#include <iostream>
#include <stdlib.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
node *CreateNode(int data)
{
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        cout << "Memory Error\n";
        exit(0);
    }
    n->data = data;
    n->left = n->right = NULL;
    return n;
}
node *InsertNode(node *root, int data)
{
    node *n = CreateNode(data);
    if (root == NULL)
    {
        root = n;
        return root;
    }
    else if (root->data > data)
        root->left = InsertNode(root->left, data);
    else if (root->data < data)
        root->right = InsertNode(root->right, data);
    else
    {
        cout << "Same data Can Not Allow in Tree\n";
        return root;
    }
    return root;
}
void InOrderTravertion(node *root)
{
    if (root != NULL)
    {
        InOrderTravertion(root->left);
        cout << root->data << "\t";
        InOrderTravertion(root->right);
    }
}
node *BinarySearch(node *root, int data)
{
    if (root == NULL)
    {
        cout << "Empty Tree\n";
        return NULL;
    }
    else if (root->data == data)
        return root;
    else if (root->data > data)
        return (BinarySearch(root->left, data));
    else
        return (BinarySearch(root->right, data));
}
node *MinNode(node *root)
{
    node *p = root;
    while (p->left != NULL && p == NULL)
        p = p->left;
    return p;
}
node *DeleteNode(node *root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = DeleteNode(root->left, data);
    else if (data > root->data)
        root->right = DeleteNode(root->right, data);
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        // Take inorder successor
        node *temp = MinNode(root->right);
        root->data = temp->data;
        root->right = DeleteNode(root->right, temp->data);
    }
    return root;
}
int main(int argc, char const *argv[])
{
    node *root = NULL;
    root = InsertNode(root, 10);
    root = InsertNode(root, 1);
    root = InsertNode(root, 11);
    root = InsertNode(root, 12);
    root = InsertNode(root, 0);
    root = InsertNode(root, 60);
    root = InsertNode(root, 20);
    InOrderTravertion(root);
    cout << endl;
    cout << "Data = " << (BinarySearch(root, 20))->data << endl;
    cout<<"--------------------\n";
    root = DeleteNode(root,1);
    root = DeleteNode(root,20);
    InOrderTravertion(root);

    return 0;
}
