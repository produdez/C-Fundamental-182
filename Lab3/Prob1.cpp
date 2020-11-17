#include <fstream>
#include<iostream>
#include<random>
#include<time.h>
#include<iomanip>
#define row 40
#define col 40
using namespace std;
main()
{
    int Table [row][col];
    srand(time(NULL));
    ofstream out ;
    out.open("output.txt",ofstream::out);
    for(int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
           Table[i][j]=rand()%100-20;
        out<<setw(5)<<Table[i][j];
        }
        out<<'\n';
    }
    cout<<"Output written!";
    out.close();
}
