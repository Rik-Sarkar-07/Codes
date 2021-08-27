#include<iostream>
using namespace std;
int main()
{
   int m,n;
   cout<<"Enter the numbers of row and colum \n";
   cin>>m>>n;
   int i,j,k;
   int A[m][n],B[m][n],C[m][n],D[m][n],E[m][n];
   cout<<"------ Enter First Matrix's Elements -----\n";
   for(i=0;i<m;i++)
   {
       for(j=0;j<n;j++)
       {
           cin>>A[i][j];
       }
   }
   cout<<"------ Enter Second Matrix's Elements -----\n";
   for(i=0;i<m;i++)
   {
       for(j=0;j<n;j++)
       {
           cin>>B[i][j];
       }
   }

   for(i=0;i<m;i++)
   {
       for(j=0;j<n;j++)
       {
          C[i][j] = A[i][j] + B[i][j];
          D[i][j] = A[i][j] - B[i][j];
       }
   }
   for(i=0;i<m;i++)
   {
       for(j=0;j<n;j++)
       {
           E[i][j] = 0;
           for(k=0;k<n;k++)
           {
               E[i][j] = E[i][j] + (A[i][k] * B[k][j]);
           }
       }
   }
   cout<<"------ After Matrix Addition -----\n";
   for(i=0;i<m;i++)
   {
       for(j=0;j<n;j++)
       {
           cout<<C[i][j]<<"\t";
       }
       cout<<"\n\n";
   }
   cout<<"------ After Matrix Subtraction -----\n";
   for(i=0;i<m;i++)
   {
       for(j=0;j<n;j++)
       {
           cout<<D[i][j]<<"\t";
       }
       cout<<"\n\n";
   }
   cout<<"------ After Matrix Multiplication -----\n";
   for(i=0;i<m;i++)
   {
       for(j=0;j<n;j++)
       {
           cout<<E[i][j]<<"\t";
       }
       cout<<"\n\n";
   }
    return 0;
}

