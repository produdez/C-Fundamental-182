#include <iostream>
#include<random>
#include<time.h>
#include<iomanip>
#define RUNTIME 36000
using namespace std;
main()
{
srand(time(NULL));
int dice1,dice2;
int result[11]={0};
int sum;

for(int i=0;i<RUNTIME;i++) //Rolling dices and calculation
{
 dice1 = rand() %6 +1;
 dice2 = rand() %6 +1;
 sum=dice1+dice2;
 result[sum-2]++;
}

cout<< setw(5)<<"Sum|"<<setw(10)<<"Counts"<<"\n";//Printing result
for(int i=0;i<11;i++)
{
 cout<<setw(3)<<i+2<<setw(2)<<'|'<<setw(10)<<result[i]<<'\n';
}

}
