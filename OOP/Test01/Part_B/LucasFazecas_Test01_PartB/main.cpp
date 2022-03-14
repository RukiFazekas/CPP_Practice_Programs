// --------------------------------------------------------------- //
// Author: Lucas Fazecas
// Purpose: Test 01 - Part B
// Date: Feb 16, 2022
// --------------------------------------------------------------- //
#include <iostream>
#include <string>
#include "personType.h"
#include "athleteType.h"

using namespace std;

int main()
{
	cout << "Time to 'object'ively inherit and composite stuff....Woot Woot!!\n\n";

	// person type default constructor

	personType defaultPerson;

	// athlete type default constructor

	athleteType athlete1;

	// athlete type parameterized constructor

	athleteType athlete2("Wayne Gretzky", "January", 26, 1961, athleteType::HOCKEY, "Yes", "Edmonton Oilers");

	// display person object

	cout << "Person Object ----------------------------------------" << endl;
	defaultPerson.display();

	// display athlete 1 object

	cout << "Athlete 1 Object -------------------------------------" << endl;
	athlete1.display();

	// display athlete 2 object

	cout << "Athlete 2 Object ------------------------------------" << endl;
	athlete2.display();

	// test set functions for athlete 1 object

	athlete1.setName("Connor Bedard");
	athlete1.setBirthDate("June", 1, 2002);
	athlete1.setSport(athleteType::CRICKET);
	athlete1.setIsProfessional("No");
	athlete1.setTeamName("St. Catharines Warriors");

	// display athlete 1 object

	cout << "Athlete 1 Object after set function calls ------------" << endl;
	athlete1.display();

	system("pause");
	return 0;
}