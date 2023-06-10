// Include standard cpp headers

#include<string>
using namespace std;

/* This is serializable class and it is an abstract class 
	Any class derived from this class must implement 'toString' method
*/

class Serializable{
public:
	// pure virtual function
	// 'Serializable' class does not know what 'toString' method will do 
	// It is the responsibility of derived class to implement this method
	// Each derived class has its own 'toString' implementation.

	virtual string toString() const = 0;
};