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
#include <sstream>
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
std::ifstream file;
std::string menu[5];
// TODO: add more global variables to complete tasks

///--------------------------------------------------------------------
/**
 * Function: Initialization
 * Purpose:  Initialize anything necessary in your program before starting
 * Input:    None
 * Output:   None
 */
void Initialization() {
    file.open("conf.json",std::ifstream::in);
    if(file.is_open())
    {
    LoadConfiguration();
    LoadMenu();
    // TODO: write the code to initialize the program
    __coreInitialized = true;
    file.close();
    }
    else
    {
        std::cout<<"Can't open file!"<<std::endl;
    }

}

/**
 * Function: Finalization
 * Purpose:  Clean up everything before the program exits
 * Input:    None
 * Output:   None
 */
void Finalization() {
    // TODO: write the code to clean up when the program exits
}

void LoadConfiguration() {
    file.clear();
    file.seekg(0,std::ios::beg);

    std::string ss;
    while(!file.eof())
    {
        getline(file,ss);

        unsigned line =ss.find("line");
        if(line != std::string::npos)
        {
            unsigned first = ss.find('"',line+7);
            unsigned last = ss.find_last_of('"');
            std::cout<<ss.substr(first+1,last-first-1)<<std::endl;
        }
    }
    // TODO: write code to load data from the configuration file
}

void LoadMenu() {
    file.clear();
    file.seekg(0,std::ios::beg);

    int i=0;
    std::string ss;
    while(!file.eof())
    {
        getline(file,ss);
        unsigned opt = ss.find("opt");
        if(opt != std::string::npos)
        {
            unsigned first = ss.find('"',opt+7);
            unsigned last = ss.find_last_of('"');
            menu[i++] = ss.substr(first+1,last-first-1);
        }
    }
    // TODO: write code to load menu from the configuration file
}

void DisplayMenu() {
    // TODO: Display the menu loaded from configuration file
    for(int i=0;i<5;i++)
    {
        std::cout<<i+1<<". "<<menu[i]<<std::endl;
    }
}

void ProcessUserChoice() {
    // TODO: Read user input and process
    std::string in="";
    while(1)
    {
        std::cout<<"Please select: ";
        getline(std::cin,in);

        bool isNum=1;
        in.erase(0,in.find_first_not_of(' '));
        if(in.size()==0)
        {
            isNum=0;
            goto checkPoint;
        }
        in.erase(in.find_last_not_of(' '),in.size()-in.find_last_not_of(' ')-1);
        for(int i=1;i<in.size();i++)
        {
            if('0' > in[i] || in[i] > '9')
            {
                isNum=0;
                goto checkPoint;
            }
        }
        if(in[0] != '+' && in[0] != '-' && (in[0]<'0' || in[0] >'9'))
            isNum=0;

        checkPoint:
        if(isNum==0)
        {
            std::cout<<"Invalid input, please input an integer number."<<std::endl;
            continue;
        }
        else
        {
            std::stringstream ss(in);
            if(ss>>__userChoice)
            {
            if(__userChoice>=1 && __userChoice <=5) break; // input valid, exit loop and process
            else
            std::cout<<"Please select a number from 1 to 5."<<std::endl;
            continue;
            }
        }
//        std::stringstream ss(in);
//        if(ss>>__userChoice)
//        {
//            if(__userChoice>=1 && __userChoice <=5) break; // input valid, exit loop and process
//            else
//            std::cout<<"Please select a number from 1 to 5."<<std::endl;
//            continue;
//        } else
//        {
//            std::cout<<"Invalid input, please input an integer number."<<std::endl;
//            ss.clear();
//            ss.ignore(10000000,'\n');
//        }
    }

    if(__userChoice == 5)
    {
        std::cout << "Exiting..."<<std::endl;
        __isExiting=true;
        return;
    }
    std::cout << "You select menu item "<<__userChoice<<". Processing . . . Done!"<<std::endl;
}
