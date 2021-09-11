#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;	
};
void Travertion(struct Node* head) 
{
	struct Node* p = head;
	while(p != NULL)
	{
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n\n");
}
struct Node* AdditionAtFirst(struct Node* head,int data)
{
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	if( n == NULL)
	{
		printf("Memory is Full -- Not Possible\n");
		return (head);
	}
	else
	{
		printf("\t After Addition List Node \n");
		n->next = head;
		head = n;
		return (head);
	}
}
struct Node* AdditionAtLast(struct Node* head,int data)
{
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	if(n == NULL)
	{
		printf("Memory is Full -- Operation Failed \n");
		return (head);
	}
	else
	{
		printf("\t After Addition List Node \n");
		struct Node* p = head;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = n;
		n->next = NULL;
		return (head);
	}
}
struct Node* AdditionAtAnyIndex(struct Node* head,int data,int index)
{
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	if(n == NULL)
	{
		printf("Memory is Full -- Operation is failed \n");
		return (head);
	}
	else
	{
		printf("\t After Addition List Node \n");
		int i = 0;
		struct Node* p = head;
		while(i<index-1 && p != NULL)
		{
			p = p->next;
			i++;
		}
		n->next = p->next;
		p->next = n;
		return (head);
	}
}
struct Node* DeleteAtLastNode(struct Node* head)
{
	if(head == NULL)
	{
		printf("List Node is Empty  \n");
		return head;
	}
	else
	{
		printf("\t After Delete Last Node \n");
		struct Node* p = head;
		struct Node* q = head->next;
		while(q->next != NULL)
		{
			p = p->next;
			q = q->next;
		}
		p->next = q->next;
		free(q);
		return head;
	}
}
struct Node* DeleteAtFirstNode(struct Node* head)
{
	if(head == NULL)
	{
		printf("Empty list \n");
		return head;
	}
	else
	{
		printf("\t After Delete the frist node \n");
		struct Node* p = head;
		head = head->next;
		free(p);
		return (head);
	}
}
struct Node* DeleteAtAnyIndex(struct Node* head,int index)
{
	if(head == NULL)
	{
		printf("List is Empty \n");
		return head;
	}
	else if(index < 0)
	{
		printf("Not vailid \n");
	}
	else
	{
		struct Node* p = head;
		struct Node* q = head->next;
		int i = 0;
		printf("\t After Delete at any index \n");
		while(index-1 > i && q != NULL)
		{
			p = p->next;
			q = q->next;
			i++;
		}
		p->next = q->next;
		free(q);
		return head;
	}
}
struct Node* ListAddition(struct Node* head1,struct Node* head2)
{
	printf("\t After Addition of two List \n");
	struct Node* p = head1;
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = head2;
	return head1;
}
int main()
{
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	struct Node* f1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* f2 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* f3 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* f4 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* f5 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* f6 = (struct Node*)malloc(sizeof(struct Node));
	
	head->data = 10;	head->next = f1;
	f1->data = 20;	    f1->next = f2;
	f2->data = 30;		f2->next = f3;
	f3->data = 40;		f3->next = f4;
	f4->data = 50;		f4->next = f5;
	f5->data = 60;		f5->next = f6;
	f6->data = 70;		f6->next = NULL;
	
	
	struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* f11 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* f21 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* f31 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* f41 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* f51 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* f61 = (struct Node*)malloc(sizeof(struct Node));
	
	head1->data = 110;		head1->next = f11;
	f11->data = 120;	    f11->next = f21;
	f21->data = 130;		f21->next = f31;
	f31->data = 140;		f31->next = f41;
	f41->data = 150;		f41->next = f51;
	f51->data = 160;		f51->next = f61;
	f61->data = 170;		f61->next = NULL;		
	Travertion(head);
	
	head = AdditionAtFirst(head,5);
	Travertion(head);
	
	head = AdditionAtLast(head,80);
	Travertion(head);
	
	head = AdditionAtAnyIndex(head,35,4);
	Travertion(head);
	
	head = DeleteAtFirstNode(head);
	Travertion(head);
	
	head = DeleteAtLastNode(head);
	Travertion(head);
	
	head = DeleteAtAnyIndex(head,4);
	Travertion(head);
	
	head = ListAddition(head,head1);
	Travertion(head);
	return 0;
}
