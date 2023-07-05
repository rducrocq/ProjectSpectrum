#include "../inc/Field.h"

Field::Field(std::string name, std::vector<int> charge) {
	name_ = name ; 
	charge_ = charge ; 
	vev_ = 0 ; 
}; 

Field::Field(std::string name, std::vector<int> charge, double vev) {
	name_ = name ; 
	charge_ = charge ; 
	vev_ = vev ; 
}; 

Scalar::Scalar(std::string name, std::vector<int> charge): Field::Field(name,charge){}; 
Scalar::Scalar(std::string name, std::vector<int> charge, double vev):  Field::Field(name,charge,vev){}; 

Spinor::Spinor(std::string name, std::vector<int> charge): Field::Field(name,charge){}; 
Spinor::Spinor(std::string name, std::vector<int> charge, double vev):  Field::Field(name,charge,vev){}; 

Vector::Vector(std::string name, std::vector<int> charge): Field::Field(name,charge){}; 
Vector::Vector(std::string name, std::vector<int> charge, double vev):  Field::Field(name,charge,vev){}; 

