#ifndef HOROSCOPE
#define HOROSCOPE

#define VERSION "1.0"

#define MAN 1
#define WOMEN 0

#define ARIES 1
#define TAURUS 2
#define GEMINI 3
#define CANCER 4
#define LEO 5
#define VIRGO 6
#define LIBRA 7
#define SCORPIO 8
#define SAGITTARIUS 9
#define CAPRICORN 10
#define AQUARIUS 11
#define PISCES 12

#define WATER 1 
#define FIRE 2
#define EARTH 3 
#define AIR 4 

struct People
{
	int date;
	int month;
	int sex;
	int sign;
	int element;
};

void showMenuText();
void setVars(int* date, int* month, int* sex);
void setPeople(struct People* people, int date, int month, int sex);
void showSign(struct People people);
void isFriendshipPossible(struct People first, struct People second);
void isBusinessPossible(struct People first, struct People second);
void isMarriagePossible(struct People first, struct People second);
void showInfo();

#endif
