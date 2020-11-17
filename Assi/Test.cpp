#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
main(){

ifstream data;

string line,output;
char keyword='"';
//array<string> welcome[9];
string welcome[15];
string menu[10];
string info[10];
int i=0,j=0,k=0;
int pos1,pos2;

data.open("conf.json",ifstream::in);
while(!data.eof()){
    getline(data,line);
    /*size_t pos1 = line.find(keyword)+1;
    size_t pos2= line.find(keyword,pos1)+1;
    size_t pos3 = line.find(keyword,pos2)+1;
    size_t pos4 = line.find(keyword,pos3);*/
    //if(pos1!=string::npos&&pos2!=string::npos&&pos3!=string::npos&&pos4!=string::npos)
    //{
        size_t found_line = line.find("line");
       // size_t found_opt= line.find("opt");
        if (found_line!=string::npos)
        {
            //welcome[i]=line.substr(pos3,pos4-pos3);
            //i++;
            k=0;
            for (int x=0;line[x]!='\0';x++)
            {
                if(line[x]=='"')
                {
                    k++;
                    if (k==3) pos1=x;
                    else if (k==4) pos2=x;
                }
            }
            welcome[i]=line.substr(pos1+1,pos2-pos1-1);
            i++;
        } /*else if (found_opt!=string::npos)
        {
            menu[j]=line.substr(pos3,pos4-pos3);
            j++;
        }else
        {
            info[k]=line.substr(pos3,pos4-pos3);
            k++;
        }*/
    //}
}
for (int x=0;welcome[x]!=welcome[x+1];x++)
    cout << welcome[x]<<"\n";
/*for (int x=0;menu[x]!=menu[x+1];x++)
    cout << menu[x]<<"\n";
for (int x=0;info[x]!=info[x+1];x++)
    cout << info[x]<<"\n";*/
data.close();

}
