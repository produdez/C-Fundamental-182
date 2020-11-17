#include <fstream>
#include<iostream>
#include<iomanip>
#define Max_Size 100
using namespace std;
main()
{
int N;
cout<<"How big is your chess table?";
cin>>N;

int Table [Max_Size][Max_Size];
int a,b;

cout<<"Starting position (i,j)? :";
cin>>a>>b;
int x=a-1;
int y=b-1;
int moveX[]={2,1,-1,-2,-2,-1,1,2};
int moveY[]={1,2,2,1,-1,-2,-2,-1};

     for(int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
           if(i==(x)&&j==(y)) Table[i][j]=1;
           else Table[i][j]=0;
           cout<<setw(3)<<Table[i][j];
        }
        cout<<'\n';
    }


 int _x=0;
 int _y=0;
 int k=0;
 while(1)
    {

        for (; k<8;k++)
        {
            _x=x+moveX[k];
            _y=y+moveY[k];
            if (_x>-1&&_x<N&&_y>-1&&_y<N&&!Table[_x][_y]) break;
        }

        if(k<8)
        {
            Table[_x][_y]=Table[x][y]+1;
            x=_x;
            y=_y;
        }else break;

    }



    for(int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
           cout<<setw(3)<<Table[i][j];
        }
        cout<<'\n';
    }
}
