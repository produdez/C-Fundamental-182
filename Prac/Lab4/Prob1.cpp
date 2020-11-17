#include <iostream>
#define maxLength 1000
using namespace std;

main()
{
    int n;
    int fullArray[maxLength];
    cout<<"how long is your array?";
    cin >>n;
    for (int i=0;i<n;i++)
    {
        cout<<"Input the "<<i+1<<" element ";
        cin>>fullArray[i];
    }
    for (int i=0;i<n;i++)
    {
        cout<<"  "<<fullArray[i];
    }
}
