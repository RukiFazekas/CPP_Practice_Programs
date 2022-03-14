// --------------------------------------------------------------- //
// Athlete Class Definition File								   //
// --------------------------------------------------------------- //
#pragma once

#include <string>
#include "personType.h"
#include "dateType.h"

using namespace std;

class athleteType : public personType
{
public:
	static enum sportType { UNASSIGNED, HOCKEY, BASEBALL, GOLF, CRICKET };
	static string sportNames[5];

	void setSport(sportType inSport) { sport = inSport; }
	sportType getSport() { return sport; }
	void setIsProfessional(string inIsPro) { isProfessional = inIsPro; }
	string getIsProfessional() const { return isProfessional; }
	void setTeamName(string inTeamName) { teamName = inTeamName; }
	string getTeamName() const { return teamName; }
	void display() const;

	athleteType();
	athleteType(string inName, string inMonth, int inDay, int inYear, sportType inSport, string inIsPro, string inTeamName);

private:
	sportType sport;
	string isProfessional;   // Input answer is Yes or No
	string teamName;
};