#include<iostream>
#include<ctime>
#include<cstring>
#include<fstream>
using namespace std;
int main()
{
    ofstream f;
    f.open("C:\\Users\\USER\\Desktop\\test.txt");       // location of text file
    int k=0;
    cout<<"\t How many Medicine buy by the Customer = ";
    cin>>k;
    int i=0;
    long long m;
    float p[k],t,a;
    string n[k];
    string name;
    string ad;
    time_t my_time = time(NULL);


             cout<<"\n\n\t Fill-Up The Customer Deitails \n\n\n";

    cout<<"Enter the name of the Customer = ";
    cin>>name;
    cout<<"Enter the Age of the Customer = ";
    cin>>a;
    cout<<"Enter the mobile no of this Customer = ";
    cin>>m;
    cout<<"Enter the Address of this Customer = ";
    cin>>ad;

             cout<<"\n\n\t Fill-Up The Medicine Deitails \n\n\n";

    for(i=0;i<k;i++)
    {
        cout<<"Medicine No "<<i+1<<" = ";
        cin>>n[i];
        cout<<"Medicine price = ";
        cin>>p[i];
        cout<<"\n";
        t=t+p[i];
    }

    cout<<"\n\n\t Full Medicine Deitails \n\n\n";

    cout<<"Name = "<<name<<"\t"<<"Age = "<<a<<"\tMOB = "<<m<<"\t"<<"Address = "<<ad<<endl<<endl;

    cout<<"\t No      Medicine Name        Price\n\n";

    for(i=0;i<k;i++){

    cout<<"\t "<<i+1<<"\t"<<n[i]<<"\t\t"<<p[i]<<endl;

    }

    cout<<"\n\t\t\t\t\t Date = "<<ctime(&my_time)<<endl;

    cout<<"\n\t\t\a Total  = "<<t<<" Rs."<<"\n";


    char ch;
    float x,y=0;
    cout<<"\n If you have get Discount ? [Y/N]  = ";
    cin>>ch;
    cout<<"\n Percentage of Discount = ";
    cin>>x;

    if(ch=='Y'||ch=='y')
    {
        y = t - ( (x/100) * t );
    }
    else if(ch=='n'||ch=='N')
    {
        y=t;
    }
    else
    {
      cout<<"Wrong !!";
    }

    cout<<"\n\t\t ------------------------------------------------------------ ";
    cout<<"\n\t\t\t\a After Discount "<<x<<" % "<<" Total  = "<<y<<" Rs."<<"\n";
    cout<<"\t\t ------------------------------------------------------------ "<<"\n\n\n";


    // in file

    f<<"\t Medicine Deitails \n\n\n";

    f<<"Name = "<<name<<"\t"<<"Age = "<<a<<"\tMOB = "<<m<<"\t  "<<"Address = "<<ad<<endl<<endl;

    f<<"\t No       Medicine Name        Price\n\n";

    for(i=0;i<k;i++){

    f<<"\t "<<i+1<<"\t"<<n[i]<<"\t\t"<<p[i]<<endl;

    }

    f<<"\n\t\t\t\t\t Date = "<<ctime(&my_time)<<endl;

    f<<"\n\n\t\t\a Total  = "<<t<<" Rs."<<"\n";

    f<<"\n\n\t\t ------------------------------------------------------------ ";
    f<<"\n\t\t\t\a After Discount "<<x<<" % "<<" Total  = "<<y<<" Rs."<<"\n";
   f<<"\t\t ------------------------------------------------------------ "<<"\n\n\n";


    f.close();
    return 0;
}
