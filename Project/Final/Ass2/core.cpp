//
// Created by Nguyen Duc Dung on 2019-04-20.
//

#include "core.h"

using namespace std;

//void writeToFile(void* pData, const char* fileName)
//{
//    fstream output;
//    output.open(fileName,fstream::out);
//
//    RecManager* recordList=static_cast<RecManager*>(pData);
//    for(int i=0;i<recordList->N;i++)
//    {
//        for(int j=0;j<9;j++)
//        {
//            output<<recordList->records[i].data[j]<<' ';
//        }
//        output<<endl;
//    }
//}
//void printAllData(void*pData) // correct
//{
//    RecManager* recordList=static_cast<RecManager*>(pData);
//    for(int i=0;i<recordList->N;i++)
//    {
//        for(int j=0;j<9;j++)
//        {
//            std::cout<<recordList->records[i].data[j]<<' ';
//        }
//        std::cout<<std::endl;
//    }
//}
int count_record(const char* pFName) // count number of record in data! //correct
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
    cout << pRequest << ":";
    if (pOutput == nullptr) {
        cout << " error\n";
        return;
    }
    int*    pInt = (int*)pOutput;
    for (int i = 0; i < N; ++i) {
        cout << ' ' << *pInt++;
    }
    cout << '\n';
}

void Initialization() {
    // TODO: Implement the initialization
}

void Finalization() {
    // NOTE: Any data that you allocated MUST BE CLEAN UP
}

void LoadData(const char* pFName, void* &pData) { //correct

    RecManager* record_list=new RecManager;
    record_list->N= count_record(pFName);
    record_list->records= new Record[record_list->N];

    fstream input;
    input.open(pFName,fstream::in);

    string ss;
    getline(input,ss); // skip first line
    double temp;

    for(int i=0;i<record_list->N;i++) //each record
    {
        for(int j=0;j<9;j++) // each attribute
        {
            input>>temp;
            record_list->records[i].data[j]=temp;
            input.ignore(1);
        }
    }
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

void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int& N) { //seems okay

    N=0;
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
        DI(info,col_pointer(col),pData,pOutput,N);

    }else if(temp=="HI")
    {
        ss>>col>>_min>>_max>>_step;
        HI(col_pointer(col),_min,_max,_step,pData,pOutput,N);
    }else if(temp=="FR")
    {
        if(ss>>col) // if input is more than just 'FR'
        {
            ss>>_min>>_max;
            FR(col_pointer(col),_min,_max,pData,pOutput,N);
        } else
        FR(pData,pOutput,N);
    }
    // TODO: Please implement this function to process requests from client.
}


int col_pointer(std::string col) // will return the column number depends on needed column
{ //correct
    if(col=="Pregnancies") return 0;
    if(col=="Glucose") return 1;
    if(col=="BloodPressure") return 2;
    if(col=="SkinThickness") return 3;
    if(col=="Insulin") return 4;
    if(col=="BMI") return 5;
    if(col=="DiabetesPedigreeFunction") return 6;
    if(col=="Age") return 7;
    if(col=="Outcome") return 8;
    return -1;
}

void CR(void* &pData,void* &pOutput,int &N) // count numbers of records //correct
{
    RecManager* recordList=static_cast<RecManager*>(pData);
    int* a = new int(); //release later through pOutput
    a[0]= recordList->N;
    pOutput=a;
    N=1;
}
void DI(std::string info,int col,void *& pData,void* &pOutput,int &N) //calculate needed value from a certain column
{// correct
    RecManager* recordList=static_cast<RecManager*>(pData);
    float* a = new float(); //release later through pOutput
     float mean=0;
     float _min=recordList->records[0].data[col];
     float _max=recordList->records[0].data[col];
     if(info=="Mean")
     {
        for(int i=0;i<recordList->N;i++)
        {
            mean+= recordList->records[i].data[col];
        }
        mean/=recordList->N;
        *a= mean;
     }
     else if(info=="Min")
     {
        for(int i=1;i<recordList->N;i++)
        {
            _min=min(_min,recordList->records[i].data[col]);
        }
        *a=_min;
     }
     else if(info=="Max")
     {
        for(int i=1;i<recordList->N;i++)
        {
            _max=max(_max,recordList->records[i].data[col]);
        }
        *a=_max;
     }
     else if (info=="StandardDeviation")
     {
         for(int i=0;i<recordList->N;i++)
        {
            mean+= recordList->records[i].data[col];
        }
        mean/=recordList->N;
         float deviation=0;
         for(int i=0;i<recordList->N;i++)
        {
           deviation+= pow(recordList->records[i].data[col]-mean,2);
        }
        deviation= sqrt(deviation/recordList->N);
        *a=deviation;
     }

     pOutput=a;
     N=1;
}
void HI(int col,float _min,float _max, float _step,void*&pData,void* &pOutput,int &N)
{ // Calculate histogram of  a column //correct
    RecManager* recordList=static_cast<RecManager*>(pData);
     N=ceil((_max-_min)/_step);
     int* a= new int[N]; //release later through pOutput
     memset(a, 0, N*sizeof(float));

     for(int i=0;i<recordList->N;i++)
     {
         float temp = recordList->records[i].data[col];
         if(temp>=_min &&  temp<_max)
         {
             a[int((temp-_min)/_step)]++;
         }
     }
     pOutput=a;
}
void FR(int col,float _min,float _max,void*& pData,void* &pOutput,int &N)
{ // return index of records depends on outcome and another column
     RecManager* recordList=static_cast<RecManager*>(pData);
     int counter=0;
     for(int i=0;i<recordList->N;i++)
     {
         float temp = recordList->records[i].data[col];
         if(temp!=0&&temp>=_min&&temp<=_max)
         {
             counter++;
         }
     }
     int* a= new int [counter];
     N=counter;
     counter=0;
     for(int i=0;i<recordList->N;i++)
     {
         float temp = recordList->records[i].data[col];
         if(temp!=0&&temp>=_min&&temp<=_max)
         {
             a[counter]=i;
             counter++;
         }
     }
     pOutput=a;


}
void FR(void*&pData,void* &pOutput,int &N) //correct
{ // return index of records depends on outcome=1 only
    RecManager* recordList=static_cast<RecManager*>(pData);
     int counter=0;
     for(int i=0;i<recordList->N;i++)
     {
         if(recordList->records[i].data[8]!=0)
         {
             counter++;
         }
     }
     int* a= new int [counter];
     N=counter;
     counter=0;
     for(int i=0;i<recordList->N;i++)
     {
         if((recordList->records[i].data[8])!=0)
         {
             a[counter]=i;
             counter++;
         }
     }
     pOutput=a;

}


