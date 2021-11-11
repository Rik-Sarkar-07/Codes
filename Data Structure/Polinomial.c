#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Polinomial
{
    int value;
    char variable;
    int degree;
};
struct Node
{
    struct Polinomial data;
    struct Node *next;
};
typedef struct Node node;
void Print(node *pol)
{
    printf("Equation is = ");
    node *p = pol;
    while (p->next != NULL)
    {
        printf("%d %c^ %d + ", p->data.value, p->data.variable, p->data.degree);
        p = p->next;
    }
    printf("%d %c^ %d ", p->data.value, p->data.variable, p->data.degree);
    printf("\n\n");
}
void Sum(node *p1, node *p2)
{
    if (p1 == NULL || p2 == NULL)
    {
        printf("Error \n");
        return;
    }
    else
    {
        printf("After Sum Both Equations \n");
        node *p = p1;
        node *q = p2;
        node *new = (node *)malloc(sizeof(node));
        while (p->next != NULL && q->next != NULL)
        {
            if (p->data.degree == q->data.degree && p->data.variable == q->data.variable)
            {
                new->data.degree = p->data.degree;
                new->data.variable = p->data.variable;
                new->data.value = p->data.value + q->data.value;
                printf("%d %c^ %d + ", new->data.value, new->data.variable, new->data.degree);
            }
            p = p->next;
            q = q->next;
        }
        new->data.degree = p->data.degree;
        new->data.variable = p->data.variable;
        new->data.value = p->data.value + q->data.value;
        printf("%d %c^ %d \n\n", new->data.value, new->data.variable, new->data.degree);
    }
}
int main(int argc, char const *argv[])
{
    node *x1 = (node *)malloc(sizeof(node));
    node *x2 = (node *)malloc(sizeof(node));
    node *x3 = (node *)malloc(sizeof(node));
    // x^2+4x+7
    x1->data.value = 1;
    x1->data.degree = 2;
    x1->data.variable = 'x';
    x2->data.value = 4;
    x2->data.degree = 1;
    x2->data.variable = 'x';
    x3->data.value = 7;
    x3->data.degree = 0;
    x3->data.variable = 'x';
    x1->next = x2;
    x2->next = x3;
    x3->next = NULL;
    node *y1 = (node *)malloc(sizeof(node));
    node *y2 = (node *)malloc(sizeof(node));
    node *y3 = (node *)malloc(sizeof(node));
    // 4x^2+9x-2
    y1->data.value = 4;
    y1->data.degree = 2;
    y1->data.variable = 'x';
    y2->data.value = 9;
    y2->data.degree = 1;
    y2->data.variable = 'x';
    y3->data.value = 2;
    y3->data.degree = 0;
    y3->data.variable = 'x';
    y1->next = y2;
    y2->next = y3;
    y3->next = NULL;
    Print(x1);
    Print(y1);
    Sum(x1, y1);
    return 0;
}
