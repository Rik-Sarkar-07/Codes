// // // // // #include <stdio.h>
// // // // // #include <stdlib.h>
// // // // // struct Node
// // // // // {
// // // // //     int data;
// // // // //     struct Node *next;
// // // // // };
// // // // // typedef struct Node node;
// // // // // node *CreateNode(int data)
// // // // // {
// // // // //     node *n = (node *)malloc(sizeof(node));
// // // // //     if (n == NULL)
// // // // //     {
// // // // //         printf("Memory Error\n");
// // // // //         return (n);
// // // // //     }
// // // // //     else
// // // // //     {
// // // // //         n->data = data;
// // // // //         n->next = NULL;
// // // // //         return n;
// // // // //     }
// // // // // }
// // // // // void Print(node *head)
// // // // // {
// // // // //     if (head == NULL)
// // // // //     {
// // // // //         printf("Linked list is Empty \n");
// // // // //         return;
// // // // //     }
// // // // //     else
// // // // //     {
// // // // //         node *p = head;
// // // // //         printf("\t The Linked list is  ---- \n");
// // // // //         while (p != NULL)
// // // // //         {
// // // // //             printf("%d\t", p->data);
// // // // //             p = p->next;
// // // // //         }
// // // // //         printf("\n");
// // // // //     }
// // // // // }
// // // // // void Insert_at_frist(node **head, int data)
// // // // // {
// // // // //     node *n = CreateNode(data);
// // // // //     n->next = *head;
// // // // //     *head = n;
// // // // // }
// // // // // void Insert_at_last(node **head, int data)
// // // // // {
// // // // //     node *p = *head;
// // // // //     node *n = CreateNode(data);
// // // // //     while (p->next != NULL)
// // // // //         p = p->next;
// // // // //     p->next = n;
// // // // // }
// // // // // void Insert_at_any_position(node **head, int pos, int data)
// // // // // {
// // // // //     if(pos == 1)
// // // // //     {
// // // // //         Insert_at_frist(head,data);
// // // // //         return;
// // // // //     }
// // // // //     node *p = *head;
// // // // //     int i = 1;
// // // // //     node *n = CreateNode(data);
// // // // //     while (i < pos - 1 && p->next != NULL)
// // // // //     {
// // // // //         p = p->next;
// // // // //         i++;
// // // // //     }
// // // // //     if (p->next == NULL)
// // // // //         printf("Index out of range so we add the data at last position \n");
// // // // //     n->next = p->next;
// // // // //     p->next = n;
// // // // // }
// // // // // void Delete_at_frist(node**head)
// // // // // {
// // // // //     if(*head == NULL)
// // // // //     {
// // // // //         printf("Linked list is Empty \n");
// // // // //         return;
// // // // //     }
// // // // //     else
// // // // //     {
// // // // //         node* temp = *head;
// // // // //         *head = (*head)->next;
// // // // //         int data = temp->data;
// // // // //         free(temp);
// // // // //         printf("The data %d has been deleted \n",data);
// // // // //         return;
// // // // //     }
// // // // // }
// // // // // void Delete_at_last(node** head)
// // // // // {
// // // // //     if(*head == NULL)
// // // // //     {
// // // // //          printf("Linked list is Empty \n");
// // // // //         return;
// // // // //     }
// // // // //     else
// // // // //     {
// // // // //         node* p = *head;
// // // // //         while(p->next->next != NULL)
// // // // //             p = p->next;
// // // // //         node* temp = p->next;
// // // // //         p->next = NULL;
// // // // //         int data = temp->data;
// // // // //         free(temp);
// // // // //          printf("The data %d has been deleted \n",data);
// // // // //         return;
// // // // //     }
// // // // // }
// // // // // void Delete_at_any_position(node** head,int pos)
// // // // // {
// // // // //     node* p = *head;
// // // // //     int i = 1;
// // // // //     if(pos == 1)
// // // // //     {
// // // // //         Delete_at_frist(head);
// // // // //         return;
// // // // //     }
// // // // //     while(p->next->next != NULL && i<pos-1)
// // // // //     {
// // // // //         p = p->next;
// // // // //         i++;
// // // // //     }
// // // // //     node* temp = p->next;
// // // // //     p->next = temp->next;
// // // // //     int data = temp->data;
// // // // //     free(temp);
// // // // //     printf("The data %d has been deleted \n",data);
// // // // //     return;
// // // // // }
// // // // // int main(int argc, char const *argv[])
// // // // // {
// // // // //     node *head = NULL;
// // // // //     for (int i = 0; i <= 5; i++)
// // // // //     {
// // // // //         Insert_at_frist(&head, 10 + i);
// // // // //     }
// // // // //     Print(head);
// // // // //     for (int i = 0; i <= 5; i++)
// // // // //     {
// // // // //         Insert_at_last(&head, i);
// // // // //     }
// // // // //     Print(head);
// // // // //     Insert_at_any_position(&head, 1, 100);
// // // // //     Print(head);
// // // // //     Insert_at_any_position(&head, 200, 400);
// // // // //     Print(head);
// // // // //     Insert_at_any_position(&head, 5, 500);
// // // // //     Print(head);
// // // // //     Delete_at_last(&head);
// // // // //     Print(head);
// // // // //     Delete_at_any_position(&head,2);
// // // // //     Print(head);
// // // // //     Delete_at_last(&head);
// // // // //     Print(head);
// // // // //     return 0;
// // // // // }
// // // // #include <stdio.h>
// // // // #include <stdlib.h>
// // // // typedef struct Node
// // // // {
// // // //     int data;
// // // //     struct Node *next;
// // // // } node;
// // // // node *CreateNode(int data)
// // // // {
// // // //     node *n = (node *)malloc(sizeof(node));
// // // //     if (n == NULL)
// // // //         printf("Memory Error \n");

// // // //     else
// // // //     {
// // // //         n->data = data;
// // // //         n->next = n;
// // // //     }
// // // //     return n;
// // // // }
// // // // void Print(node *head)
// // // // {
// // // //     if (head == NULL)
// // // //     {
// // // //         printf("Linked list is Empty \n");
// // // //         return;
// // // //     }
// // // //     else
// // // //     {
// // // //         node *p = head->next;
// // // //         printf("\t\t The Circular Linked list is --- \n");
// // // //         printf("\t%d", head->data);
// // // //         while (p != head)
// // // //         {
// // // //             printf("\t%d", p->data);
// // // //             p = p->next;
// // // //         }
// // // //         printf("\n");
// // // //     }
// // // // }
// // // // void Insert_at_frist(node **head, node **tail, int data)
// // // // {
// // // //     if (*head == NULL)
// // // //     {
// // // //         *tail = *head = CreateNode(data);
// // // //         return;
// // // //     }
// // // //     else
// // // //     {
// // // //         node *n = CreateNode(data);
// // // //         (*tail)->next = n;
// // // //         n->next = *head;
// // // //         *head = n;
// // // //         return;
// // // //     }
// // // // }
// // // // void Insert_at_last(node **head, node **tail, int data)
// // // // {
// // // //     if (*head == NULL)
// // // //     {
// // // //         *tail = *head = CreateNode(data);
// // // //         return;
// // // //     }
// // // //     else
// // // //     {
// // // //         node *n = CreateNode(data);
// // // //         (*tail)->next = n;
// // // //         n->next = *head;
// // // //         *tail = n;
// // // //         return;
// // // //     }
// // // // }
// // // // void Insert_at_any_position(node **head, node **tail, int data, int pos)
// // // // {
// // // //     if (pos == 1)
// // // //     {
// // // //         Insert_at_frist(head, tail, data);
// // // //         return;
// // // //     }
// // // //     node *p = *head;
// // // //     node *temp;
// // // //     int i = 1;
// // // //     while (p->next != *head && i < pos - 1)
// // // //     {
// // // //         p = p->next;
// // // //         i++;
// // // //     }
// // // //     if (p->next == *head)
// // // //     {
// // // //         printf("Position out of range \n");
// // // //         Insert_at_last(head, tail, data);
// // // //         return;
// // // //     }
// // // //     else
// // // //     {
// // // //         node *n = CreateNode(data);
// // // //         n->next = p->next;
// // // //         p->next = n;
// // // //         return;
// // // //     }
// // // // }
// // // // void Delete_at_frist(node **head, node **tail)
// // // // {
// // // //     if (*head == NULL)
// // // //     {
// // // //         printf("Linked list is Empty \n");
// // // //         return;
// // // //     }
// // // //     else
// // // //     {
// // // //         node *temp = *head;
// // // //         *head = (*head)->next;
// // // //         (*tail)->next = *head;
// // // //         printf("The data %d has been deleted\n", temp->data);
// // // //         free(temp);
// // // //     }
// // // // }
// // // // void Delete_at_last(node **head, node **tail)
// // // // {
// // // //     if (*head == NULL)
// // // //     {
// // // //         printf("Linked list is Empty \n");
// // // //         return;
// // // //     }
// // // //     else
// // // //     {
// // // //         node *temp;
// // // //         node *p = *head;
// // // //         while (p->next != *tail)
// // // //             p = p->next;
// // // //         *tail = p;
// // // //         temp = p->next;
// // // //         (*tail)->next = *head;
// // // //         printf("The data %d has been deleted\n", temp->data);
// // // //         free(temp);
// // // //     }
// // // // }
// // // // void Delete_at_any_position(node **head, node **tail, int pos)
// // // // {
// // // //     if (*head == NULL)
// // // //     {
// // // //         printf("Linked list is Empty \n");
// // // //         return;
// // // //     }
// // // //     else
// // // //     {
// // // //         if (pos == 1)
// // // //         {
// // // //             Delete_at_frist(head, tail);
// // // //             return;
// // // //         }
// // // //         int i = 1;
// // // //         node *p = *head;
// // // //         while (p->next != *tail && i < pos - 1)
// // // //         {
// // // //             p = p->next;
// // // //             i++;
// // // //         }
// // // //         if (p->next == *tail)
// // // //         {
// // // //             printf("Position out of renge \n");
// // // //             Delete_at_last(head, tail);
// // // //             return;
// // // //         }
// // // //         else
// // // //         {
// // // //             node *temp = p->next;
// // // //             p->next = temp->next;
// // // //             printf("The data %d has been deleted\n", temp->data);
// // // //             free(temp);
// // // //             return;
// // // //         }
// // // //     }
// // // // }
// // // // int main(int argc, char const *argv[])
// // // // {
// // // //     node *head = NULL;
// // // //     node *tail = NULL;
// // // //     for (int i = 0; i < 5; i++)
// // // //         Insert_at_frist(&head, &tail, 10 + i);
// // // //     Print(head);
// // // //     for (int i = 0; i < 5; i++)
// // // //         Insert_at_last(&head, &tail, i);
// // // //     Print(head);
// // // //     Insert_at_any_position(&head, &tail, 200, 3);
// // // //     Print(head);
// // // //     Delete_at_any_position(&head, &tail,4);
// // // //     Print(head);
// // // //     return 0;
// // // // }
// // // #include<stdio.h>
// // // #include<stdlib.h>
// // // typedef struct Node{
// // //     int data;
// // //     struct Node* next;
// // //     struct Node* prev;
// // // }node;
// // // node* CreateNode(int data)
// // // {
// // //     node* n = (node*)malloc(sizeof(node));
// // //     if(n == NULL)
// // //     printf("Memory Error \n");
// // //     else
// // //     {
// // //         n->data = data;
// // //         n->next = NULL;
// // //         n->prev = NULL;
// // //     }
// // //     return n;
// // // }
// // // void Print(node* head)
// // // {
// // //     node* p = head;
// // //     if(p == NULL)
// // //     {
// // //         printf("Linked list is Empty \n");
// // //         return;
// // //     }
// // //     else
// // //     {
// // //         printf("The Linked List is --- \n");
// // //         while(p != NULL)
// // //         {
// // //             printf("%d\t",p->data);
// // //              p = p->next;
// // //         }
// // //         printf("\n\n");
// // //     }
// // // }
// // // void Insert_at_frist(node** head,int data)
// // // {
// // //     if(*head == NULL)
// // //     {
// // //         *head = CreateNode(data);
// // //         return;
// // //     }
// // //     else
// // //     {
// // //         node* n = CreateNode(data);
// // //         (*head)->prev = n;
// // //         n->next = *head;
// // //         *head = n;
// // //         return;
// // //     }
// // // }
// // // void Insert_at_last(node** head,int data)
// // // {
// // //      if(*head == NULL)
// // //     {
// // //         *head = CreateNode(data);
// // //         return;
// // //     }
// // //     else
// // //     {
// // //         node* n = CreateNode(data);
// // //         node* p = *head;
// // //         while(p->next != NULL)
// // //         p = p->next;
// // //         p->next = n;
// // //         n->prev = p;
// // //         return;
// // //     }
// // // }
// // // void Insert_at_any_position(node** head,int data,int pos)
// // // {
// // //      if(*head == NULL)
// // //     {
// // //         *head = CreateNode(data);
// // //         return;
// // //     }
// // //     else
// // //     {
// // //         if(pos == 1)
// // //         {
// // //             Insert_at_frist(head,data);
// // //             return;
// // //         }
// // //         node* n = CreateNode(data);
// // //         node* p = *head;
// // //         int i=1;
// // //         while(p->next != NULL && i<pos-1)
// // //         {
// // //             p = p->next;
// // //             i++;
// // //         }
// // //         if(p->next == NULL)
// // //         {
// // //             printf("Position out of index \n");
// // //             Insert_at_last(head,data);
// // //             return;
// // //         }
// // //         else
// // //         {
// // //             n->next = p->next;
// // //             (p->next)->prev = n;
// // //             n->prev = p;
// // //             p->next = n;
// // //             return;
// // //         }
// // //     }
// // // }
// // // void Delete_at_frist(node** head)
// // // {
// // //     if(*head == NULL)
// // //     {
// // //         printf("Linked list is empty \n");
// // //         return;
// // //     }
// // //     else
// // //     {
// // //         node* temp = *head;
// // //         *head = (*head)->next;
// // //         printf("The %d data has been deleted \n",temp->data);
// // //         free(temp);
// // //         return;
// // //     }
// // // }
// // // void Delete_at_last(node** head)
// // // {
// // //     if(*head == NULL)
// // //     {
// // //         printf("Link list is empty \n");
// // //         return;
// // //     }
// // //     else
// // //     {
// // //         node* p = *head;
// // //         while(p->next->next != NULL)
// // //         p = p->next;
// // //         node *temp = p->next;
// // //         p->next = NULL;
// // //         printf("The %d data has been deleted \n",temp->data);
// // //         free(temp);
// // //         return;
// // //     }
// // // }
// // // void Delete_at_any_position(node** head,int pos)
// // // {
// // //     if(*head == NULL)
// // //     {
// // //         printf("The Linked list is Empty \n");
// // //         return;
// // //     }
// // //     else
// // //     {
// // //         if(pos == 1)
// // //         {
// // //             Delete_at_frist(head);
// // //             return;
// // //         }
// // //         int i=1;
// // //         node* p = *head;
// // //         node* temp;
// // //         while(p->next != NULL && i<pos)
// // //         {
// // //             p = p->next;
// // //             i++;
// // //         }
// // //         if(p->next == NULL)
// // //         {
// // //             printf("Index out of range \n");
// // //             Delete_at_last(head);
// // //             return;
// // //         }
// // //         temp = p;
// // //         (p->prev)->next = p->next;
// // //         (p->next)->prev = p->prev;
// // //          printf("The %d data has been deleted \n",temp->data);
// // //         free(temp);
// // //     }
// // // }
// // // int main(int argc, char const *argv[])
// // // {
// // //     node* head = NULL;
// // //     for(int i=0;i<5;i++)
// // //     Insert_at_frist(&head,10+i);
// // //     Print(head);
// // //      for(int i=0;i<5;i++)
// // //     Insert_at_last(&head,i);
// // //     Print(head);
// // //     Insert_at_any_position(&head,100,4);
// // //     Print(head);
// // //     Delete_at_any_position(&head,5);
// // //     Print(head);
// // //     return 0;
// // // }
// // #include <stdio.h>
// // #include <stdlib.h>
// // typedef struct Node
// // {
// //     int data;
// //     struct Node *next;
// //     struct Node *prev;
// // } node;
// // node *CreateNode(int data)
// // {
// //     node *n = (node *)malloc(sizeof(node));
// //     if (n == NULL)
// //     {
// //         printf("Memory error \n");
// //         return (NULL);
// //     }
// //     else
// //     {
// //         n->data = data;
// //         n->next = n;
// //         n->prev = n;
// //         return n;
// //     }
// // }
// // void Print(node *head)
// // {
// //     if (head == NULL)
// //     {
// //         printf("Linked list is Empty \n");
// //         return;
// //     }
// //     else
// //     {
// //         node *p = head->next;
// //         printf("The linked list is ---- \n");
// //         printf("%d\t", head->data);
// //         while (p != head)
// //         {
// //             printf("%d\t", p->data);
// //             p = p->next;
// //         }
// //         printf("\n\n");
// //     }
// // }
// // void Insert_at_frist(node **head, node **last, int data)
// // {
// //     if (*head == NULL)
// //     {
// //         *last = *head = CreateNode(data);
// //         return;
// //     }
// //     else
// //     {
// //         node *n = CreateNode(data);
// //         (*last)->next = n;
// //         n->prev = *last;
// //         n->next = *head;
// //         (*head)->prev = n;
// //         *head = n;
// //         return;
// //     }
// // }
// // void Insert_at_last(node **head, node **tail, int data)
// // {
// //     if (*head == NULL)
// //     {
// //         *tail = *head = CreateNode(data);
// //         return;
// //     }
// //     else
// //     {
// //         node *n = CreateNode(data);
// //         (*tail)->next = n;
// //         n->prev = *tail;
// //         n->next = *head;
// //         (*head)->prev = n;
// //         *tail = n;
// //         return;
// //     }
// // }
// // void Insert_at_any_position(node **head, node **tail, int pos, int data)
// // {
// //     if (*head == NULL)
// //     {
// //         *tail = *head = CreateNode(data);
// //         return;
// //     }
// //     else
// //     {
// //         if (pos == 1)
// //         {
// //             Insert_at_frist(head, tail, data);
// //             return;
// //         }
// //         node *n = CreateNode(data);
// //         node *p = *head;
// //         int i = 1;
// //         while (p != *tail && i < pos - 1)
// //         {
// //             p = p->next;
// //             i++;
// //         }
// //         if (p == *tail)
// //         {
// //             printf("Index out of range \n");
// //             Insert_at_last(head, tail, data);
// //             return;
// //         }
// //         else
// //         {
// //             n->next = p->next;
// //             (p->next)->prev = n;
// //             p->next = n;
// //             n->prev = p;
// //             return;
// //         }
// //     }
// // }
// // void Delete_at_frist(node **head, node **tail)
// // {
// //     if (*head == NULL)
// //     {
// //         printf("Linked list is Empty \n");
// //         return;
// //     }
// //     else
// //     {
// //         node *temp = *head;
// //         *head = (*head)->next;
// //         (*head)->prev = *tail;
// //         (*tail)->next = *head;
// //         printf("The %d Data has been deleted \n", temp->data);
// //         free(temp);
// //         return;
// //     }
// // }
// // void Delete_at_last(node **head, node **tail)
// // {
// //     if (*head == NULL)
// //     {
// //         printf("Linked list is Empty \n");
// //         return;
// //     }
// //     else
// //     {
// //         node *temp = *tail;
// //         *tail = (*tail)->prev;
// //         (*tail)->next = *head;
// //         (*head)->prev = *tail;
// //         printf("The %d Data has been deleted \n", temp->data);
// //         free(temp);
// //         return;
// //     }
// // }
// // void Delete_at_any_position(node **head, node **tail, int pos)
// // {
// //     if (*head == NULL)
// //     {
// //         printf("Linked list is Empty \n");
// //         return;
// //     }
// //     else
// //     {
// //         if (pos == 1)
// //         {
// //             Delete_at_frist(head, tail);
// //             return;
// //         }
// //         int i = 1;
// //         node *p = *head;
// //         node *temp;
// //         while (p != *tail && i < pos)
// //         {
// //             p = p->next;
// //             i++;
// //         }
// //         if (p == *tail)
// //         {
// //             printf("Index out of range \n");
// //             Delete_at_last(head, tail);
// //             return;
// //         }
// //         temp = p;
// //         (p->prev)->next = p->next;
// //         (p->next)->prev = p->prev;
// //         printf("The %d Data has been deleted \n", temp->data);
// //         free(temp);
// //         return;
// //     }
// // }
// // int main(int argc, char const *argv[])
// // {
// //     node *head = NULL;
// //     node *tail = NULL;
// //     for (int i = 0; i < 5; i++)
// //         Insert_at_last(&head, &tail, 10 + i);
// //     Print(head);
// //     Insert_at_any_position(&head, &tail, 5, 100);
// //     Print(head);
// //     Delete_at_any_position(&head, &tail, 4);
// //     Print(head);
// //     return 0;
// // }
// #include <stdio.h>
// #include <stdlib.h>
// struct Node
// {
//     int data;
//     struct Node *next;
// };
// typedef struct Node node;
// void Print(node *head)
// {
//     if (head == NULL)
//     {
//         printf("Linked List is Empty \n");
//     }
//     else
//     {
//         node *p = head;
//         while (p != NULL)
//         {
//             printf("%d\t", p->data);
//             p = p->next;
//         }
//         printf("\n");
//     }
// }
// node *CreateNode(int data)
// {
//     node *new = (node *)malloc(sizeof(node));
//     if (new == NULL)
//     {
//         printf("Mwmory Error\n");
//         return NULL;
//     }
//     else
//     {
//         new->data = data;
//         new->next = NULL;
//     }
// }
// node *ReverseLinkedList(node *head)
// {
//     node *curr = head;
//     node *prev = NULL;
//     node *nextptr;
//     while (curr != NULL)
//     {
//         nextptr = curr->next;
//         curr->next = prev;

//         prev = curr;
//         curr = nextptr;
//     }
//     head = prev;
//     return (head);
// }
// node *InsertNode(node *head, int data)
// {
//     node *new = CreateNode(data);
//     if (head == NULL)
//     {
//         head = new;
//     }
//     else
//     {
//         new->next = head;
//         head = new;
//     }
//     return (head);
// }
// void Sorting(node **head)
// {
//     for (node *i = *head; i->next != NULL; i = i->next)
//     {
//         for (node *j = *head; j->next != NULL; j = j->next)
//         {
//             if (j->data > j->next->data)
//             {
//                 int data = j->data;
//                 j->data = j->next->data;
//                 j->next->data = data;
//             }
//         }
//     }
// }
// int main(int argc, char const *argv[])
// {
//     node *head = NULL;
//     for (int i = 0; i <= 10; i++)
//     {
//         head = InsertNode(head, (10 + i));
//     }
//     printf("\tBefore the Reverse Linked List \n");
//     Print(head);
//     Sorting(&head);
//     printf("After Sorting \n");
//     Print(head);
//     printf("\tAfter the Reverse Linked List \n");
//     head = ReverseLinkedList(head);
//     Print(head);
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
struct DoublyLinkedList
{
    int data;
    struct DoublyLinkedList *next;
    struct DoublyLinkedList *prev;
};
typedef struct DoublyLinkedList node;
node *CreateNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Memory Error\n");
        return (NULL);
    }
    else
    {
        new->data = data;
        new->prev = NULL;
        new->next = NULL;
        return (new);
    }
}
void Print(node *head)
{
    node *p = head;
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}
node *InsertionAtFirst(node *head, int data)
{
    if (head == NULL)
    {
        head = CreateNode(data);
        return (head);
    }
    else
    {
        node *new = CreateNode(data);
        new->next = head;
        head->prev = new;
        head = new;
        return (head);
    }
}
void Reverse(node** head)
{
    node* temp = NULL;
    node* curr = *head;
    while(curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }
    if(temp != NULL)
    *head = temp->prev;
}
int main(int argc, char const *argv[])
{
    node *head = NULL;
    for(int i=0;i<10;i++)
    head = InsertionAtFirst(head,10+i);
    Print(head);
    Reverse(&head);
    printf("After Reverse the linked list \n");
    Print(head);
    return 0;
}
