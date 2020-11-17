//
// Created by Nguyen Duc Dung on 2019-04-20.
//

#include "core.h"

using namespace std;

int count_record(const char* pFName) // count number of record in data!
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
    return (n-2); // since there's first line and last empty line
}

void PrintOutput(const char* pRequest, void* pData, void* &pOutput, int N) {
    cout << pRequest << ":"; //print request
    //problem: this layout only print integer, we need float as well, for norm,...
    int*    pInt = (int*)pOutput; // dereference void pointer to output into int*
    for (int i = 0; i < N; ++i) {
        cout << ' ' << *pInt++; //print output
    }
    cout << '\n';
    delete[] pInt;
}

void Initialization() {
    // TODO: Implement the initialization
}

void Finalization() {
     NOTE: Any data that you allocated MUST BE CLEAN UP
}

void LoadData(const char* pFName, void* &pData) {

    RecManager* record_list=new RecManager; // create dynamic struct containing number of records and a pointer to record struct
    record_list->N= count_record(pFName);
    record_list->records= new Record[record_list->N]; // the pointer points to an dynamic array of record struct

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

    float* a = new float[9]; //released after this function

    //getting the order of data columns in case of column switch
    string temp;
    int order=0;
    while(true)
    {
        if(order<8) getline(input,temp,',');
        else getline(input,temp,'\n');
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
        if(order==9) break;
    }
/*
after the above loop, we have each slot of a[i] pointed to by our pointer, data is stored to a[] in order
and taken out unordered using our pointer
*/
    //reading and storing value for each record
    for(int record_index=0;record_index<record_list->N;record_index++) //or !input.eof()
    {
        order=0;
        getline(input,temp);

        stringstream ss(temp); //get line and translate that line in to input stream
        while(order<9) // load data into the a.array
        {
            ss>>a[order];
            ss.ignore(10,',');
            order++;
        }

        //move data from our a[] array to our struct using the pointers pointing to a[]

        record_list->records[record_index].glu=*glu;
        record_list->records[record_index].preg=*preg;
        record_list->records[record_index].blood=*blood;
        record_list->records[record_index].skin=*skin;
        record_list->records[record_index].insulin=*insulin;
        record_list->records[record_index].bmi=*bmi;
        record_list->records[record_index].dia=*dia;
        record_list->records[record_index].age=*age;
        record_list->records[record_index].outcome=*outcome;

    }


    delete[] a; //release a[]
    pData = record_list; // this is our public void pointer pointing to our object
    input.close();

    // TODO: Load the records from the given file.
}

void ReleaseData(void* &pData) { // Release records data only

    RecManager* record_list = static_cast<RecManager*>(pData);
    delete[] record_list->records;
    delete record_list;
    // TODO: Release any data that you loaded. Please remember that there
    //       MUST BE NO MEMORY LEAK in this program.
}

void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int& N) {

    stringstream ss(pRequest);
    string temp;
    ss>>temp;

    string info,col;
    float _min,_max,_step;


    if(temp=="CR")
    {
        CR(pData,pOutput,N);

    }else if(temp=="DI")
    {
        ss>>info>>col;
        DI(info,col_pointer(col,pData),pData,pOutput,N);

    }else if(temp=="HI")
    {
        ss>>col>>_min>>_max>>_step;
        HI(col_pointer(col,pData),_min,_max,_step,pData,pOutput,N); //implement
    }else if(temp=="FR")
    {
        if(ss>>col) // if input is more than just 'FR'
        {
            ss>>_min>>_max;
            FR(col_pointer(col,pData),_min,_max,pData,pOutput,N);//implement
        } else
        FR(pData,pOutput,N);
    }
    // TODO: Please implement this function to process requests from client.
}


float* col_pointer(std::string col,void* &pData) // will return a pointer depends on needed column
{
    RecManager* data=static_cast<RecManager*>(pData);
    if(col=="Pregnancies") return &(data->records[0].preg);
    if(col=="Glucose") return &(data->records[0].glu);
    if(col=="BloodPressure") return &(data->records[0].blood);
    if(col=="SkinThickness") return &(data->records[0].skin);
    if(col=="Insulin") return &(data->records[0].insulin);
    if(col=="BMI") return &(data->records[0].bmi);
    if(col=="DiabetesPedigreeFunction") return &(data->records[0].dia);
    if(col=="Age") return &(data->records[0].age);
    if(col=="Outcome") return &(data->records[0].outcome);
}

void CR(void* &pData,void* &pOutput,int &N) // count numbers of records
{
    RecManager* data=static_cast<RecManager*>(pData);
    int* a = new int[1]; //release later through pOutput
    a[0]= data->N;
    pOutput=a;
    N=1;
}
void DI(std::string info,float* col,void *& pData,void* &pOutput,int &N) //calculate needed value from a certain column
{
    RecManager* data=static_cast<RecManager*>(pData);
     int* a = new int[1]; //release later through pOutput
     float mean=0;
     float _min=col[0];
     float _max=col[0];
     if(info=="Mean")
     {
        for(int i=0;i<data->N;i++)
        {
            mean+= *(col+9*i);
        }
        mean/=data->N;
        a[0]= mean;
     }
     else if(info=="Min")
     {
        for(int i=1;i<data->N;i++)
        {
            _min=min(_min,*(col+9*i));
        }
        a[0]=_min;
     }
     else if(info=="Max")
     {
        for(int i=1;i<data->N;i++)
        {
            _max=max(_max,*(col+9*i));
        }
        a[0]=_max;
     }
     else if (info=="Standard-Deviation")
     {
         for(int i=0;i<data->N;i++)
        {
            mean+= *(col+9*i);
        }
        mean/=data->N;
         float deviation=0;
         for(int i=0;i<data->N;i++)
        {
           deviation+= pow(*(col+9*i)-mean,2);
        }
        deviation= sqrt(deviation/data->N);
        a[0]=deviation;
     }

     pOutput=a;
     N=1;
}
void HI(float* col,float _min,float _max, float _step,void*&pData,void* &pOutput,int &N)
{ // Calculate histogram of  a column
    RecManager* data=static_cast<RecManager*>(pData);
     N=ceil((_max-_min)/_step);
     int* a= new int[N]; //release later through pOutput
     memset(a, 0, N*sizeof(float));
     for(int i=0;i<data->N;i++)
     {
         if(*(col+9*i)>=_min&&*(col+9*i)<_max)
         {
             a[int((*(col+9*i)-_min)/_step)]++;
         }
     }
     pOutput=a;
}
void FR(float* col,float _min,float _max,void*& pData,void* &pOutput,int &N)
{ // return index of records depends on outcome and another column
     RecManager* data=static_cast<RecManager*>(pData);
     int counter=0;
     for(int i=0;i<data->N;i++)
     {
         if(data->records[i].outcome!=0&&*(col+9*i)>=_min&&*(col+9*i)<=_max)
         {
             counter++;         }
     }
     int* a= new int [counter];
     N=counter;
     counter=0;
     for(int i=0;i<data->N;i++)
     {
         if(data->records[i].outcome!=0&&*(col+9*i)>=_min&&*(col+9*i)<=_max)
         {
             a[counter]=i;
             counter++;
         }
     }
     pOutput=a;


}
void FR(void*&pData,void* &pOutput,int &N)
{ // return index of records depends on outcome only
    RecManager* data=static_cast<RecManager*>(pData);
     int counter=0;
     for(int i=0;i<data->N;i++)
     {
         if(data->records[i].outcome!=0)
         {
             counter++;
         }
     }
     int* a= new int [counter];
     N=counter;
     counter=0;
     for(int i=0;i<data->N;i++)
     {
         if((data->records[i].outcome)!=0)
         {
             a[counter]=i;
             counter++;
         }
     }
     pOutput=a;

}


