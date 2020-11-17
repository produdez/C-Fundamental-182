#include <iostream>
#include "Setup.h"
using namespace std;

int main()
{
    NewGame:

    reset();
    printBoard();

    Player winner=NoWin;
    do
    {

        tactoe();
        winner= winnerCheck();
        printBoard();
    }
    while (winner == NoWin);

    if(winner==P1) cout<<"PLAYER ONE WINS!!! CONGRATS"<<endl;
    else cout<<"PLAYER TWO WINS!!! CONGRATS"<<endl;

    cout<<"Do you want to restart? Y/N:";

    string restart="Y";
    while(1)
    {
        if(!(cin>>restart))
        {
            cout<<"Wrong input!"<<endl;
            cin.clear();
            cin.ignore(10000,'\n');
        }else if(restart !="Y" && restart !="N")
        {
            cout<<"Y or N only!"<<endl;
        }else break;

    }

    if(restart=="Y")
    goto NewGame;
    else
        cout<<"EndGame!!!"<<endl;
}
