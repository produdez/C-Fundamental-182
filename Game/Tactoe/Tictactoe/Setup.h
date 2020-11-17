#ifndef SETUP_H_INCLUDED
#define SETUP_H_INCLUDED

#include <iostream>
#include <iomanip>
using namespace std;


enum Player {P1=1,P2=-1,NoWin=0};
enum State {X='X',O='O',None='N'};

Player board[3][3]={NoWin};
Player turn;

void printBoard()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            char currentState;
            if(board[i][j]==NoWin) currentState=None;
            else if(board[i][j]==P1) currentState=X;
            else currentState=O;
            cout<<setw(4)<<currentState;//board[i][j];
        }
        cout<<endl;
    }
}
Player winnerCheck()
{
    int diag1=0;
    int diag2=0;
    for(int i=0;i<3;i++)
    {
        //row check
        if(board[i][0]==P1 && board[i][1]==P1 && board[i][2]==P1) return P1;
        if(board[i][0]==P2 && board[i][1]==P2 && board[i][2]==P2) return P2;
        //coll check
        if(board[0][i]==P1 && board[1][i]==P1 && board[2][i]==P1) return P1;
        if(board[0][i]==P2 && board[1][i]==P2 && board[2][i]==P2) return P2;
        //diag check
        diag1+=board[i][i];
        diag2+=board[i][2-i];
    }
    if(diag1==P1*3) return P1;
    if(diag2==P1*3) return P2;
    return NoWin;
}
int* takeCoord()
{
    int* a= new int[2];
    while(1)
    {
        if(cin>>a[0]&&cin>>a[1]){}
        else
        {
            cin.clear();
            cin.ignore(1000000,'\n');
            cout<<"Wrong format, choose again!"<<endl;
            continue;
        }
        if(a[0]>2 || a[0]<0 || a[1] >2 || a[1]<0)
        {
            cin.clear();
            cout<<"Numbers from 0 to 2 please!"<<endl;
        }else
        break;
    }
    return a;
}
void tactoe()
{
    if(turn==P1)
    cout<<"Player 1 choose move [a,b]: ";
    else
    cout<<"Player 2 choose move [a,b]: ";

    int* mov=takeCoord();
    board[mov[0]][mov[1]]=turn;
    turn=(turn==P1)?P2:P1;
}
void reset()
{
    turn=P1;
    std::fill((char*)board, (char*)board + 9, NoWin);
    cout<<"Let's Play tic-tac-toe <3"<<endl;
}
#endif // SETUP_H_INCLUDED
