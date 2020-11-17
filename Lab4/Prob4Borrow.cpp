#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

struct myDay {
    int day;
    int month;
    int year;
};

struct Student {
    string ID;
    string name;
    string surName;
    myDay birthday;    
    char data[1024];
};

struct StudentList {
    int nStudent;
    int maxStudent;
    Student sList[100];
};

int main(){
    string surName;
    string ID;
    int month;
    int counter = 0;
    int studentIndex[100];
    memset(studentIndex, -1, sizeof(int) * 100);

    StudentList sL = {5, 100, {
        {"1852590", "Minh", "Vu", {16, 8, 2000}, ""},
        {"1852405", "Gia Huy", "Nguyen", {12, 9, 2000}, ""},
        {"1659878", "Thanh", "Tran", {30, 9, 1997}, ""}
    }
    };
    cout << "SURNAME you wanted to find: ";
    cin >> surName;

    for (int i = 0; i < sL.nStudent; i++){
        if (surName == sL.sList[i].surName) 
		{
            studentIndex[counter++] = i;
        }
    }
    if (counter){
        cout << setw(5) << "#" << "|"
             << setw(10) << "ID" << "|"
             << setw(10) << "SurName" << "|"
             << setw(15) << "Given Name" << "|"
             << setw(10) << "birthday" << "\n";
        for (int i = 0; i < counter; i++){
            cout << setw(5) << i + 1 << "|"
                 << setw(10) << sL.sList[studentIndex[i]].ID << "|"
                 << setw(10) << sL.sList[studentIndex[i]].surName << "|"
                 << setw(15) << sL.sList[studentIndex[i]].name << "|"
                 << setw(2) << sL.sList[studentIndex[i]].birthday.day << "-"
                 << setw(2) << sL.sList[studentIndex[i]].birthday.month << "-"
                 << setw(2) << sL.sList[studentIndex[i]].birthday.year << "\n";
        }
    }

    counter = 0;
    cout << "\nID you want to find: ";
    cin >> ID;
    for (int i = 0; i < sL.nStudent; i++){
        if (ID == sL.sList[i].ID) {
            studentIndex[counter++] = i;
        }
    }
    if (counter) {
        cout << setw(5) << "#" << "|"
             << setw(10) << "ID" << "|"
             << setw(10) << "SurName" << "|"
             << setw(15) << "Given Name" << "|"
             << setw(10) << "birthday" << "\n";
        for (int i = 0; i < counter; i++) {
            cout << setw(5) << i + 1 << "|"
                 << setw(10) << sL.sList[studentIndex[i]].ID << "|"
                 << setw(10) << sL.sList[studentIndex[i]].surName << "|"
                 << setw(15) << sL.sList[studentIndex[i]].name << "|"
                 << setw(2) << sL.sList[studentIndex[i]].birthday.day << "-"
                 << setw(2) << sL.sList[studentIndex[i]].birthday.month << "-"
                 << setw(2) << sL.sList[studentIndex[i]].birthday.year << "\n";
        }
    }
	
	counter = 0;
	
	cout << "\nList of students in September: \n";
	for (int i = 0; i < sL.nStudent; i++) {
        if (sL.sList[i].birthday.month == 9) {
            studentIndex[counter++] = i;
        }
    }
    if (counter) {
        cout << setw(5) << "#" << "|"
             << setw(10) << "ID" << "|"
             << setw(10) << "SurName" << "|"
             << setw(15) << "Given Name" << "|"
             << setw(10) << "birthday" << "\n";
        for (int i = 0; i < counter; i++) {
            cout << setw(5) << i + 1 << "|"
                 << setw(10) << sL.sList[studentIndex[i]].ID << "|"
                 << setw(10) << sL.sList[studentIndex[i]].surName << "|"
                 << setw(15) << sL.sList[studentIndex[i]].name << "|"
                 << setw(2) << sL.sList[studentIndex[i]].birthday.day << "-"
                 << setw(2) << sL.sList[studentIndex[i]].birthday.month << "-"
                 << setw(2) << sL.sList[studentIndex[i]].birthday.year << "\n";
        }
    }
    return 0;
}

