#include <iostream>
using namespace std;

template <typename T, int N>
class GoBoard
{
private:
    T** Board;
public:
    GoBoard();
    ~GoBoard();
    const T* operator[](int idx);
    T& operator=(const T& obj);
};

template <typename T,int N>
GoBoard<T,N>::GoBoard()
{
    T**a = new T*[N];
    for(int i=0;i<N;i++)
    {
        a[N]= new T[N];
    }
}
template <typename T,int N>
GoBoard<T,N>::~GoBoard()
{
    for(int i=0;i<N;i++)
    {
        delete(Board[i]);
    }
    delete Board;
}
template <typename T,int N>
const T* GoBoard<T,N>::operator[](int idx)
{
    return &Board[idx];
}
template <typename T,int N>
T& GoBoard<T,N>:: operator=(const T& obj)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            this->Board[i][j]=obj.Board[i][j];
        }
    }
}
//Main
int main()
{
    GoBoard<int,5> oldBoard;
    GoBoard<int,5> newBoard;
    newBoard= oldBoard;

}
