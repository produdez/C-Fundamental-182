#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

//.............................PROTOTYPE.................................
class MyVector {
private:
    float* ele_pointer;   //Pointer to the dynamic float array
    int capacity;  // Max number of element can hold before needing to re_allocate memory
    int current_size; //Current number of elements in vector

public:
    MyVector(); //default
    MyVector(const MyVector& b); //copy constructor
    MyVector(int n); // with n-elements

    MyVector operator+(MyVector b); // +
    float operator*(MyVector b); // dot-product
    float &operator[](int n); // accessing element of vector using a[i]

    void push_back(float n); //pushing more element to the end of vector

    void print_vector(); //print all elements


    ~MyVector(); //destructor for release memory
};


#endif // VECTOR_H_INCLUDED
