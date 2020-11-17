#include <iostream>
using namespace std;

void print_down(int n);

main()
{
    print_down(1);

}

void print_down(int n)
{
    cout<<n<<endl;
    if(n==0) return;
    print_down(n-1);
}
