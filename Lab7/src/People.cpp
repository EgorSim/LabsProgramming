#include "People.h"
#include <cstdarg>
#include <typeinfo>
#include <string>

void People::setBirthday(uint8_t day, uint8_t month, uint8_t year) {
	if (month > 12) throw "Unkorrect month";
	if (day > 31 || (day > 28 && month == 2)) throw "Unkorrect day";
	this->day = day;
	this->month = month;
	this->year = year;
}

People::People(std::string name,
	std::string secondName,
	uint16_t number,
	Sex sex,
	uint8_t day,
	uint8_t month,
	uint16_t year,
	uint8_t height,
	uint8_t weight,
	std::string sity) :
	name(name), 
	secondName(secondName),
	sex(sex),
	height(height), 
	weight(weight),
	sity(sity) {
	setBirthday(day, month, year);
}

void People::setInformation(std::string info) {
	information = info;
}

void People::setHobbies(uint8_t count, ...) {
	va_list list;
	va_start(list, count);

	for (size_t i = 0; i < count; ++i) {
		//if (!strcmp(typeid(va_arg(list, Sex)).name(), typeid(Sex).name())) throw "Argument is not Sex type";
		Hobby temp{ va_arg(list, Hobby) };
		bool flag{ false };
		for (const auto& obj : hobbies) flag = true;
		if (flag) continue;
		hobbies.push_back(temp);
	}
}

void People::setBadHobbies(uint8_t count, ...) {
	va_list list;
	va_start(list, count);

	for (size_t i = 0; i < count; ++i) {
		BadHabbits temp{ va_arg(list, BadHabbits) };
		bool flag{ false };
		for (const auto& obj : badHabbits) flag = true;
		if (flag) continue;
		badHabbits.push_back(temp);
	}
}

void People::setRequiredHobbies(uint8_t count, ...) {
	va_list list;
	va_start(list, count);

	for (size_t i = 0; i < count; ++i) {
		Hobby temp{ va_arg(list, Hobby) };
		bool flag{ false };
		for (const auto& obj : requiredHobbies) flag = true;
		if (flag) continue;
		requiredHobbies.push_back(temp);
	}
}

void People::setRequiredBadHobbies(uint8_t count, ...) {
	va_list list;
	va_start(list, count);

	for (size_t i = 0; i < count; ++i) {
		BadHabbits temp{ va_arg(list, BadHabbits) };
		bool flag{ false };
		for (const auto& obj : requiredBadHabbits) flag = true;
		if (flag) continue;
		requiredBadHabbits.push_back(temp);
	}
}

bool People::operator==(const People& obj) {
	if (this->number == obj.number) return true;
	return false;
}
