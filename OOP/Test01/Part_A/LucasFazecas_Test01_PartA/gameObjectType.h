#pragma once
#include <string>

using namespace std;

class gameObjectType
{
public:
	static int objectCount;

	string getName() const { return name; }
	void setName(string inName) { name = inName; }
	int getWorld() const { return world; }
	void setWorld(int inWorld) { world = inWorld; }
	void getPosition(float& xPos, float& yPos) const { xPos = xPosition, yPos = yPosition; }
	void setPosition(float xPos, float yPos) { xPosition = xPos, yPosition = yPos; }
	void display() const;
	bool equal(gameObjectType& compareTarget) const;
	static int getObjectCount() { return objectCount; }

	gameObjectType(string inName, int inWorld, float inXPos, float inYPos);
	gameObjectType();
	~gameObjectType();

private:
	string name;
	int world;		// world is represented by an int number instead of a name
	float xPosition;
	float yPosition;
};