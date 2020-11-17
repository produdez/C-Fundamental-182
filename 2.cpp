#include<iostream>
#include "Testorr.cpp"
#include<stdio.h>
#include<cstring>
using namespace std;


struct subject
{
    int id;
    string name;
};
struct student
{
    int MS;
    string name;
    static int numberOfsub;
    subject* subList = new subject[numberOfsub];
};
int student::numberOfsub=3;
 int main(){
     student listS[300];
     for(int i=0;i<300;i++)
     {
         cout<<"input "<<i;
         cin>>listS[i].MS;
         cin>>listS[i].name;
         for(int j=0;j<listS[i].numberOfsub;j++)
         {
             cout<<"subject "<<j;
             cin>>listS[i].subList[j].id;
             cin>>listS[i].subList[j].name;
         }

     }

 }
