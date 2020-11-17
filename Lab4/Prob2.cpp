#include <iostream>
#include <iomanip>
#define row 10
#define col 10
using namespace std;
main()
{
    int numbers[row][col]; //a

    for(int i=0;i<row;i++) //b
    {
        for(int j=0;j<col;j++)
        {
            cout<<"Input integer value for the slot ["<<i<<"]["<<j<<"]: ";
            cin>>numbers[i][j];
        }
    }

    int min;
    min=numbers[0][0];
    for(int i=0;i<row;i++) //c
    {
        for(int j=0;j<col;j++)
        {
            if(numbers[i][j]<min) min=numbers[i][j];
        }
    }
    cout<<"The smallest number in the array is: "<<min<<'\n';



    cout<<setfill('_')<<setw(5); //d
    for(int j=0;j<col;j++)
        {
            cout<<'|'<<setw(5)<<j+1;
        }
    cout<<'|'<<'\n';
    cout<<setfill(' ');
    for(int i=0;i<row;i++)
    {
        cout<<setw(2)<<i+1<<setw(3);
        for(int j=0;j<col;j++)
        {
            cout<<'|'<<setw(5)<<numbers[i][j];
        }
        cout<<'|'<<"\n";
    }
}
