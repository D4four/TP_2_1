#include "Train.h"

price::price()
{
	cout << "price constructor called" << endl;
	nextPtr = nullptr;
}

string price::getVisit()
{
	return prop[VISIT];
}
string price::getArrival()
{
	return prop[ARRIVAL];
}
string price::getTrain()
{
	return prop[TRAIN];
}
price* price::getNextPtr()
{
	return nextPtr;
}

void price::setVisit(string str)
{
	prop[VISIT] = str;
}
void price::setArrival(string str)
{
	prop[ARRIVAL] = str;
}
void price::setTrain(string str)
{
	prop[TRAIN] = str;
}
void price::setNextPtr(price* p)
{
	nextPtr = p;
}
