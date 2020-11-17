#include<fstream>
#include<iostream>
#define row 40
#define col 40
using namespace std;
main()
{
    ifstream input;
    input.open("output.txt",ifstream::in);
    int __DiagPos=0;
    int sum,Number;
    for(int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            input>>Number;
            if(j==__DiagPos) {sum=sum+Number;}
        }
        __DiagPos++;
    }
    cout<<"The sum of all numbers in the main diagonal is:"<<sum;
    input.close();
}
