#pragma once

#include "People.h"
#include <vector>

class MarriageAgency {
private:
	std::vector<People> men;
	std::vector<People> women;
	std::vector<std::pair<People&, People&>> archive;

	void showPair(std::pair<People&, People&> pair);
	bool checkSimilarity(const People& m, const People& w);
public:
	MarriageAgency();
	
	void addPeople(People& people);
	void showPossiblePairs();
	void makePair(uint16_t firstNumber, uint16_t secondNumber);
};

