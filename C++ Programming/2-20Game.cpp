#include <iostream>
#include <string.h>
using namespace std;
int isWinNumber(int num)
{
    if (num == 2 || num == 5 || num == 8 || num == 11 || num == 14 || num == 17)
        return 1;
    return 0;
}
int iswin(int num)
{
    if (num == 20)
        return 1;
    return 0;
}
void MachineAttempt(int *curr)
{
    for (int i = 0; i < 2; i++)
    {
        cout << "Machine Said = " << ++(*curr) << "\n";
        if (iswin(*curr))
        {
            cout << " \t Machine Win \n";
            exit(0);
        }
        if (isWinNumber(*curr))
        {
            return;
        }
    }
}
void PersonAttempt(int *curr, string name)
{
    int a;
    cout << "Enter the numbers of attempt[1 or 2] = ";
    cin >> a;
    if (a > 2)
    {
        cout << "\t   !!!!! ERROR !!!!!   \t\n";
        exit(1);
    }
    for (int i = 0; i < a; i++)
    {
        cout << name << " Said = " << ++(*curr) << "\n";
        if (iswin(*curr))
        {
            cout << " \t " << name << " Win \n";
            exit(0);
        }
    }
}
void MachineFrist(string name)
{
    int curr = 0;
    while (1)
    {
        MachineAttempt(&curr);
        PersonAttempt(&curr, name);
    }
}
void PersonFrist(string name)
{
    int curr = 0;
    while (1)
    {
        PersonAttempt(&curr, name);
        MachineAttempt(&curr);
    }
}
int main()
{
    string name;
    cout << "Enter The Player Name = ";
    cin >> name;
    cout << "Enter Choice [ Machine Frist 1 or Player Frist = 2] = ";
    int ch;
    cin >> ch;
    if (ch == 1)
        MachineFrist(name);
    else if (ch == 2)
        PersonFrist(name);
    else
        cout << "\t Wrong Choice \n";
    return 0;
}
