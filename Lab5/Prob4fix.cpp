#include<iostream>
#include<string>
#include <stdio.h>
#include <string.h>
using namespace std;
void prob4a(string &str){
    char *pSN,*pGN;
    pSN= &str[0]; //set pointer at the start of string
    while(*pSN==' ') pSN++;
    pGN=pSN;
    while(*pGN !=' ') pGN++;
    while(*pGN==' ') pGN++;

    char *pC =new char[str.length()+2];
    strcpy(pC,pGN);

    strcat(pC,", ");
    strcat(pC,pSN);
    pGN=pC+strlen(pC);
    while(*pSN !=' ')
    {
        *pC++ = *pSN++;
    }
    *pC=0;
    str=pC;
    cout<<str;
}
void prob4b(){

}
void prob4c(){

}
main()
{
    string s="tran hoang long";
    prob4a(s);

}
