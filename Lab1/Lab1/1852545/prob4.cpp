#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream fl;
    string s;
    fl.open("in.txt",std::fstream::in);
    getline(fl,s);
    cout <<s<<"\n";
    getline(fl,s);
    cout <<s<<"\n";
    getline(fl,s);
    cout<<s<<"\n";

    fl.seekp(-3,ios_base::end);
    cout<<(char)fl.get();
    cout<<(char)fl.get();
    cout<<(char)fl.get()<<"\n";

    fstream fe;
    fe.open("out.txt",std::fstream::out);


    fl.seekp(0,ios::beg);
    getline(fl,s);
    getline(fl,s); //line 2
    fe<< s<<"\n";
    getline(fl,s);
    getline(fl,s); //line 4
    fe<< s<<"\n";
    getline(fl,s);
    getline(fl,s);
    getline(fl,s); //line 7
    fe<< s<<"\n";

cout<< "Insert some text and a float number!:";
string a;
float b;
cin>>a>>b;
fe<<a<<"\n";
fe<<b<<"\n";

    fe.close();
    fl.close();

}
