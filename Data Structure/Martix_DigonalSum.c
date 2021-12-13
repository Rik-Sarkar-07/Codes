#include<stdio.h>
#include<stdlib.h>
int main()
{
    int** arr;
    int row,col;
    int i,j;
    int sum1,sum2,sum;
    int l,k;

    int** arr1;
    int row1,col1;
    int sum11,sum21,sum0;
    int l1,k1;

    int* array;

    printf("\t Enter the Details of First Square Matrix \n");
    printf("Enter the numbers of Row of the Matrix = ");
    scanf("%d",&row);
    printf("Enter the numbers of Colums of the Matrix = ");
    scanf("%d",&col);

    if(row != col)
    {
        printf("\n \t The Matrix is not a square matrix FAILED !!\n");
        exit(1);
    }

    arr = (int**)malloc(sizeof (int*)*row);
     for(int i=0;i<row;i++)
     {
        arr[i] = (int*)malloc(sizeof (int)*col);
     }
     printf("Enter The Elements of the Matrix -- \n");

      for( i=0;i<row;i++)
      {
          for( j=0;j<col;j++)
          {
             scanf("%d",&arr[i][j]);
          }
      }

    printf("\t Your First Matrix is --- \n\n");

        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
               printf("\t%d",arr[i][j]);
            }
            printf("\n\n");
        }
        sum1 = arr[0][0];
        for(i=1;i<row;i++)
        {
            for(j=1;j<col;j++)
            {
                if(i == j)
                {
                    sum1 = sum1+arr[i][j];
                }
            }
        }
        sum2 = arr[0][col-1];
        for(i=1;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(i == col-j-1)
                {
                    sum2 = sum2+arr[i][j];
                }
            }
        }
        if(row % 2 == 0)
        {
            sum = sum1+sum2;
        }
        else
        {
            l = row/2;
            k = col/2;
            sum = sum1+sum2-arr[l][k];
        }
        printf("Sum of First Matrix digonal elements [Left to Right] = %d \n",sum1);
        printf("Sum of First Matrix digonal elements [Right to Left] = %d \n",sum2);
        printf("Total Sum of First Matrix Both Digonal elements = %d \n",sum);





        printf("\n\t Enter the Details of Second Square Matrix \n");
        printf("Enter the numbers of Row of the Matrix = ");
        scanf("%d",&row1);
        printf("Enter the numbers of Colums of the Matrix = ");
        scanf("%d",&col1);

        if(row1 != col1)
        {
            printf("\n \t The Matrix is not a square matrix FAILED !!\n");
            exit(1);
        }

        arr1 = (int**)malloc(sizeof (int*)*row1);
         for(int i=0;i<row1;i++)
         {
            arr1[i] = (int*)malloc(sizeof (int)*col1);
         }
         printf("Enter The Elements of the Matrix -- \n");

          for( i=0;i<row1;i++)
          {
              for( j=0;j<col1;j++)
              {
                 scanf("%d",&arr1[i][j]);
              }
          }

        printf("\t Your Second Matrix is --- \n\n");

            for(i=0;i<row1;i++)
            {
                for(j=0;j<col1;j++)
                {
                   printf("\t%d",arr1[i][j]);
                }
                printf("\n\n");
            }
            sum11 = arr1[0][0];
            for(i=1;i<row1;i++)
            {
                for(j=1;j<col1;j++)
                {
                    if(i == j)
                    {
                        sum11 = sum11+arr1[i][j];
                    }
                }
            }
            sum21 = arr1[0][col1-1];
            for(i=1;i<row1;i++)
            {
                for(j=0;j<col1;j++)
                {
                    if(i == col1-j-1)
                    {
                        sum21 = sum21+arr1[i][j];
                    }
                }
            }
            if(row1 % 2 == 0)
            {
                sum0 = sum11+sum21;
            }
            else
            {
                l1 = row1/2;
                k1 = col1/2;
                sum0 = sum11+sum21-arr1[l1][k1];
            }
            printf("Sum of Second Matrix digonal elements [Left to Right] = %d \n",sum11);
            printf("Sum of Second Matrix digonal elements [Right to Left] = %d \n",sum21);
            printf("Total Sum of Second Matrix Both Digonal elements = %d \n",sum0);


// All Sum Values are store in 1D array

  array = (int*)malloc(sizeof (int)*6);
   array[0] = sum;
   array[1] = sum1;
   array[2] = sum2;
   array[3] = sum0;
   array[4] = sum11;
   array[5] = sum21;

    printf("\n\n \t All Sum values are -- \n");
    for(i=0;i<6;i++)
    {
        printf("\t%d",array[i]);
    }
   printf("\n\n");

    return 0;
}
