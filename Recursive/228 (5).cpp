#include <iostream>
#define N 5
using namespace std;


int fibonacci (int pos,int a=0,int b=1)
{

   if(pos==1)
   {
       cout<<a+b<<' ';
       return a+b;
   }

    cout<<a+b<<" ";
    return fibonacci(pos-1,b,a+b);

}

main()
{
    fibonacci(N);
}
