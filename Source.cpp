#include <string>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include "conio.h"
#include <stdio.h>

#include "windows.h"

#include "Source.h"

using namespace std::chrono;

time_point<system_clock> now = system_clock::now(); //getting current time


int main()
{
	Source source;
	int userSelection;
	int maxChoice = 4;

	do { //do these steps until user enters 4

		/* Display message until key is pressed. */
		while (!_kbhit()) { //while loop resets clock every second
			system("cls"); //clear screen

			source.printClock();

			source.printMenu();

			source.addSecond(); //keeps adding one second every 1 second using sleep()

			Sleep(1000); //program sleeps for 1000 milliseconds = 1 second
		}

		cin >> userSelection;

		while (userSelection < 1 || userSelection > maxChoice) { //if user enters value higher than 4 then they are asked to input again
			cout << "Invalid Choice. Enter a number between 1 and 4" << endl;
			cout << endl;
			cin >> userSelection;
		}

		switch (userSelection) {
		case 1:
			source.addHour();
			break;
		case 2:
			source.addMinute();
			break;
			//skipped case 3 because one second is already added every second
		case 4:
			return 0;
			break;
		default: "Not valid option";
		}

	} while (userSelection != 4);

	return 0;
}

void Source::addHour() {
	now += hours{ 1 }; //adds one hour to time_point now
}

void Source::addMinute() {
	now += minutes{ 1 }; //adds one minute to time_point now
}

void Source::addSecond() {
	now += seconds{ 1 }; //adds one second to time_point now
}


std::string Source::timeFormat24() {
	// convert to std::time_t in order to convert to std::tm (broken time)
	auto timer = system_clock::to_time_t(now);

	// convert to broken time
	std::tm bt;


	localtime_s(&bt, &timer);

	std::ostringstream oss;

	oss << std::put_time(&bt, "%H:%M:%S"); // 24 hour format

	return oss.str();
}

std::string Source::timeFormat12() {
	auto timer = system_clock::to_time_t(now);

	// convert to broken time
	std::tm bt;


	localtime_s(&bt, &timer);

	std::ostringstream oss;

	oss << std::put_time(&bt, "%I:%M:%S %p"); // 12 hour format with pm/am

	return oss.str();
}



std::string nCharString(size_t n, char c) {
	// return the n character string
	std::string str;

	for (size_t i = 0; i < n; i++) { //for loop for size of n
		str += c; //add character to empty string
	}

	return str;
}


//Prints menu
void Source::printMenu() {
	std::cout << nCharString(27, '*') << std::endl;
	std::cout << "* 1 - Add One Hour" << nCharString(8, ' ') << "*" << std::endl;
	std::cout << std::endl;
	std::cout << "* 2 - Add One Minute" << nCharString(6, ' ') << "*" << std::endl;
	std::cout << std::endl;
	std::cout << "* 3 - Add One Second" << nCharString(6, ' ') << "*" << std::endl;
	std::cout << std::endl;
	std::cout << "* 4 - Exit Program" << nCharString(8, ' ') << "*" << std::endl;
	std::cout << nCharString(27, '*');
	std::cout << std::endl;
}

void Source::printClock() {
	std::cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << std::endl;
	std::cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*" << nCharString(3, ' ');
	std::cout << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << std::endl;
	std::cout << std::endl;
	std::cout << "*" << nCharString(6, ' ')<< timeFormat12() << nCharString(8, ' ') << "*" << nCharString(3, ' ');
	std::cout << "*" << nCharString(8, ' ') << timeFormat24() << nCharString(10, ' ') << "*" << std::endl;
	std::cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << std::endl;
	std::cout << std::endl;
}


