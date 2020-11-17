#include <iostream>
#define maxLength 1000
using namespace std;
 int n;
 int fullArray[maxLength];
void MakeArray()
{


    cout<<"how long is your array?";
    cin >>n;
    for (int i=0;i<n;i++)
    {
        cout<<"Input the "<<i+1<<" element ";
        cin>>fullArray[i];
    }
    for (int i=0;i<n;i++)
    {
        cout<<"  "<<fullArray[i];
    }
    cout<<'\n';
}

int max_num;
void CheckArrayMax()
{

    max_num= fullArray[0];
    for (int i=1;i<n;i++)
    {
        if(fullArray[i]>max_num) max_num=fullArray[i];
    }
    cout<<"Maximum element is: "<<max_num<<'\n';
}
void CheckArraySecond()
{

    int gap;
    int min_gap= max_num-fullArray[0];
    for (int i=1;i<n;i++)
    {
        gap=max_num-fullArray[i];
        if(gap<min_gap&&gap!=0) min_gap=gap;
    }
    cout<<"Second largest element is: "<<max_num-min_gap<<'\n';
}
int diff_index=0;
bool rep;
int diff_ele[maxLength];
void DiffEleFilter() //Check for all different elements and put in a array
{
    for (int i=0;i<n;i++)  // Check each element in FullArray
    {
        rep=0;

        for (int j=i+1;j<n;j++) //Check if ele repeated from that point forward
        {
            if(fullArray[i]==fullArray[j])
            {
                rep=1;
                break;
            }
        } // After loop, if rep=0 means it the only ele in array or the last occurrence

        if (rep==0)
        {
            diff_ele[diff_index]=fullArray[i]; //Put in new array that only have different ele
            diff_index++;
        }
        else continue; //Else keep checking!
    }
 //Number of diff ele is the diff_index after running this fuct
}
void DiffEleArray() //Print the array of different elements
//FOR DEBUG ONLY
{
   for (int i=0;i<diff_index;i++)
   {
       cout<<" "<<diff_ele[i];
   }
}

int counter[maxLength]={0};
void ElementCounter()
{
    for (int i=0;i<diff_index;i++) //Check each ele in diff_ele
   {
       for (int j=0;j<n;j++)  // Check each element in FullArray
    {
        if(diff_ele[i]==fullArray[j]) counter[i]++;
    }
   }
    for (int i=0;i<diff_index;i++)
    {
        cout<<"The number occurrences for "<<diff_ele[i]<<" is: "<<counter[i]<<'\n';
    }
}

int max_count=counter[0];
void MaxOccurrence()
{
    for (int i=1;i<diff_index;i++)
    {
        if(counter[i]>max_count) max_count=counter[i];
    }
    cout<<"Maximum occurrence is "<<max_count<<" times!"<<'\n';

    cout<<"Elements with such occurrence are: ";
    for (int i=0;i<diff_index;i++)
    {
        if(counter[i]==max_count) cout<<"  "<<diff_ele[i];
    }
    cout<<'\n';
}



main()
{
    MakeArray();
    CheckArrayMax();
    CheckArraySecond();
    DiffEleFilter();
   // DiffEleArray();
   ElementCounter();
   MaxOccurrence();
}
