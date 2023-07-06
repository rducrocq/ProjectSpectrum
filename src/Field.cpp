#include "../inc/Field.h"

Field::Field(std::string name, std::vector<double> charge, Symmetries sym) {
	name_ = name ; 
	charge_ = charge ; 
	vev_ = 0 ; 
	sym_ = sym ; 
//	assert(charge_.size == sym_.size) ; 
	if (charge_.size() != sym_.size()) {
		std::cerr << "In definition of Field " << name_ << ":\n\tProblem of dimensionality between the charges and the symmetries!" << std::endl ; 
		}
}; 

Field::Field(std::string name, std::vector<double> charge, double vev, Symmetries sym) {
	name_ = name ; 
	charge_ = charge ; 
	vev_ = vev ; 
	sym_ = sym ; 
//	assert(charge_.size == sym_.size) ; 
	if (charge_.size() != sym_.size()) {
		std::cerr << "In definition of Field " << name_ << ":\n\tProblem of dimensionality between the charges and the symmetries!" << std::endl ; 
		}
}; 

Scalar::Scalar(std::string name, std::vector<double> charge, Symmetries sym): Field::Field(name,charge,sym){}; 
Scalar::Scalar(std::string name, std::vector<double> charge, Symmetries sym, double vev):  Field::Field(name,charge,sym,vev){}; 

Spinor::Spinor(std::string name, std::vector<double> charge, Symmetries sym): Field::Field(name,charge,sym){}; 
Spinor::Spinor(std::string name, std::vector<double> charge, Symmetries sym, double vev):  Field::Field(name,charge,sym,vev){}; 

Vector::Vector(std::string name, std::vector<double> charge, Symmetries sym): Field::Field(name,charge,sym){}; 
Vector::Vector(std::string name, std::vector<double> charge, Symmetries sym, double vev):  Field::Field(name,charge,sym,vev){}; 

