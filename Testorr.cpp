#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    fstream input;
    input.open("new.txt",ifstream::in);
    string ss;
    float fuck;
    getline(input,ss);
    for(int i=0;i<4;i++) //each record
    {
        for(int j=0;j<8;j++) // each attribute
        {
            input>>fuck;
            input.ignore(1);
            cout<<fuck<<' ';
        }
    }
}
  //  == != > < >= <=
    // compare 3 numbers that are user input and print all cases?
    // take user input 3 numbers
    // check for all cases
    // print the info of those cases
    /*
    int a,b;
    cout<<"Two numbers a,b needed:";
    cin>>a>>b;
    if(a>b || && ) cout<< "a>b";
    else if(a==b) cout<<"a=b";
    else cout<<"a<b";
        */
