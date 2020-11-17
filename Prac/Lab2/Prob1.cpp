#include <iostream>
using namespace std;

    long long int f_0=0;
    long long int f_1=1;
    long long int tmp;
main()
{
    cout<<"Fibonacci for how many numbers?? ";
    int n=0;
    cin>>n;
    if(n==0) cout<<"Set: "<<0;
    else if (n==1) cout<<"Set: "<<1;
    else if (n>1)
    for(int i=1;i<=n;i++)
    {
        tmp=f_0;
        f_0=f_1;
        f_1=f_1+tmp;
        cout <<" "<<tmp;
    }
}
