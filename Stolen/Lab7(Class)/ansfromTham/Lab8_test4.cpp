/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 07: 07003_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Tue Apr 23 10:19:58 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07003_sol.cpp"
using namespace std;
//----------------------------------------------
// Begin implementation
//----------------------------------------------

//------------------------------------------------------------------------
/**
* Champion class definition
*/
class Champion {
	int id;
	int heath;
	int damage;
	static int numberOfAliveChampions;	// Think: Why static? What is a static member?
	/* What are the differences between a static member and the others? */
public:
	Champion(int _id, int _health, int _damage);
	~Champion();
	bool attack(Champion& _victim);
	int getHeath();
	static int getNumberOfAliveChampions();	// Why static? What is a static method?
	/* What are the differences between a static method and the others? */
};


/**
* Champion class implementation
*/

/* The constructor */
Champion::Champion(int _id, int _health, int _damage) {
	// Hint: set the corresponding passed values to id, heath, and damage
	// Hint: We have a static variable for alive champion counting!
    id = _id;
    heath = _health;
    damage = _damage;
    numberOfAliveChampions ++;
}
/* The destructor */
Champion::~Champion() {
	numberOfAliveChampions --;
}
bool Champion::attack(Champion& _victim) {
    _victim.heath -= damage;
    if (_victim.heath <= 0)
    	return true;
    else
    	return false;
}
int Champion::getHeath() {
	return heath;
}
int Champion::getNumberOfAliveChampions() {
	return numberOfAliveChampions;
}
int Champion::numberOfAliveChampions = 0;
int fight(Champion*& a, Champion*& b, bool* eventList, int numberOfEvent) {
	for (int i = 0; i < numberOfEvent; i++) {
		if (eventList[i] == true)
		{
            if (a->attack(*b) == true)
            {
            	delete b;
            	b = NULL;
				return 1;
			}
        }
        else
            if (b->attack(*a) == true)
                {
                	delete a;
                	a = NULL;
					return -1;
				}
}
    return 0;
}
int main()
{
	Champion *a = new Champion(1, 2000, 100);
	Champion *b = new Champion(2, 3000, 200);
	bool eventList[3] = {1,1,0};
	int n = 3;
	cout << fight(a, b, eventList, n);
}
