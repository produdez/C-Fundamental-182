#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#define max_courses 100
#define max_records 100
#define course_num 3
#define re recordList
#define max_line 100
using namespace std;

struct student //Create the Structure
{
    string ID;
    string name;
    float courses[max_courses];
    float GPA;
};

int N;
student recordList[max_records];


void recordInput() //Read input from User
{


    cout<<"How many records would you like to input? ";
    cin>>N;
    cout<<"Input the data for "<<N<<" student records!\n";

    for(int i=0; i<N;i++)
    {
        cout<<"Student #"<<i+1<<'\n';
        cout<<"ID: "; cin>>re[i].ID;
        cout<<"name: "; cin>>re[i].name;
        for (int j=0;j<course_num;j++)
        {
            cout<<"Grade of course #"<<j+1<<' ';
            cin>>re[i].courses[j];
        }
        cout<<"GPA: "; cin>>re[i].GPA;
    }
}


void recordOutputtxt() // Out put to file txt
{
    ofstream data;
    data.open("StudentDB.txt",ofstream::out);
    data<<'|'<<setw(3)<<"ID"<<setw(6)<<'|'<<setw(4)<<"Name"<<setw(16)<<'|';
    for (int i=0;i<course_num;i++) data<<setw(5)<<'|';
    data<<setw(3)<<"GPA"<<setw(5)<<'|'<<'\n';



    for(int i=0;i<N;i++)
    {
    data<<'|'<<setw(8)<<re[i].ID<<'|'<<setw(19)<<re[i].name<<'|';
    data<<fixed<<setprecision(1);
    for (int j=0;j<course_num;j++) data<<setw(4)<<re[i].courses[j]<<'|';
    data<<setw(7)<<re[i].GPA<<'|'<<'\n';
    }
    data.close();
}


void recordOutputbat() //Output to file bat
{
    ofstream bat;
    bat.open("StudentDB.bat",ofstream::out);
    bat<<N<<'\n';
    bat<<'|'<<setw(3)<<"ID"<<setw(6)<<'|'<<setw(4)<<"Name"<<setw(16)<<'|';
    for (int i=0;i<course_num;i++) bat<<setw(5)<<'|';
    bat<<setw(3)<<"GPA"<<setw(5)<<'|'<<'\n';



    for(int i=0;i<N;i++)
    {
    bat<<'|'<<setw(8)<<re[i].ID<<'|'<<setw(19)<<re[i].name<<'|';
    bat<<fixed<<setprecision(1);
    for (int j=0;j<course_num;j++) bat<<setw(4)<<re[i].courses[j]<<'|';
    bat<<setw(7)<<re[i].GPA<<'|'<<'\n';
    }
    bat.close();
}

void batVerify() //Check if the information in bat file is correct!
{
    string data_line[max_line];
    string bat_line[max_line];
    int index1=0;
    int index2=0;
    int record_data;
    bool verify=1;
    ifstream data;
    ifstream bat;
    data.open("StudentDB.txt",ifstream::in);
    bat.open("StudentDB.bat",ifstream::in);
    while(!data.eof())
    {
        getline(data,data_line[index1]);
        index1++;
    }
    while(!bat.eof())
    {
        getline(bat,bat_line[index2]);
        index2++;
    }
    istringstream temp (bat_line[0]);
    temp>> record_data;
    if(record_data!=(index1-2)) verify=0;
    for(int k=1;k<index2;k++)
    {
        if(data_line[k-1].compare(bat_line[k])==0)
        {
			verify=0; break;
        }
    }

    if(verify==0) cout<<"Wrong information in the Bat file!"<<'\n';
    else cout<<"Data in Bat file written correctly!"<<'\n';

    data.close();
    bat.close();
}




main()
{
    //recordInput();
    //recordOutputtxt();
    //recordOutputbat();
    batVerify();

}
