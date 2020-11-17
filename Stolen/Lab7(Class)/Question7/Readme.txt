#ID : 180    Question 5Number of sumissions: 0/70Expired time: 2019-05-24 12:15:00
Given Champion class as follows:



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


In which:


- Constructor, takePhysicalDamage, takeMagicDamage, and printStatus methods are all conducted correctly.


Create two classes ChampionA and ChampionB, both are inheritances of Champion class.


Then, write code for skill1 and skill2 as requested, remember to call takePhysicalDamage or take MagicDamage function to demonstrate a champion is dead or not.


- ChampionA: 


	+ skill1: cause physical damage = 100 + (physicalDamage * 20) / 100


	+ skill2: cause physical damage = 20 + (physicalDamage * 80) / 100


- ChampionB: 


	+ skill1: cause magic damage = 30 + (abilityPower * 70) / 100


	+ skill2: cause magic damage = 90 + (abilityPower * 30) / 100