#include <iostream>
#include <algorithm>
#include <cmath>

bool isSafe(int* pB,int N,int row,int col){
    for(int i=0;i<row;i++){
        if(col==pB[i]||abs(col-pB[i])==row-i) return false;
    }
}

bool putQ(int* pB,int N,int row){
    if (row==N) return true;
    for (int i=0;i<N;i++){
        if (isSafe(pB,N,row,i)){
            pB(row)=i;
            if(putQ(pB,N,row+1)) return true;
        }
    }
    return false;
}
void printBoard(int*pB,int N)
{
    for(int i=0;i<N;i++)
    {
        cout<<setw(5)<<pB[i];
    } cout<<endl;
}

int main(){
int N ;
cin>>N;
int* pB = new int [N];
for(int i=0;i<N;i++) pB[i]=-1;

if(putQ(pB,N,0)){
    printBoard(pB,N);
}
}
