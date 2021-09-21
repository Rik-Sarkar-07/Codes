#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* Create(int data)
{
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	if(n == NULL)
	{
		printf("Memory is Full \n");
		exit(1);
	}	
	else
	{
		n->data = data;
		n->left = NULL;
		n->right = NULL;
		return n;
	}
}
void PreorderTraversion(struct Node* root)
{
	if(root != NULL)
	{
		printf("%d\t",root->data);
		PreorderTraversion(root->left);
		PreorderTraversion(root->right);
	}
}
void InOrderTravertion(struct Node* root)
{
	if(root != NULL)
	{
		InOrderTravertion(root->left);
		printf("%d\t",root->data);
		InOrderTravertion(root->right);
	}
}
void PostOrderTravertion(struct Node* root)
{
	if(root != NULL)
	{
		InOrderTravertion(root->left);
		InOrderTravertion(root->right);	
		printf("%d\t",root->data);
	}
}
int main()
{
	struct Node* root = Create(10);
	struct Node* f1 = Create(12);
	struct Node* f2 = Create(15);
	struct Node* f3 = Create(20);
	struct Node* f4 = Create(25);
	struct Node* f5 = Create(30);
	root->left = f1;
	root->right = f2;
	f1->right = f3;
	f1->left = f4;
	f2->left = f5;
	printf("\t After PreOrder Traversion ---- \n");
	PreorderTraversion(root);
	printf("\n\t After InOrder Traversion ---- \n");
	InOrderTravertion(root);
	printf("\n\t After PostOrder Traversion ---- \n");
	PostOrderTravertion(root);
	return 0;
}
