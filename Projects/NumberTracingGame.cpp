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
    for (int i = 0; i < step; i++)
    {
        cout << "Machine Said = " << ++(*curr) << "\n";
        if (iswin(*curr,destination))
        {
            cout << " \t Machine Win \n";
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
    cout << "Enter the numbers of attempt[1 to "<<step<<"] = ";
    cin >> a;
    if (a > step)
    {
        cout << "\t   !!!!! ERROR !!!!!   \t\n";
        exit(1);
    }
    for (int i = 0; i < a; i++)
    {
        cout << name << " Said = " << ++(*curr) << "\n";
        if (iswin(*curr,destination))
        {
            cout << " \t " << name << " Win \n";
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
    cout << "Enter The Player Name = ";
    cin >> name;
    int step;
    int destination;
    cout<<"Enter the Destination point = ";
    cin>>destination;
    cout<<"Enter the At a time Step = ";
    cin>>step;
    int *arr = (int*)calloc(sizeof(int),(destination/(step+1)+1));
    ArrayInitilization(arr,step,destination);

    cout << "Enter Choice [ Machine Frist 1 or Player Frist = 2] = ";
    int ch;
    cin >> ch;
    if (ch == 1)
        MachineFrist(name,arr,step,destination);
    else if (ch == 2)
        PersonFrist(name,arr,step,destination);
    else
        cout << "\t Wrong Choice \n";
    return 0;
}
