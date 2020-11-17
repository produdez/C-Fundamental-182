#include <iostream>
#include<string>
#include<sstream>
#include<stdio.h>
using namespace std;
int main()
{
   int __userChoice;
  string __userChoice2;
      bool valid=false;
      bool space_front=true;
      bool space_back=true;

    while (!valid) //check user input until accepted our conditions
    {
        valid=true;


        cout<<"Please select: ";
       //getline(cin,__userChoice2);
        cin>> __userChoice2; //For storing the input as a string

      //  cout<<__userChoice2<<'\n';

        for(unsigned int x=0; x<__userChoice2.length();x++)  //Check string char by char to check for wrong input
    {

        if(cin) {valid=false; break;}
        if(__userChoice2[x]=='+' || __userChoice2[x]=='-'&& isdigit(__userChoice2[x+1])) continue;
        if(!isdigit(__userChoice2[x])) {valid = false; break;}

    }
    cout<<valid<<'\n'; //Valid check

        if(valid) //Transform the input from string to integer if the format is correct
        {
            stringstream __choice(__userChoice2);
            __choice>>__userChoice;



        }else
        {
            cout<<"Invalid input, please input an integer number.\n";
            cin.clear();
        cin.ignore(100000,'\n');
        }
    if ((__userChoice<1 || __userChoice>5)&&valid) //Check if choice is out of range
        {
			cout << "Please select a number from 1 to 5." << "\n";

			cin.clear();
        cin.ignore(100000,'\n');
			valid = false;
        }
    cout<<__userChoice<<'\n';
}
}
