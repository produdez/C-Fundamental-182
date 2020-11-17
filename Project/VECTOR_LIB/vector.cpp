#define DEFAULT_SIZE 5
#define EXTRA_STORAGE 2
#include<iostream>
#include <stdlib.h>
#include "vector_def.h"

// ......................................................CONSTRUCTOR....................................
MyVector::MyVector(){
    ele_pointer = new float[DEFAULT_SIZE];
    capacity = DEFAULT_SIZE;
    current_size=0;
}
MyVector::MyVector(int n){  // even-though given n elements, allocate some 'extra' storage is very handy
    ele_pointer= new float[n+EXTRA_STORAGE];
    capacity= n+EXTRA_STORAGE;
    current_size=0;
}
MyVector::MyVector(const MyVector& b){ //Very important
    ele_pointer= new float[b.capacity];
    std::copy( b.ele_pointer,(b.ele_pointer)+(b.current_size), ele_pointer);
    current_size=b.current_size;
    capacity=b.capacity;

}

//............................................DESTRUCTOR.....................................


MyVector::~MyVector(){

    if(ele_pointer) delete [] ele_pointer; // release memory allocated for vector array
}

//..................................... MAIN FUNCTION............................
void MyVector::push_back(float n){
     if(current_size==capacity) //when full
     {
        capacity*=2;
        MyVector c=*this;  // create an array with more space and copy current data to it!
        c.push_back(n); //Then push in the new number !

        delete [] ele_pointer; //release old array
        ele_pointer=c.ele_pointer; //move our pointer to new array
        capacity=c.capacity;
        current_size++; //change capacity and current_size

        c.ele_pointer=NULL;
        return;
     }
     //if not full, just push data inside
     ele_pointer[current_size]=n;
     current_size++;
}

void MyVector::print_vector(){
    for (int i=0;i< current_size;i++)
    {
        std::cout<<ele_pointer[i]<<' ';
    }
    std::cout<<std::endl;
}

//..............................................OVERLOADED OPERATORS.......................
MyVector MyVector::operator+(MyVector b){

    // I found two method for this operator
    //......First method:

    MyVector* maxv= current_size>b.current_size? &(*this) : &b;
    int _min=std::min(this->current_size,b.current_size);

    MyVector c=*maxv; // create a new vector equals to the size of the bigger vector

    for(int i=0;i<_min;i++) // and change the elements in the indexes from (0 to _min-1) to a[i]+b[i]
    {
        c.ele_pointer[i]=ele_pointer[i]+b.ele_pointer[i];
    }

    maxv=nullptr;
    return c;
    //......Second method below
    //(create an empty vector with same size as the bigger vector and use our push_back method!)
/**
    MyVector* minv= current_size<=b.current_size? &(*this) : &b;
    MyVector* maxv= current_size>b.current_size? &(*this) : &b;
    int _max=maxv->current_size;
    int _min=minv->current_size;

    MyVector c(_max);

    for(int i=0;i<_max;i++)
    {
        if(i<_min)
        c.push_back(ele_pointer[i]+b.ele_pointer[i]);
        else
        c.push_back(maxv->ele_pointer[i]);
    }
    minv=nullptr;
    maxv=nullptr;
    return c;

    */
}


float MyVector::operator*(MyVector b){
    if(current_size!=b.current_size)
    return -1;
    float dot=0;
    for(int i=0;i<current_size;i++)
    {
        dot+= ele_pointer[i]*b.ele_pointer[i];
    }
    return dot;
}

float &MyVector::operator[](int index){
    if (index >= current_size)
    {
        std::cout << "Vector index out of bound, exiting"<<std::endl;
        exit(0);
    }
    return ele_pointer[index];
}


