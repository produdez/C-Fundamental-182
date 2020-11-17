#include <iostream>
#include<string>
using namespace std;

bool running=0;
int userChoice;




void loadMenu()
{

   cout<<"1.Help"<<'\n';
   cout<<"2.Print record"<<'\n';
   cout<<"3.Exit"<<'\n';

}


void userInput()
{

    cin>>userChoice;
   while(!cin||userChoice<1||userChoice>3)
   {
       cout<<"I do not understand the input. Please input a valid request."<<'\n';
       cin.clear();
       cin.ignore(1000,'\n');
       loadMenu();
       cin>>userChoice;
   }
}


void process()
{
    string ID;
    switch(userChoice){
    case(1): cout<<"Here is some help instructions"<<'\n';
            cout<<"...\n";
            break;
    case(2):cout<<"Please tell me the ID of record ";
            cin>>ID;
            cout<<"Here is the record #"<<ID<<'\n';
            break;
    case(3): cout<<"Exiting...\n";
            running=0;
            break;
    }
}

main()
{
    running=1;

    while(running==1)
    {
        cout<<"Hello, please select a request"<<'\n';
        loadMenu();
        userInput();
        process();
    }
}
