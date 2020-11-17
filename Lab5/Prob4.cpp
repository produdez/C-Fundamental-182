#include <iostream>
#include <iomanip>
#include <string>
int N;
char* surname (string* a)
{
    string* sur;
    sur = new string[N];
    return 'a';
}
char* name (string* a)
{

}
char* lastname (string* a)
{

}
void arr_cre ()
{
    cout<<"How many names?";
    cin>>N;
    string* a;
    a= new string[N];
    for (int i=0;i<N;i++)
    {
        cout<<i+1<<" name: ";
        cin>>a[i];
    }
    return a;
}

void main()
{
    arr_cre ();
}
