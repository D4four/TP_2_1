#pragma once
#pragma once
#include "Train.h"
#include <string>

template <typename T>
void mcin(T* _x);

class myList
{
	int size = 0;
	price* HEAD;
	price* LAST;
	bool a_to_z_flag;

	price* operator[](int idx);
	void sort();

public:

	myList();

	void flipFlag();
	void seeFlag();
	void bestEarly();

	void add();
	void print();
	void del();
	void edit();
	void findTrain();

};