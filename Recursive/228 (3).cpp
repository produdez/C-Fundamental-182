#include <iostream>
#define A 5
#define B 10
using namespace std;

int fuct(int a,int b)
{
    if (a==0) return b;
    return fuct(a-1,b+1);
}

main()
{
    cout<<"Result of function with a="<<A<<" and b="<<B<<" is: "<<fuct(A,B)<<'\n';

}
