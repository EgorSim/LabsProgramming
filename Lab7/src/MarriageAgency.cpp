#include "MarriageAgency.h"
#include <iostream>

void MarriageAgency::showPair(std::pair<People&, People&> pair) {
	std::cout << "===============PAIR===============" << std::endl;
	std::cout.setf(std::ios::left);
	std::cout.width(25);
	std::cout << "Man:" << "Woman:" << std::endl;
	std::cout.width(25);
	std::cout << ("Name: " + pair.first.name);
	std::cout << ("Name: " + pair.second.name) << std::endl;
	std::cout.width(25);
	std::cout << ("Second Name: " + pair.first.secondName);
	std::cout << ("Second Name: " + pair.second.secondName) << std::endl;
	std::cout.width(25);
	std::cout << ("Sity: " + pair.first.sity);
	std::cout << ("Sity: " + pair.second.sity);
	std::cout << std::endl;
}

bool MarriageAgency::checkSimilarity(const People& m, const People& w) {
	bool flag{ false };
	for (auto& i : m.requiredHobbies) {
		for (auto& j : w.hobbies) {
			if (i == j) {
				flag = true;
				break;
			}
		}
		if (!flag) return false;
	}

	for (auto& i : m.requiredBadHabbits) {
		for (auto& j : w.badHabbits) {
			if (i == j) return false;
		}
	}

	flag = false;
	for (auto& i : w.requiredHobbies) {
		for (auto& j : m.hobbies) {
			if (i == j) {
				flag = true;
				break;
			}
		}
		if (!flag) return false;
	}

	for (auto& i : w.requiredBadHabbits) {
		for (auto& j : m.badHabbits) {
			if (i == j) return false;
		}
	}

	return true;
}

MarriageAgency::MarriageAgency() {}

void MarriageAgency::addPeople(People& people) {
	if (people.sex == Sex::Man) men.push_back(people);
	else women.push_back(people);
}

void MarriageAgency::showPossiblePairs() {
	for (auto& m : men) {
		for (auto& w : women) {
			if (checkSimilarity(m, w)) showPair(std::pair<People&, People&>{m, w});
		}
	}
}

void MarriageAgency::makePair(uint16_t mansNumber, uint16_t womansNumber) {
	int i{ 0 }, j{ 0 };
	for (auto& obj : men) {
		if (obj.number == mansNumber) break;
		++i;
		if (obj == *--men.end()) throw "Mans number not found";
	}
	for (auto& obj : women) {
		if (obj.number == womansNumber) break;
		++j;
		if (obj == *--women.end()) throw "Womans number not found";
	}

	archive.push_back(std::pair<People&, People&>{men[i], women[j]});
	men.erase(men.begin() + i);
	women.erase(women.begin() + j);
}
