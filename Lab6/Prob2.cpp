#include <iostream>
using namespace std;

bool Priming(long long int numb, int temp = 2)
{
    if(temp<numb)
    {
        if(numb%temp==0) return 0;
        else return Priming(numb,temp+1);
    } return 1;
}

main()
{
    cout<<"Prime or not?  "<<Priming(1);
}

//Teacher's solution
/*
bool testPrime(int N,int i){
    if(i<2) return true;
    if (N%i==0) return false;
    return testPrime(N,i-1);
}
bool isPrime(int N){
if(N<2) return true;
return testPrime(N,(int)sqrt(N));
}

main(){
int N;
cin>>N;
cout<<(isPrime(N)? "TRUE":"FALSE")
}
*/
