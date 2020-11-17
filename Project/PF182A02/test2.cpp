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

#include "core.cpp"
using namespace std;
void read_input(const char* req );
float* col_pointer_old(string col,RecManager* data);
void print_the_shit(float* col,RecManager* data);
int main()
{
    /*
    void* pData;
    void* pOutput;
    int N;
    LoadData("diabetes.csv",pData);

    string ss;
    cin>>ss;
    RecManager* data= static_cast<RecManager*>(pData);
    print_the_shit(col_pointer(ss,data),data);
    */

/** HOW to manage data!!!


    float* preg= &(data->records[0].blood);
    for(int i=0;i<data->N;i++)
    {
        cout<<*(preg+9*i)<<endl;
    }

*/

//cout<<count_record("diabetes.csv")<<endl;

   void*   pData;
    void*   pOutput;
    int     N;
    LoadData("diabetes.csv",pData);
    RecManager* data= static_cast<RecManager*>(pData);
    print_the_shit(col_pointer_old("Pregnancies",data),data);
    ReleaseData(pData);
    return 0;

}
void print_the_shit(float* col,RecManager* data)
{
    for(int i=0;i<data->N;i++)
    {
        cout<<*(col+9*i)<<endl;
    }
}
float* col_pointer_old(string col,RecManager* data)
{
    if(col=="Pregnancies") return &(data->records[0].preg);
    if(col=="Glucose") return &(data->records[0].glu);
    if(col=="BloodPressure") return &(data->records[0].blood);
    if(col=="SkinThickness") return &(data->records[0].skin);
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
