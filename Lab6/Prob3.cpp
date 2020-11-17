#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int rev(int n);

 int main()
 {
     cout<<rev(123456789);
 }

int rev(int n)
{
    if(n/10==0) return n;
    else return (n%10)*pow(10,floor(log10(n)))+rev(n/10);
}
