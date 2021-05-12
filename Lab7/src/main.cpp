#include <iostream>
#include "People.h"
#include "MarriageAgency.h"




int main() {
	MarriageAgency ag{};
	People gena("Gena", "Ivanov", 123456, Sex::Man, 8, 5, 2000, 188, 84, "Minsk");
	People galya("Galya", "Pupkina", 123457, Sex::Woman, 18, 7, 2001, 182, 63, "Minsk");
	gena.setRequiredHobbies(1, Hobby::Cooking);
	galya.setHobbies(1, Hobby::Cooking);
	galya.setRequiredHobbies(1, Hobby::ListeningToMusic);
	gena.setHobbies(1, Hobby::ListeningToMusic);
	galya.setRequiredBadHobbies(1, BadHabbits::Smoking);
	gena.setBadHobbies(1, BadHabbits::Drinking);

	ag.addPeople(gena);
	ag.addPeople(galya);
	ag.showPossiblePairs();


	return 0;
}