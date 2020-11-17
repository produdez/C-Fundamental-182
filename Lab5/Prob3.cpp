
#include <iostream>
#include<random>
#include<time.h>
using namespace std;
main()
{
    int N,M;
    cout<<"Size of Matrix? AxB";
    cin>>N;
    cin>>M;
    int **tray;
    tray = new int*[N];
    *tray= new int[N*M];
    for (int i=0;i<N;i++)
        tray[i]=tray[0]+M*i;
 /*   int** tray = new int*[N];
if (N)
{
    tray[0] = new int[N * M];
    for (int i = 1; i < N; ++i)
        tray[i] = tray[0] + i * M;
} */

    srand(time(NULL));
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
        tray[i][j]= rand() %30;
        }
    }

    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
         cout<<tray[i][j]<<' ';
        }
        cout<<'\n';
    }
delete *tray;
delete tray;
}
