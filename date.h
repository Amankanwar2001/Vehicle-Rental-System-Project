#ifndef Date_h
#define Date_h

#include "storable.cpp"

#include<ctime>
#include<string>

using namespace std;

typedef struct Date : Serializable{
private:
	// structure holding date & time info

	struct tm date;

	bool empty;

public:
	// constructor, create date from string
	Date(string date);

	// create date from current time
	Date();

	// add given number of days in this date
	Date operator + (int days);

	// If this date is greater than given date
	bool operator > (Date date) const;

	// If this date is greater than or equal to given date
	bool operator >= (Date date) const;

	// If this date is less than given date
	bool operator < (Date date) const;

	// if this date is less than equal tot given date
	bool operator <= ( Date date) const;

	bool isEmpty() const;
	string toString() const;
} Date;

#endif
