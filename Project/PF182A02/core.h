//
// Created by Nguyen Duc Dung on 2019-04-20.
//

#ifndef A02_CORE_H
#define A02_CORE_H

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

/// Prototype declaration
int count_record(const char*); //open file and count number of records

/// Functions to work with struct

float* col_pointer(std::string col,void*&pData); // return a pointer to the needed value of first record, help to access column easier

void CR(void*&pData,void* &pOutput,int &);
void DI(std::string info,float* col,void*& pData,void* &pOutput,int &);
void HI(float* col,float _min,float _max, float _step,void*&pData,void* &pOutput,int &);
void FR(float* col,float _min,float _max,void*&pData,void* &pOutput,int &);
void FR(void*&pData,void* &pOutput,int &);

///
void Initialization();
void Finalization();

void LoadData(const char*, void* &);
void ReleaseData(void* &);

void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int &);
void PrintOutput(const char* pRequest, void* pData, void* &pOutput, int);

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
    // TODO: Please define the detail of this struct so that you can manage the records
    int N; // number of records
    Record* records; //array of struct!

};



#endif //A02_CORE_H
