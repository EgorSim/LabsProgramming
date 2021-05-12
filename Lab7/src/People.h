#pragma once

#include <string>
#include <vector>

enum class Sex {
	Man,
	Woman
};

enum class Hobby {
	Reading,
	Singing,
	ListeningToMusic,
	Photography,
	Drowing,
	Needlework,
	Cooking
};

enum class BadHabbits {
	Smoking,
	Drinking,
	Drug,
	Gluttony
};

class People
{
private:
	void setBirthday(uint8_t day, uint8_t month, uint8_t year);

public:
	std::string name;
	std::string secondName;
	uint16_t number;
	Sex sex;
	uint8_t day;
	uint8_t month;
	uint16_t year;
	uint8_t height;
	uint8_t weight;
	std::string sity;
	std::string information;
	std::vector<Hobby> hobbies;
	std::vector<BadHabbits> badHabbits;
	std::vector<Hobby> requiredHobbies;
	std::vector<BadHabbits> requiredBadHabbits;

	People(std::string name,
		std::string secondName,
		uint16_t number,
		Sex sex,
		uint8_t day,
		uint8_t month,
		uint16_t year,
		uint8_t height,
		uint8_t weight,
		std::string sity);

	void setInformation(std::string info);
	void setHobbies(uint8_t count, ...);
	void setBadHobbies(uint8_t count, ...);
	void setRequiredHobbies(uint8_t count, ...);
	void setRequiredBadHobbies(uint8_t count, ...);

	bool operator==(const People& obj);
};

