#include <iostream>
#include <vector>
using namespace std;
void PrintVector(vector<int> &v)    // Reference 
{
    if(v.empty())
    {
        cout<<"Vector is Empty\n";
        return;
    }
    cout<<"\t The Vector is --- \n";
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<"\t";
    cout<<"\n\n";
}
int main(int argc, char const *argv[])
{
    vector<int> v;                          //  it is like Dynamic Array

    vector<int> v1(10, -1);                  // size is 10 that is also growable and initialize with -1

    for (int i = 0; i < 10; i++)
        v.push_back(i);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\t";
    cout << endl;

    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << "\t";
    cout << endl;

    v.pop_back();               // Delete at end
    v.pop_back();
    v.pop_back();

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\t";
    cout << endl;

    v1.resize(20);                      // size now 20
    cout << "Size  = " << v1.size() << endl;

    v.erase(v.begin());               // Delete  frist element
    v.erase(v.end() - 1);            // Delete last element
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\t";
    cout << endl;


    for(auto x : v)     //  using for each loop
    cout<<x<<"\t";
    cout<<endl;

    v.clear();      // Delete All elements in vector

    PrintVector(v);



    v.push_back(10);
    v.push_back(91);
    v.push_back(30);
    v.push_back(34);
    v.push_back(31);
    v.push_back(21);
    cout<<"Size of v Vector = "<<v.size()<<endl;

    PrintVector(v);

    // cout<<"Enter the index value which can be deleted[0 based indexing] = ";
    // int i=0;
    // cin>>i;
    // v.erase(v.begin() + i);
    // cout<<"After Delete --\n";
    // PrintVector(v);


    cout<<"Enter the index value which can be inserted 12 [0 based indexing] = ";
    int i=0;
    cin>>i;
    v.insert(v.begin() + i,12);
    cout<<"After Delete --\n";
    PrintVector(v);

   // reserve(v.begin(),v.end()-1);
   // PrintVector(v);

    // sort(v.begin(),v.end());

    PrintVector(v);

    return 0;
}
