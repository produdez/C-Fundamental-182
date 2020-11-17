//
// Created by Nguyen Duc Dung on 2019-02-15.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include<sstream>
#include <chrono>
#include <thread>
using namespace std;
/// Prototype declaration
void Initialization();
void Finalization();

void LoadConfiguration();
void LoadMenu();
void DisplayMenu();
void ProcessUserChoice();
///--------------------------------------------------------------------

bool __coreInitialized = false;  /// an example of global variable
int  __userChoice;               /// a global variable to store user choice
bool __isExiting = false;        /// this variable should be turn on when the program exits
string line;
char keyword='"';
string welcome[15]; //Store Welcome message
string menu[10]; //Store menu info
int i;
ifstream data;
// TODO: add more global variables to complete tasks

///--------------------------------------------------------------------
/**
 * Function: Initialization
 * Purpose:  Initialize anything necessary in your program before starting
 * Input:    None
 * Output:   None
 */
void Initialization() {
    data.open("conf.json",ifstream::in);
    LoadConfiguration();
    cout<<"\n";
    LoadMenu();
    // TODO: write the code to initialize the program
    __coreInitialized = true;
}

/**
 * Function: Finalization
 * Purpose:  Clean up everything before the program exits
 * Input:    None
 * Output:   None
 */
void Finalization() {
    // TODO: write the code to clean up when the program exits
    data.close();
    return;

}

void LoadConfiguration() {
    // TODO: write code to load data from the configuration file
    if(__coreInitialized)return;
    i=0;
    while(!data.eof()){ //Read line by line till end of file
    getline(data,line);
    size_t pos1 = line.find(keyword)+1;         //find the positions of the char " in the lines
    size_t pos2= line.find(keyword,pos1)+1;
    size_t pos3 = line.find(keyword,pos2)+1;
    size_t pos4 = line.find(keyword,pos3);
    if(pos1!=string::npos&&pos2!=string::npos&&pos3!=string::npos&&pos4!=string::npos)
    {
        size_t found_line = line.find("line");
        if (found_line!=string::npos)   //specify if the found line is for welcome text
        {
            welcome[i]=line.substr(pos3,pos4-pos3); //put it in an array for later use
            i++;
        }
}
    }
    for (int x=0;welcome[x]!=welcome[x+1];x++) //print the array for welcome text
    cout << welcome[x]<<"\n";
       std::this_thread::sleep_for(std::chrono::seconds(3));
       data.clear(); //reset the file reading stream
}
void LoadMenu() {
    // TODO: write code to load menu from the configuration file
	data.seekg(0, ios::beg); //return the reading pointer to the start of the file
	i=0;
    while(!data.eof()){ //Read line by line till end of file
    getline(data,line);
    size_t pos1 = line.find(keyword)+1; //find the positions of the char " in each lines
    size_t pos2= line.find(keyword,pos1)+1;
    size_t pos3 = line.find(keyword,pos2)+1;
    size_t pos4 = line.find(keyword,pos3);
    if(pos1!=string::npos&&pos2!=string::npos&&pos3!=string::npos&&pos4!=string::npos) //Only further check the line if four different chars of " is available
    {
        size_t found_opt= line.find("opt"); //Specify the the found line is for menu text
        if (found_opt!=string::npos)
        {
            menu[i]=line.substr(pos3,pos4-pos3); //Store in a string array for menu printing
            i++;
        }
}
}
}

void DisplayMenu() {
    // TODO: Display the menu loaded from configuration file
    for (int x=0;menu[x]!=menu[x+1];x++) //Print menu from the array
    cout <<x+1<<". "<< menu[x]<<"\n";
}

void ProcessUserChoice() {
    // TODO: Read user input and process

    bool valid=false;
    string __userChoice2;

    while (!valid) //check user input until accepted our conditions
    {
        valid=true;
        cout<<"Please select: ";
        cin>> __userChoice2; //For storing the input as a string

        for(unsigned int x=0; x<__userChoice2.length();x++)  //Check string char by char to check for wrong characters
    {
        if(!isdigit(__userChoice2[x]))	{valid = false;}
    }
        if(valid) //Transform the input from string to integer if the format is correct
        {
            stringstream __choice(__userChoice2);
            __choice>>__userChoice;
        }else
        {
            cout<<"Invalid input, please input an integer number.\n";
             DisplayMenu();
            cin.clear();
        cin.ignore(100000,'\n');
        }
    if ((__userChoice<1 || __userChoice>5)&&valid) //Check if choice is out of range
        {
			cout << "Please select a number from 1 to 5." << "\n";
			 DisplayMenu();
			cin.clear();
        cin.ignore(100000,'\n');
			valid = false;
        }
    }
    switch(__userChoice) { //Process final User choice
    case 1 : cout << "You've select menu item "<<__userChoice<<". Processing... Done!\n";
             break;
    case 2 : cout << "You've select menu item "<<__userChoice<<". Processing... Done!\n";
             break;
    case 3 : cout << "You've select menu item "<<__userChoice<<". Processing... Done!\n";
             break;
    case 4 : cout << "You've select menu item "<<__userChoice<<". Processing... Done!\n";
             break;
    case 5 : cout << "Exiting ...";
             __isExiting=true; //Turn on exit flag to exit program
             return;
}
}

