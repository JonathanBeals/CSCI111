#pragma once
#ifndef clockType_h
#define clockType_h

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

private:
	int hrs, min, sec;
};

#endif /* clockType_h */