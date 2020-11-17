#include <iostream>
#include<random>


// realloc


void expand (int* (&p),int N){
    int* temp = new int[N+1];
    std::copy(p, p + 5, temp);
    delete [] p;
    temp[N]=12;
    p = temp;

}
 int main(){
 int *p;
p = new int[5];
for(int i=0;i<5;i++)
   *(p+i)=i;
for(int i=5;i<20;i++)
expand(p,i);
for(int i=0;i<20;i++)
    std::cout<<p[i]<<' ';

 return 0;
 }
