#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct StackNode
{
    int top;
    char *arr;
    int size;
};
typedef struct StackNode stack;
char TOS(stack *s)
{
    return (s->arr[s->top]);
}
int isEmpty(stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}
int isFull(stack *s)
{
    if (s->top == s->size - 1)
        return 1;
    return 0;
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    return 0;
}
int Priority(char ch)
{
    if (ch == '^')
        return 4;
    else if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}
char* Reverse(char* ch)
{
    int i,j;
    char* temp= (char*)malloc(sizeof(char)*(strlen(ch)+1));
    for(i=strlen(ch)-1,j=0;i>=0;i--,j++)
    {
        temp[j] = ch[i];
    }
    temp[j]='\0';
    return (temp);
}
void Push(stack *s, char data)
{
    if (isFull(s))
        printf("Stack is Full \n");
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}
char Pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty \n");
        return ('x');
    }

    else
    {
        char val = s->arr[s->top];
        s->top--;
        return (val);
    }
}
char *InfixTOPostFix(char *infix)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->size = 50;
    s->top = -1;
    s->arr = (char *)malloc(sizeof(char) * s->size);
    char *postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 1));
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (infix[i] == '^')
            {
                if (Priority(infix[i]) >= Priority(TOS(s)))
                {
                    Push(s, infix[i]);
                    i++;
                }
            }
            else if (Priority(infix[i]) > Priority(TOS(s)))
            {
                Push(s, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = Pop(s);
                j++;
            }
        }
    }

    while (!isEmpty(s))
    {
        postfix[j] = Pop(s);
        j++;
    }

    postfix[j] = '\0';

    return (postfix);
}
char* InfixTOPreFix(char* infix)
{
    char* temp = Reverse(infix);
    return (Reverse(InfixTOPostFix(temp)));
}
int main(int argc, char const *argv[])
{
    char* infix = "A+B*C-D/F*K+H";
    printf("\t The InFix Expression is = %s\n",infix);
    printf("The PreFix Expression is = %s\n",InfixTOPreFix(infix));
    printf("The Postfix Expression is = %s\n",InfixTOPostFix(infix));
    return 0;
}

