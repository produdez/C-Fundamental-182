#include <iostream>
#define N 5
using namespace std;

int factorial(int numb)
{
    if (numb==0) return 1;
    return numb*factorial(numb-1);
}
int fibonacci (int numb)
{
    if (numb<=1) return 1;
     //if (numb==1) return 1;
    return fibonacci(numb-1)+fibonacci(numb-2);

}

main()
{
    cout<<"Factorial of "<<N<<" is: "<<factorial(N)<<'\n';
   cout<<"The "<<N<<"'th member of the fibonacci sequence is:"<<fibonacci(N)<<'\n';
}
