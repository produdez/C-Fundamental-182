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

struct Record {
    // TODO: Please define the detail struct for storing a record here
    float preg;
    float glu;
    float blood;
    float skin;
    float insulin;
    float bmi;
    float dia;
    float age;
    float outcome;
};

struct RecManager {
    // TODO: Please define the detail of this struct so that you can manage
    //       the records that you loaded from given the file. If you don't need
    //       such a struct, you can ignore or delete this one.
    int N; // number of records
    Record* records; //array of struct!

};

int count_record(const char* pFName) // count number of records in data!
{
    fstream input;
    int n=0;
    string temp;
    input.open(pFName,fstream::in);
    while(!input.eof())
    {
        getline(input,temp);
        n++;
    }
    input.close();
    return n-1;
}
void LoadData(const char* pFName, void* &pData);


int main()
{
void* pData;
RecManager record_list;
record_list.N=3;
record_list.records=new Record[3];

cout<<record_list.N<<endl;
record_list.records[0].dia=123;
cout<<record_list.records[0].dia<<endl;

LoadData("diabetes.csv",pData);


return 0;
}

void LoadData(const char* pFName, void* &pData) {

    // create static struct containing number of records and a pointer to record struct
    // the pointer points to an dynamic array of record struct

    RecManager record_list;
    record_list.N= count_record(pFName); // this is number of records
    record_list.records= new Record[record_list.N]; //pointer pointing to array of records

    fstream input;
    input.open(pFName,fstream::in);

    float* preg;
    float* glu;
    float* blood;
    float* skin;
    float* insulin;
    float* bmi;
    float* dia;
    float* age;
    float* outcome;

    float* a = new float[9]; //release a[] later

    //getting the order of data columns
    string temp;
    int order=0;

    while(true)
    {
        if(order<8) getline(input,temp,','); // problem, wont stop even when\n
        else getline(input,temp,'\n');
        cout<<temp<<endl;
        if (temp=="Pregnancies"){
            preg=&a[order];
        }
        if (temp=="Glucose"){
            glu=&a[order];
        }
        if(temp=="BloodPressure"){
            blood=&a[order];
        }
        if(temp=="SkinThickness"){
            skin=&a[order];
        }
        if(temp=="Insulin"){
            insulin=&a[order];
        }
        if(temp=="BMI"){
            bmi=&a[order];
        }
        if(temp=="DiabetesPedigreeFunction"){
            dia=&a[order];
        }
        if(temp=="Age"){
            age=&a[order];
        }
        if(temp=="Outcome"){
           outcome=&a[order];
        }

        order++;
        if(!(order<9)) break;
    }

/*
after the above loop, we have each slot of a[i] pointed to by our pointer, data is stored to a in order
and taken out unordered using our pointer
*/
    //reading and storing value until eof

    int record_index=-1;
    while(!input.eof()) // or while !input.eof()
    {
         record_index++;
        order=0;
        getline(input,temp); // get a line
        stringstream ss(temp);
        while(order<=8) // load data into the a.array
        {
            ss>>a[order]; // get a number
            ss.ignore(10,','); //ignore next ','
            order++;
        }
        //convert from a.array to our struct
        record_list.records[record_index].glu=*glu;
        record_list.records[record_index].preg=*preg;
        record_list.records[record_index].blood=*blood;
        record_list.records[record_index].skin=*skin;
        record_list.records[record_index].insulin=*insulin;
        record_list.records[record_index].bmi=*bmi;
        record_list.records[record_index].dia=*dia;
        record_list.records[record_index].age=*age;
        record_list.records[record_index].outcome=*outcome;

        cout<<record_list.records[record_index].glu<<endl;

    }

 delete[] a;

    cout<<"done"<<endl;

    input.close();
//    delete [] load->records;

    return; //done
    // TODO: Load the records from the given file. The name of data file
    //       is given in pFName. The data that you load into is pointed to
    //       by the pointer pData. You should make decision on what data
    //       type will be used to store records.
}
