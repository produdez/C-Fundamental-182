#include <iostream>
#define N 1024*243*7*7
using namespace std;

void Priming(long long int numb, int temp = 2)
{
        if (numb % temp == 0) {
                std::cout << temp << " ";
                Priming(numb / temp, temp);
        } else if (temp <= numb) {
                if(temp==2) Priming(numb, temp + 1);
                Priming(numb, temp + 2);
        }
}

main()
{
   cout<<"Prime elements of "<<N<<" are: ";
   Priming(N);
}
