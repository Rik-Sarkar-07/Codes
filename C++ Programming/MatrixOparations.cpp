#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int n,m,k;

    int i,j;
    cout<<"-- Enter Rows and Culloms --\n";
    cin>>m;
    cin>>n;
    int m1[m][n],m2[m][n],m3[m][n],m4[m][n];
    cout<<"Enter First Matrix details \n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>m1[i][j];
        }
    }
    cout<<"Enter Second Matrix details \n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>m2[i][j];
        }
    }

    cout<<"Addition Result of those matrix -- \n\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
           m3[i][j]= m1[i][j] + m2[i][j];
           cout<<m3[i][j]<<"\t";
        }
        cout<<"\n";
    }

    cout<<"\n\nMultiplication Result of those matrix -- \n\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
           m4[i][j] = 0;
           for(k=0;k<m;k++)
           {
               m4[i][j] = m4[i][j] + m1[i][k]*m2[k][j];
           }
           cout<<m4[i][j]<<"\t";
        }
            cout<<endl;
    }


        cout<<"\n\n\n";

    return 0;
}
