#include <iostream>
#include<random>
#include<time.h>
using namespace std;
main()
{
    int N;
    cout<<"Size of array? ";
    cin>>N;
    int *tray;
    tray = new int[N];

    srand(time(NULL));
    for (int i=0;i<N;i++)
    {
        tray[i]= rand() %100;
         cout<<tray[i]<<' ';

    }
delete[] tray;
}
