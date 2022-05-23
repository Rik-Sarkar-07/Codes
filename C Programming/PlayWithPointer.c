#include<stdio.h>
#include<stdlib.h>
void Swap(int*,int*);
int main(int argc, char *argv[])
{
    printf("The no of file = %d\n",argc);
    printf("The Name of the file alomg with full path = %s\n",argv[0]);

    // Play with pointers
    int* array = (int*)calloc(sizeof (int),10); // array size 10
    for(int i=0;i<10;i++)
    array[i] = i;

    printf("array[0] = %d\n",array[0]);
    printf("array[1] = %d\n",array[1]);

    printf("\n\n");

    printf("*(array+0) = %d\n",*(array+0));
    printf("*(array+1) = %d\n",*(array+1));
    printf("*(array+2) = %d\n",*(array+2));
    printf("*(array+3) = %d\n",*(array+3));


    // Play with Pointer to Pointer 2D Pointer to Matrix

    int** Matrix = (int**)calloc(sizeof (int*),4);      // Matrix[4][3]
    for(int i=0;i<4;i++)
        Matrix[i] = (int*)calloc(sizeof (int),3);

    for(int i=0;i<4;i++)
        for(int j=0;j<3;j++)
            Matrix[i][j] = i*10+j;

    for(int i=0;i<4;i++){

        for(int j=0;j<3;j++)
        {
            printf("%d\t",Matrix[i][j]);
        }
        printf("\n\n");
    }



    printf("Matrix[0][0] = %d\n",Matrix[0][0]);

    printf("Matrix[0][0] = %d\n",*(*(Matrix + 0)+0));


    printf("Matrix[2][1] = %d\n",Matrix[2][1]);

    printf("Matrix[2][1] = %d\n",*(*(Matrix + 2)+1));



    int* arr = (int*)malloc(sizeof (int)*10);
    for(int i=0;i<10;i++)
        arr[i] = i;

    for(int i=0;i<10;i++)
        printf("%d\t",*arr++);
    
    // Pointer Arithmatic
    int i = 10;
    int j = 20;
    int* k = &i;
    int* l = &j;

    printf("\ni = %d\t j = %d\t *k = %d\t *l = %d\n",i,j,*k,*l);


    *l = *l + *k;
    *k = *l - *k;

     printf("i = %d\t j = %d\t *k = %d\t *l = %d\n",i,j,*k,*l);

     // Call By Reference
     // i =30 and j = 20
     printf("i = %d\t j = %d\n",i,j);
    Swap(&i,&j);
    printf("i = %d\t j = %d\n",i,j);
    return 0;
}
void Swap(int *i,int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}
