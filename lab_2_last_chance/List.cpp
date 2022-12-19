#include "List.h"
#include <Windows.h>
template <typename T>
void mcin(T* _x)
{
	while (true)
	{
		cin >> *_x;
		if (std::cin.good())
			break;

		cout << "invalid input" << std::endl;
		cin.clear();
		cin.ignore();
	}
}

price* myList::operator[](int idx)
{
	if (idx < 0 || idx > size)
	{
		return nullptr;
	}

	price* ptr = HEAD;

	int count = 0;
	while (count != idx)
	{
		ptr = ptr->getNextPtr();
		count++;
	}

	return ptr;
}

void myList::sort()
{
	if (size == 1)
		return;

	price* p = HEAD->getNextPtr();
	price* prev = HEAD;
	int count = 1;
	while (count != size)
	{
		int state = strcmp(p->getArrival().c_str(), p->getNextPtr()->getArrival().c_str());
		bool isToSort = (a_to_z_flag == true) ? (state > 0) : (state < 0);
		if (isToSort)
		{
			// поменять местами
			price* ptr0 = (*this)[count - 1];
			price* ptr1 = (*this)[count];
			price* ptr2 = (*this)[count + 1];
			price* ptr3 = (*this)[count + 2];

			ptr0->setNextPtr(ptr2);
			ptr1->setNextPtr(ptr3);
			ptr2->setNextPtr(ptr1);

			if (LAST == ptr2)
				LAST = ptr1;

			count = 1;
			p = HEAD->getNextPtr();
			prev = HEAD;
		}
		else
		{
			p = p->getNextPtr();
			prev = prev->getNextPtr();
			count++;
		}
	}
}




myList::myList()
{
	cout << "myList constructor called" << endl;
	size = 0;
	HEAD = new price;
	LAST = HEAD;
	a_to_z_flag = true;
}

void myList::flipFlag()
{
	a_to_z_flag = !a_to_z_flag;
	if (size > 0) sort();
}

void myList::seeFlag()
{
	cout << "\tsorting setting:";
	if (a_to_z_flag)
		cout << "\t0 to 9" << endl;
	else
		cout << "\t9 to 0" << endl;
}




void myList::add()
{
	system("cls");
	cout << "\tadding new record" << endl;
	price* add_obj = new price;
	cin >> *add_obj;
	LAST->setNextPtr(add_obj);
	LAST = add_obj;
	size++;
	sort();
	cout << "\tadded" << endl;
}

void myList::print()
{
	system("cls");
	if (size == 0)
		cout << endl << "\tno objects added yet" << endl;
	else
		cout << endl << "\tALL OBJECTS" << endl;
	price* p = HEAD->getNextPtr();
	while (p != nullptr)
	{
		cout << *p << endl;
		p = p->getNextPtr();
	}
	system("pause");
}


void myList::del()
{
	cout << "\tdeleting" << endl;
	if (size == 0)
		throw 0;

	cout << "\tthere are " << size << " records, choose one to delete (index from 1 to " << size << ") : ";

	int idx;
	mcin(&idx);
	if (idx < 0 || idx > size)
		throw - 1;

	price* prev = (*this)[idx - 1];

	if (idx == size)
	{
		delete LAST;
		LAST = prev;
		LAST->setNextPtr(nullptr);
		size--;
		return;
	}

	price* curr = (*this)[idx];
	price* next = (*this)[idx + 1];

	delete curr;
	prev->setNextPtr(next);

	cout << "\tdeleted" << endl;
	size--;
	sort();
}

void myList::edit()
{
	system("cls");
	cout << "\tEditing" << endl;
	if (size == 0)
		throw 0;

	cout << "\tthere are " << size << " records, choose one to delete (index from 1 to " << size << ") : ";

	int idx;
	mcin(&idx);
	if (idx < 0 || idx > size)
		throw - 1;


	price* curr = (*this)[idx];
	cout << "\tenter new values for this object" << endl;
	cin >> *curr;

	cout << "\tedited" << endl;
	sort();
}

void myList::findTrain()
{
	system("cls");

	if (size == 0)
		throw 0;

	string searchVisit;
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\tVisit name to search: ";
	cin.clear();
	cin.ignore();
	getline(cin, searchVisit);
	int flag = 0;
	price* p = HEAD->getNextPtr();
	while (p != nullptr)
	{
		if (p->getVisit() == searchVisit)
		{

			cout << "Time arrival "; SetConsoleTextAttribute(h, 4);
			cout << p->getArrival(); SetConsoleTextAttribute(h, 15);
			cout << " number of train "; SetConsoleTextAttribute(h, 4);
			cout << p->getTrain() << endl; SetConsoleTextAttribute(h, 15);
			flag = 1;
		}


		p = p->getNextPtr();
	}
	SetConsoleTextAttribute(h, 15);
	if ((p == nullptr) && (flag == 0)) cout << "No tarins found" << endl;
	cout << "\tSearch finished" << endl;
	system("pause");
}


void myList::bestEarly()
{
	system("cls");

	if (size == 0)
		throw 0;

	string searchTrain;
	string bestTrain;
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\tVisit : ";
	cin.clear();
	cin.ignore();
	getline(cin, searchTrain);
	int flag = 0; int min = INT_MAX;
	string t;
	price* p = HEAD->getNextPtr();

	while (p != nullptr)
	{
		if ((p->getVisit()) == searchTrain) {
			if (stoi((p->getArrival())) < min) {
				min = stoi(p->getArrival());
				t = p->getArrival();
				flag = 1;
				bestTrain = p->getTrain();
			}
		}
		p = p->getNextPtr();
	}
	if ((p == nullptr) && (flag == 0)) cout << "No such product was found" << endl;
	else {
		cout << "Visit on "; SetConsoleTextAttribute(h, 4);
		cout << t; SetConsoleTextAttribute(h, 15);
		cout << " earlist \""; SetConsoleTextAttribute(h, 4);
		cout << bestTrain;  SetConsoleTextAttribute(h, 15); cout << "\"" << endl;
	}

}