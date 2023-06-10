#ifndef storable_cpp
#define storable_cpp

// include custom headers

#include "serializable.cpp"

// Include standard cpp headers

#include <string>
#include <iostream>

using namespace std;

/* Storable is a class which can be stored in file 
   Anything which is staorable must have 'recordId' (used asa a unique key)
   It is derived from 'Serializable'. Anything which is 'Storable' must be  'Serializable'
   (must have 'toString' method)
*/

class Storable: public Serializable{
	protected:
		// unique recorId which acts as a primary key to find data.
		// This property is protected, so only derived class can access it directly

		long recordId;
	public:
		// constructor
		// input : recordId

		Storable(long recordId){ this -> recordId = recordId;};

		long getRecordId() const {return this -> recordId;};

		// pure virtual function
		// every subclass of this class must provide a sutable way to seet 'this' object from 'Storable *s'
		// this is similar to copy constructor

		virtual void setDataFrom(Storable *s) = 0;

		// Friend declaration
		// Table and Database can access private member of this class
		// Table class: It sets 'recordId' of object inside 'addNewRecord' method
		// Database class: It sets 'recordId' of object inside 'addNewRecord' method

		template<class T> friend class Table;

		friend class Database;
};

#endif
