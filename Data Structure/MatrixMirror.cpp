#include<iostream>
using namespace std;
int main()
{
   int m;
   cout<<"Enter the numbers of row or colum [Both are same numbers] \n";
   cin>>m;
   int i,j;
   int A[m][m],B[m][m],C[m][m],D[m][m];
   cout<<"------ Enter Matrix's Elements -----\n";
   for(i=0;i<m;i++)
   {
       for(j=0;j<m;j++)
       {
           cin>>A[i][j];
       }
   }
   cout<<"------ The Matrix Is -----\n";
   for(i=0;i<m;i++)
   {
       for(j=0;j<m;j++)
       {
          cout<<"\t"<<A[i][j];
       }
       cout<<"\n\n";
   }

   cout<<"------ The Tranpose of that Matrix Is -----\n";
   for(i=0;i<m;i++)
   {
       for(j=0;j<m;j++)
       {
           B[i][j] = A[j][i];
          cout<<"\t"<<B[i][j];
       }
       cout<<"\n\n";
   }

   cout<<"------ Mirror Images Of The MATRIX [ ROWS ] ------"<<endl;
      for(i=0;i<m;i++)
      {
          for(j=0;j<m;j++)
          {
              C[i][j]=A[m-1-i][j];
          }
      }
      for(i=0;i<m;i++)
      {
          for(j=0;j<m;j++)
          {
              cout<<"\t"<<C[i][j];
          }
          cout<<"\n\n";
      }
      cout<<"------ MIRROR Images Of The MATRIX [ COLLMS ] ------"<<endl;
      for(i=0;i<m;i++)
      {
          for(j=0;j<m;j++)
          {
              D[i][j]=A[i][m-1-j];
          }
      }
      for(i=0;i<m;i++)
      {
          for(j=0;j<m;j++)
          {
              cout<<"\t"<<D[i][j];
          }
          cout<<"\n\n";
      }
    return 0;
}

