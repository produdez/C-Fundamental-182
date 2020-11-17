#include <iostream>
#include<iomanip>
#include<string>
using namespace std;
main()
{
    int N;
    cout<<"How big?\n";
    cin>>N;
   for (int i=0; i<N;i++)
   {
       cout<<setfill(' ')<<setw(N-i)<<'*';
       if(i==0)
       {
           //DO NOTHING
       } else if (i==(N/2))
       {
           cout<<setfill('*')<<setw(2*i+1);
       } else
       {
           cout<<setfill(' ')<<setw(2*i)<<'*';
       }

       cout<<'\n';

   }
}
