#include <iostream>
#include <iomanip>
using namespace std;


enum Stone
{
    Black=-1,
    White=1,
    None=0
};
enum Rank
{
    Beginner=9,
    Casual=11,
    Inter=15,
    Advanced=19,
    Prof=19
};
struct player
{
    Rank level;
};
struct GoBoard
{
    int** theBoard;
    int boardSize;
    player p1;
    Stone s1;
    player p2;
    Stone s2;
    bool turn;

};
GoBoard* makeGame(player a,player b)
{
    int n= max(a.level,b.level);
    GoBoard* board= new GoBoard;

    board->boardSize=n;
    cout<<"The size: "<<n<<" * "<<n<<endl;

    board->theBoard= new int*[n];
    for(int i=0;i<n;i++)
    {
        (board->theBoard)[i]= new int[n];
        for(int j=0;j<n;j++)
        {
            board->theBoard[i][j]=None;
        }
    }

    board->p1=a;
    board->s1= White;
    board->p2=b;
    board->s2=Black;
    board->turn=0;
    return board;

}
void deleteGame(GoBoard*& game)
{
    for(int i=0;i<game->boardSize;i++)
    {
        delete(game->theBoard[i]);
    }
    delete game->theBoard;
    delete game;
}
void printBoard(GoBoard* game)
{
    for(int i=0;i<game->boardSize;i++)
    {
        for(int j=0;j<game->boardSize;j++)
        {
            cout<<setw(3)<<game->theBoard[i][j];
        }
        cout<<endl;
    }
}
bool put(GoBoard* pB,int x,int y)
{
    Stone check;
    if(pB->turn==0) check=Black;
    else check= White;

    if(pB->theBoard[x][y]!=None) return 0;
    if(pB->theBoard[x+1][y]==check&&pB->theBoard[x-1][y]==check&&pB->theBoard[x][y+1]==check&&pB->theBoard[x][y-1]==check) return 0;
    if(pB->turn==0) //white turn
    {
        pB->theBoard[x][y]= White;
    }
    else pB->theBoard[x][y]=Black;

    pB->turn= !pB->turn;
}
int main()
{
    player p1; p1.level=Beginner;
    player p2; p2.level= Casual;
    GoBoard* ourGame;
    ourGame= makeGame(p1,p2);
    put(ourGame,2,5);
    put(ourGame,3,6);
    put(ourGame,1,1);
    put(ourGame,2,2);
    put(ourGame,2,2);
    printBoard(ourGame);
    deleteGame(ourGame);
    return 0;
}
