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

/**......Global function and Match Structure......*/

struct Match {
	int indexOfA;
	int indexOfB;
	int numberOfEvents;
	bool* eventList;
};

void combat(Champion** championList, int numberOfChampions, Match* matchList, int numberOfMatches);
/**......Initialize static member......*/
int Champion::numberOfAliveChampions = 0;


/**......Main......*/
int main()
{

    return 0;
}


/**......Initialize Class functions......*/
/* The constructor */
Champion::Champion(int _id, int _health, int _damage) {
	// Hint: set the corresponding passed values to id, heath, and damage
	// Hint: We have a static variable for alive champion counting!
    id=_id;
    heath=_health;
    damage=_damage;
    numberOfAliveChampions++;

}

/* The destructor */
Champion::~Champion() {
	// Think: What must be done when the the object is destroyed?
	// Hint: We have a static variable for alive champion counting!
    numberOfAliveChampions--;

}

/* This champion attack another champion, the victim will lose an amount of health
equal to the attacker damage, return true if the victim dies after being attacked */
bool Champion::attack(Champion& _victim) {
    _victim.heath-=this->damage;
    return _victim.heath<=0;
}

/* The getter for instance member: this->heath */
int Champion::getHeath() {
    return heath;
}

/* The getter for the class member: Champion::numberOfAliveChampions */
int Champion::getNumberOfAliveChampions() {	// Why static? What is a static method?
    return numberOfAliveChampions;
}


/* For each event, if event is true then the champion A attack the champion B and vise versa.
Return 1 if the champion A killed the champion B, return -1 if the champion B killed the champion A,
or return 0 if no one dies after the fight. Please note that, to mark that a champion is killed,
you have to delete that champion object and set the corresponding pionter to NULL*/
int fight(Champion*& a, Champion*& b, bool* eventList, int numberOfEvent) {
	/*Please note that, to mark that a champion is killed,
	you have to delete that champion object and set the corresponding pionter to NULL */
    for(int i=0;i< numberOfEvent;i++)
    {
        switch (eventList[i]){
        case 1: // a attack b
            if(a->attack(*b))
            {
                delete b;
                b= nullptr;
                return 1;
            }break;

        case 0: // b attack a
            if(b->attack(*b))
            {
                delete a;
                a=nullptr;
                return -1;
            }break;
        }
    }
    return 0;

}

/** .............Global function implement..........*/


/* There are many matches, in each match, the two champion will fight with each other */
void combat(Champion** championList, int numberOfChampions, Match* matchList, int numberOfMatches) {
	for (int i = 0; i < numberOfMatches; i++) {
		if (championList[matchList[i].indexOfA] != NULL && championList[matchList[i].indexOfB] != NULL)
			fight(championList[matchList[i].indexOfA], championList[matchList[i].indexOfB], matchList[i].eventList, matchList[i].numberOfEvents);
	}
}
