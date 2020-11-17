
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07005_sol.cpp"
using namespace std;

// ......................Abstract champion class.......................
class Champion {
protected:
	int id;
	int health;
	int armor;
	int magicResitance;
	int physicalDamage;
	int abilityPower;
public:
	Champion(int _id, int _health, int _armor, int _magicResitance, int _physicalDamage, int _abilityPower);
	bool takePhysicalDamage(int _physicalDamageTaken);
	bool takeMagicDamage(int _magicDamageTaken);
	void printStatus();
	// Abstract methods returning true if the target's health is run out after being attacked.
	virtual bool skill1(Champion& _champ) = 0;
	virtual bool skill2(Champion& _champ) = 0;
};

// ................Derived champions................
class ChampionA: public Champion{
public:
    ChampionA(int _id, int _health, int _armor, int _magicResitance, int _physicalDamage, int _abilityPower)
    : Champion(_id,_health,_armor,_magicResitance,physicalDamage,abilityPower){};
    bool skill1(Champion& _champ);
    bool skill2(Champion& _champ);
};
class ChampionB: public Champion{
 public:
     ChampionB(int _id, int _health, int _armor, int _magicResitance, int _physicalDamage, int _abilityPower)
    : Champion(_id,_health,_armor,_magicResitance,physicalDamage,abilityPower){};
    bool skill1(Champion& _champ);
    bool skill2(Champion& _champ);
};

//............Implement base class functions...........
/* The default constructor initializes the object with champion's properties.
In such, the armor and magic resistance properties must not be negative or exceed 99 */
Champion::Champion(int _id, int _health, int _armor, int _magicResitance, int _physicalDamage, int _abilityPower) {
	if (_armor < 0 || _armor > 99) throw "Invalid armor value.";
	if (_magicResitance < 0 || _magicResitance > 99) throw "Invalid magic resistance value.";
	this->id = _id;
	this->health = _health;
	this->armor = _armor;
	this->magicResitance = _magicResitance;
	this->physicalDamage = _physicalDamage;
	this->abilityPower = _abilityPower;
}

/* This method calculates and reduces the "health" property of the host object
according to the physical damage taken. If the "health" property goes zero or
negative after being attacked, return true and vise versa. */
bool Champion::takePhysicalDamage(int _physicalDamageTaken) {
	this->health -= (_physicalDamageTaken * this->armor / 100);
	if (this->health <= 0) return true;
	return false;
}

/* This method calculates and reduces the "health" property of the host object
according to the magic damage taken. If the "health" property goes zero or
negative after being attacked, return true and vise versa. */
bool Champion::takeMagicDamage(int _magicDamageTaken) {
	this->health -= (_magicDamageTaken * this->magicResitance / 100);
	if (this->health <= 0) return true;
	return false;
}

void Champion::printStatus() {
	cout << "---Champion status---" << endl;
	cout << "Champion ID: " << this->id << endl;
	cout << "Health     : " << this->health<<endl;
}
//..........Implement Skills..........
bool ChampionA::skill1(Champion& _champ)
{
    //cause physical damage = 100 + (physicalDamage * 20) / 100
    return _champ.takePhysicalDamage(100+(this->physicalDamage*20)/100);
}

bool ChampionA::skill2(Champion& _champ)
{
    // physical damage = 20 + (physicalDamage * 80) / 100
    return _champ.takePhysicalDamage(20 + (this->physicalDamage * 80) / 100);
}

bool ChampionB::skill1(Champion& _champ)
{
    return _champ.takeMagicDamage(30 + (this->abilityPower * 70) / 100);
}

bool ChampionB::skill2(Champion& _champ)
{
    return _champ.takeMagicDamage( 90 + (this->abilityPower * 30) / 100);
}

//........................Process function and Code check function.................



bool codeCheck() {
    const char* forbiddenKeyword[] = {"include"};
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


