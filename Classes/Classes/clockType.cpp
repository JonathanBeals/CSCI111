#include "Header1.h"
#include <iostream>
/*
#include <stdio.h>

class clockType {
public:
	clockType();
	clockType(int, int, int);

	//getters
	void getTime(int&, int&, int&)const;
	int getHours()const;
	int getMinutes()const;
	int getSeconds()const;
	void printTime(); const;
	bool equalTime(const clockType&)const;

	//setters
	void setTime(int, int, int);
	void setHours(int);
	void setMin(int);
	void setSec(int);

	void incHours();
	void incMin();
	void incSec();
	*/

clockType::clockType() {
	hrs =min=secs = 0;
	}

clockType::clockType(int h, int m, int s) {
	setTime(h, m, s);
}

void clockType::setTime(int h, int m, int s) {
	if (h > 0 && h < 24)
		hrs = h;
	else 
		hrs = 0;

	if (m > 0 && m < 60)
		min = m;
	else 
		min = 0;

	if (s > 0 && s < 60)
		sec = s;
	else 
		sec = 0;
}

void clockType::incHours() {
	hrs++;
	if (hrs > 23)
		hrs = 0;
}

void incMin() {
	min++;
	if (min > 59)
		min = 0;
	incHours();
}
void incSec(); {
	sec++;
	if (sec > 59)
		sec = 0;
	incMin();
}

void clockType::setMin(int m) {
	if (m > 0 && m < 60)
		min = m;
	else
		min = 0;
}

void setSec

void clockType::getTime(int& h, int& m, int& s)const;
{
	h = hrs;
	m = mins;
	s = secs;
}
int clockType::getHours()const {
	return hrs;
}
int clockType::getMinutes()const {
	return mins;
}
int clockType::getSeconds()const {
	return secs;
}
void clockType::printTime()const {
	if (hrs < 10) { //hrs
		std::cout << 0 << hrs;
	}
	else 
		std::cout << hrs;
	std::cout << ":";

	if (hrs < 10) { //min
			std::cout << 0 << hrs;
		}
	else
		std::cout << hrs;
		std::cout << ":";

		if (hrs < 10) { //sec
		std::cout << 0 << hrs;
		}
		else
			std::cout << hrs;
			std::cout << ":";
}

bool clockType::equalTime(const clockType& oth)const {
	return (hrs == oth.hrs && mins == oth.mins && secs == oth.secs);
}