#pragma once
#include <string>
//angelica nuesi
using namespace std;

class Source {
public:
	std::string timeFormat24();
	std::string timeFormat12();
	void printMenu();
	void printClock();
	void addHour();
	void addSecond();
	void addMinute();
};