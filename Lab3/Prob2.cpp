#include <fstream>
#include<iostream>

using namespace std;
main()
{
    ifstream input;
    input.open("output.txt",ifstream::in);
    int _Userchoice,_TestNum,Ans;
    Ans=0;
    cout<<"Input an integer from -20 to 80: ";
    cin>>_Userchoice;

    while(!input.eof())
    {
        input>>_TestNum;
        if(_TestNum==_Userchoice)
        {
             Ans=_TestNum;
             break;
        }

    }
    input.close();
    cout<<Ans;
}
