#pragma once

using namespace std;

/*********************************************/
// Class definitions
class carType 
{
private:
	string carName;
	int carRamStr;		// strength of the cars ram attack
	int carBodyDmg;		// body strength of the car that acts like a shield
	int carHp;			// stores the remaining hit points of a car
	static const int MAX_HP;	// max hit points used to initialize a car hit points

public:
	// Mutators
	void setName(string inName) { carName = inName; }
	void setRamStrength(int inRamStr) { carRamStr = inRamStr; }
	void setBodyDamage(int inDmg) { carBodyDmg = inDmg; }
	void setHitPoints(int inHp) { carHp = inHp; }	
	void takeDamage(const int& inRamStrength);
	void attackCar(carType& target);

	// Accessors
	string getName() const { return carName; }
	int getRamStrength() const { return carRamStr; }
	int getBodyDamage() const { return carBodyDmg; }
	int getHitPoints() const { return carHp; }
	void display() const;
	void setTextColour(int inValue) const;
	bool isAlive() const;

	// Constructors
	carType();
	carType(string inName, int inRamStr, int inHp);
	~carType();
};