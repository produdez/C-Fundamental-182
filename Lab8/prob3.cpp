#include <iostream>
#include<stdlib.h>
using namespace std;

template <typename T>
class MyArray
{
private:
T*ptr;
int size;
public:
MyArray();
MyArray(int);
~MyArray();
int getSize() const;
T &operator[](int);
};

template <typename T>
MyArray<T>::MyArray()
{
ptr = NULL;
size = 0;
}

template <typename T>
MyArray<T>::MyArray(int size)
{
ptr = new T[int(size)];
this->size = size;
}

template <typename T>
MyArray<T>::~MyArray()
{
if (ptr != NULL)
delete[] ptr;
}

template <typename T>
int MyArray<T>::getSize() const
{
return size;
}

template <typename T>
T &MyArray<T>::operator[](int subscript)
{
if (subscript < 0 || subscript >= size)
{
cout << "\nError: Subscript out of range" << endl;
exit(1); // terminate program; subscript out of range
}
return ptr[subscript];
} //


int main()
{
    MyArray<int> a;
    MyArray<int> b(2);
    MyArray<float> c(5);
    cout<<"Sizes: "<<a.getSize()<<' '<<b.getSize()<<endl;


    cout<<"b[] elements: ";
    for(int i=0;i<b.getSize();i++)
    {
        b[i]=i;
        cout<<b[i]<<' ';
    } cout<<endl;

    cout<<"c[] elements: ";
    for(int i=0;i<b.getSize();i++)
    {
        c[i]=i+0.5f;
        cout<<c[i]<<' ';
    } cout<<endl;
    return 0;
}
