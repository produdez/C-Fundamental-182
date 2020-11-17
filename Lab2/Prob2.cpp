#include<iostream>
#include<iomanip>
using namespace std;
main()
{
    unsigned int n;
    cout<<"Input the size of the square in positive integer: ";
    cin>>n;

    char star='*';
    char space=' ';
if(n==1) cout<<star;
else{

    for (int x=0;x<n;x++) {cout<<star;} cout<<"\n";
    for (int x=0;x<(n-2);x++)
    {
        cout<<star<<setw(n-1)<<star<<"\n";
    }
    for (int x=0;x<n;x++) {cout<<star;} cout<<"\n";
}
}
