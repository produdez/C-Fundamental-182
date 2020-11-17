#include <iostream>
using namespace std;

int findNum(int*pD,int nE,int N,int dex=0);
int findNum2(int*pD,int nE,int N);
int findNum3(int*pD,int nE,int N);

int main(){
    int*a;
    int N;
    cout<<"Size of array>? ";
    cin>>N;


    a=new int[N];
    for(int i=0;i<N;i++)
    {
        a[i]=i;
        cout<<a[i]<<' ';
    } cout<<endl;


    cout<<"Number to find?";
    int number;
    cin>>number;
    cout<<findNum3(a,N,number);


}


int findNum(int*pD,int nE,int N,int dex)
{
    if(dex>=nE) return -1;
    if(*pD==N) return dex+1;
    return findNum(pD+1,nE,N,dex+1);
}

int findNum2(int*pD,int nE,int N)
{
    if((nE-1)<0) return -1;
    if(pD[nE-1]==N) return nE-1;
    return findNum2(pD,nE-1,N);
}

int findNum3(int*pD,int nE,int N) // chia đôi aray rồi làm tiếp
{
    cout<<*pD<<' '<<pD[nE/2]<<'-'<<nE<<' '<<pD[nE-1]<<endl;

    if(pD[nE/2]==N) return nE/2;
    if(nE/2==0) return -1;
    if(N<pD[nE/2]) return nE-findNum3(pD,nE/2,N); //not good yet!! only print last index in last array
    else if (N>pD[nE/2]) return nE-findNum3(pD+(nE/2)+2,nE-(nE/2)-1,N);

}
