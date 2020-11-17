#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cassert>

//#include "core.cpp"
using namespace std;
void read_input(const char* req );
int main()
{

    string req;
       while (true) {
        req = "";
        getline(cin, req);
        if (cin.bad()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
            cout<<"bad"<<endl;
        }
        if (req == "Exit") break;

        //implement
   read_input(req.data());

        //implement
    }

   /* void*   pData;
    void*   pOutput;
    int     N;
    LoadData("diabetes.csv",pData);
    ReleaseData(pData); */
    return 0;
}


void read_input(const char* req )
{
    cout<<strlen(req)<<endl;
    stringstream ss(req);
    string temp;
    while(ss>>temp)
    {
         if(temp=="CR")
         {
             //point output directly to recManager.N;
         }else if(temp=="DI")
         {

         }else if(temp=="HI")
         {

         }else if(temp=="FR")
         {

         }
    }

}
