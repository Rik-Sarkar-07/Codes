#include <iostream>

using namespace std;

int main()
{
    int m[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int n[3][3] = {{7,4,1},{8,5,2},{9,6,3}};
    cout<<"----------Matrix 1-----------\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          cout<<m[i][j]<<"\t"; }
          cout<<endl;
    }
    cout<<"----------Matrix 2-----------\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          cout<<n[i][j]<<"\t"; }
          cout<<endl;
    }

    int add[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            add[i][j] = m[i][j] + n[i][j];
            
    int mul[3][3];
     for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            mul[i][j] = 0;
            
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                mul[i][j] += m[i][k]*n[j][k];
            
    cout<<"---------- Addition ----------\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          cout<<add[i][j]<<"\t"; }
          cout<<endl;
    }
    
    
    cout<<"---------- Multiplication ----------\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          cout<<mul[i][j]<<"\t"; }
          cout<<endl;
    }
    
    
    int t[3][3];
    cout<<"---------- Transpose Matrix ----------\n";
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            t[i][j] = mul[j][i];
          cout<<t[i][j]<<"\t"; }
          cout<<endl;
    }
    
    return 0;
}
