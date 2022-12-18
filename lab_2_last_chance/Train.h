#include <iostream>
#include <string>

#define VISIT 0 //product
#define ARRIVAL 1 //store
#define TRAIN 2 //price

using namespace std;



class price
{
	string prop[3];
	price* nextPtr;

public:

	price();

	string getVisit();
	string getArrival();
	string getTrain();
	price* getNextPtr();

	void setVisit(string str);
	void setArrival(string str);
	void setTrain(string str);
	void setNextPtr(price* p);

	friend std::ostream& operator<<(std::ostream& os, const price& p)
	{
		return os << "Product name: " << p.prop[VISIT] << "\nStore name: " << p.prop[ARRIVAL] << "\nProduct value: " << p.prop[TRAIN] << endl;
	}

	friend std::istream& operator>>(std::istream& in, price& p)
	{
		std::cout << "Visit name: ";
		in.clear();
		in.ignore();
		getline(in, p.prop[VISIT]);

		std::cout << "Arrival name: ";
		in.clear();
		getline(in, p.prop[ARRIVAL]);

		/*std::cout << "Arrival value: ";

		string str;
		while (1) {
			std::cin >> str;
			if (!str.empty() && str.find_first_not_of("0123456789") == std::string::npos) {
				p.prop[ARRIVAL] = str;
				break;
			}
			else {
				cout << "Error input , please repeat input (Only numbers)\n";
				continue;
			}
		}
		in.clear();
		in.ignore();*/

		string str;

		std::cout << "Train value: ";

		//string str;
		while (1) {
			std::cin >> str;
			if (!str.empty() && str.find_first_not_of("0123456789") == std::string::npos) {
				p.prop[TRAIN] = str;
				break;
			}
			else {
				cout << "Error input , please repeat input (Only numbers)\n";
				continue;
			}
		}
		in.clear();
		in.ignore();

		in.sync();

		return in;
	}

};
