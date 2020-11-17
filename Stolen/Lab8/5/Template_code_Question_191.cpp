/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 08: 08004_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Sun May 05 23:37:58 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "08004_sol.cpp"
using namespace std;

/* Your code MUST NOT contain any of words in the list:
{"..", "~/", "expect"} event in the comments */

//----------------------------------------------
// Begin implementation
//----------------------------------------------
void genomicStatistic(int numberOfRow, int numberOfColumn, char** arr);

void process(const char* fileName) {
    char** arr;
    int M, N;

    ifstream input;
    input.open(fileName,ifstream::in);
    string ss;
    //no need to count line/char since it's included in the file
    input>>M;
    input>>N;
    cout<<M<<' '<<N<<endl;
    arr= new char*[M]; //create matrix M*N
    for(int i=0;i<M;i++)
    {
        arr[i]= new char[N];
    }

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            input>>arr[i][j];
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }

    // Call function to check
    genomicStatistic(M, N, arr);

    // Tidy dynamic memory
    for (int row = 0; row < M; row++) delete[] arr[row];
    delete[] arr;
}


bool codeCheck() {
    const char* forbiddenKeyword[] = {"..", "~/", "expect"};
    fstream ifs;
    ifs.open("main.cpp", ios::in);
    if (ifs.fail()) ifs.open(FILENAME, ios::in);
    if (ifs.fail()) return true;
    ifs.seekg(0, ifs.end);
    int fileSize = ifs.tellg();
    ifs.seekg(0, ifs.beg);
    char* fileContent = new char[fileSize];
    ifs.read(fileContent, fileSize);
    ifs.close();
    *strstr(fileContent, "bool codeCheck() {") = '\0';
    char* todoSegment = strstr(fileContent ,"// Begin implementation");
    int numberOfForbiddenKeyword = sizeof(forbiddenKeyword) / sizeof(const char*);
    for (int i = 0; i < numberOfForbiddenKeyword; i++) { if (strstr(todoSegment, forbiddenKeyword[i])) return false; }
    delete[] fileContent;
    return true;
}

int main(int argc, char* argv[]) {
    if (codeCheck() == false) {
        cout << "Forbidden-keyword rule violation." << endl;
        return -1;
    }

    //manual test

    process("test.txt");

    //end

    return 0;
}

void genomicStatistic(int numberOfRow, int numberOfColumn, char** arr) {
    const char nucleicAcid[] = {'A', 'T', 'G', 'C'};
    int* statisticMatrix[4];     //0, 1, 2, 3 for A, T, G, and C respectively
    for (int i = 0; i < 4; i++) {
        statisticMatrix[i] = new int[numberOfColumn];
        for (int j = 0; j < numberOfColumn; j++) statisticMatrix[i][j] = 0;
    }
    for (int col = 0; col < numberOfColumn; col++) {
        for (int row = 0; row < numberOfRow; row++) {
            switch (arr[row][col]) {
                case 'A':
                    statisticMatrix[0][col]++;
                    break;
                case 'T':
                    statisticMatrix[1][col]++;
                    break;
                case 'G':
                    statisticMatrix[2][col]++;
                    break;
                case 'C':
                    statisticMatrix[3][col]++;
                    break;
                default:
                    break;
            }
        }
    }
    cout << "P:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < numberOfColumn; j++) {
            cout << statisticMatrix[i][j];
            if (j < numberOfColumn - 1) cout << " ";
            else cout << endl;
        }
    }
    cout << "C:" << endl;
    for (int col = 0; col < numberOfColumn; col++) {
        int largestNumberOfOccurrence = 0;
        int indexOfMax;
        for (int row = 0; row < 4; row++) {
            if (statisticMatrix[row][col] > largestNumberOfOccurrence) {
                largestNumberOfOccurrence = statisticMatrix[row][col];
                indexOfMax = row;
            }
        }
        cout << nucleicAcid[indexOfMax];
        if (col < numberOfColumn - 1) cout << " ";
    }
}
