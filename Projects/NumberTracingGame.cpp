#include <iostream>
#include <string.h>
using namespace std;
int isWinNumber(int arr[],int destination,int step,int num)
{
    for(int i=0;i<destination/(step+1) + 1;i++)
        if(num == arr[i])
            return 1;
    return 0;
}
int iswin(int num,int destination)
{
    if (num == destination)
        return 1;
    return 0;
}
void MachineAttempt(int *curr,int arr[],int step,int destination)
{
    cout<<"\n\t---- MACHINE ----\t\n";
    for (int i = 0; i < step; i++)
    {
        cout << "Machine Said = " << ++(*curr) << "\n";
        if (iswin(*curr,destination))
        {
            cout << " \n\n\n\t\t =-_-_-=[ M-A-C-H-I-N-E  W_I_N ]=-_-_-= \n\n\n\a";
            exit(0);
        }
        if (isWinNumber(arr,destination,step,*curr))
        {
            return;
        }
    }
}
void PersonAttempt(int *curr,int destination,int step, string name)
{
    int a;
    cout << "Enter The Numbers Of Attempt[1 to "<<step<<"] = ";
    cin >> a;
    if (a > step)
    {
        cout << "\t   !!!!! ERROR !!!!!   \t\n";
        exit(1);
    }
     cout<<"\n\t---- "<<name<<" ----\t\n";
    for (int i = 0; i < a; i++)
    {
        cout << name << " Said = " << ++(*curr) << "\n";
        if (iswin(*curr,destination))
        {
            cout << " \n\n\n\t\t =-_-_-= [" << name << " W_I_N] =-_-_-=\n\n\n\a";
            exit(0);
        }
    }
}
void MachineFrist(string name,int arr[],int step,int destination)
{
    int curr = 0;
    while (1)
    {
        MachineAttempt(&curr,arr,step,destination);
        PersonAttempt(&curr,destination,step,name);
    }
}
void PersonFrist(string name,int arr[],int step,int destination)
{
    int curr = 0;
    while (1)
    {
        PersonAttempt(&curr,destination,step,name);
        MachineAttempt(&curr,arr,step,destination);
    }
}
void ArrayInitilization(int arr[],int step,int destination)
{
    int i=0,j=0;
    j = destination-(step+1);
    for(i=0;i<destination/(step+1)+1;i++){

        arr[i] = j;
        j = j - (step+1);
        if(j<0)
            return;
    }
}
int main()
{

    string name;
    cout << "\t\t\tEnter The Player Name = ";
    cin>>name;
    int step;
    int destination;
    cout<<"\t\t\tEnter The Destination Point = ";
    cin>>destination;
    cout<<"\t\t\tEnter The At-A-Time Steps = ";
    cin>>step;
    int *arr = (int*)calloc(sizeof(int),(destination/(step+1)+1));
    ArrayInitilization(arr,step,destination);

    cout << "\t\t\tEnter Choice [1 ~ for Machine Frist || 2 ~ for Player Frist] = ";
    int ch;
    cin >> ch;
    if (ch == 1)
        MachineFrist(name,arr,step,destination);
    else if (ch == 2)
        PersonFrist(name,arr,step,destination);
    else
        cout << "\t Wrong Choice \n";
    cout<<"\n\n\n\a";
    return 0;
}
