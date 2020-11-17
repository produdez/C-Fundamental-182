#include <iostream>
using namespace std;

//Class declaration

class libraryBook
{
protected:
    string title;
    string author;
    int refTimes;
public:
    virtual void input();
    virtual void output();
};
class news: public libraryBook
{
    string publisher;
    int ID;
public:
    void input();
    void output();
};

//Main
int main()
{
    libraryBook* ptr = new news;
    ptr->input();
    ptr->output();
    return 0;
}
// Class implementation

void libraryBook::input()
{
    cout<<"Tittle: ";
    cin>>title;
    cout<<"Author: ";
    cin>>author;
    cout<<"Reference Times: ";
    cin>>refTimes;
}
void libraryBook::output()
{
    cout<<"Tittle: "<<title<<endl;
    cout<<"Author: "<<author<<endl;
    cout<<"Reference Times: "<<refTimes<<endl;
}
void news::input()
{
    libraryBook::input();
    cout<<"Publisher: ";
    cin>>publisher;
    cout<<"ID: ";
    cin>>ID;
}
void news::output()
{
    libraryBook::output(); // this can even access private shits!
//    cout<<"Tittle: "<<title<<endl;
//    cout<<"Author: "<<author<<endl;
//    cout<<"Reference Times: "<<refTimes<<endl;
    cout<<"Publisher: "<<publisher<<endl;
    cout<<"ID: "<<ID<<endl;
}
