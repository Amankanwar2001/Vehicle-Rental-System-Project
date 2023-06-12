#include "vehicle.h"
#include "string_helper.h"

const char DELIMITER = ';';

Vehicle :: Vehicle(string registrationNumber,VehicleType type,int seats,string companyName,double pricePerKm,Date PUCExpirationDate,long recordId) : Storable(recordID){

	this->registrationNumber=registrationNumber;
	this->type=type;
	this->seats=seats;
	this->companyName=companyName;
	this->pricePerKm=pricePerKm;
	this->PUCExpirationDate=PUCExpirationDate;
}

string vehicle :: getRegistrationNumber()const{return this -> registrationNumber;}

VehicleType Vehicle :: getVehicleType()const{return this->type;}

int Vehicle :: getSeats()const{return this->seats;}

string Vehicle :: getCompanyName()const{return this->companyName;}

double Vehicle :: getPricePerKm()const{return this->pricePerKm;}

Date Vehicle :: setPUCExpirationDate()const{return this->PUCExpirationDate;}

void Vehicle :: setPricePerKm(double newPrice){this->pricePerKm=newPrice;}

string Vehicle :: getVehicleTypeName () const{
	switch (this->type){
	case VehicleType :: bike:
		return "Bike";
	case VehicleType :: car:
		return "Car";
	case VehicleType :: towera:
		return "Towera";
	default: return "";
	}
}

void Vehicle :: display()const{
	cout << "Vehicle Details : " << endl;
	cout << "Registration no : " << this->registrationNumber << endl;
	cout << "VehicleType : " << this->getVehicleTypeName() << endl;
	cout << "No of seats : " << this->seats << endl;
	cout << "Company name : " << this->companyName << endl;
	cout << "Price Per Km : " << this->pricePerKm << " Rs/Km" << endl;
	cout << "PUC Expiration date : " << this->PUCExpirationDate.toString() << endl;
}

string Vehicle :: toString()const{
	stringstream ss;
	ss << recordID << DELIMITER
	<< type << DELIMITER
	<< seats << DELIMITER
	<< companyName << DELIMITER
	<< to_string(pricePerKm)<< DELIMITER
	<< PUCExpirationDate.toString();

	return ss.str();
}

void Vehicle :: setDataFrom(Storable * s){
	Vehicle *v=dynamic_cast<Vehicle*>(s);

	if(v){
		this->registrationNumber=v->registrationNumber;
		this->type=v->type;
		this->seats=v->seats;
		this->companyName=v->companyName;
		this->pricePerKm=v->pricePerKm;
		this->PUCExpirationDate=v->PUCExpirationDate;
	}
}
