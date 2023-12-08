#include "../inc/Field.h"
#include <iostream>

Field::Field(std::string name, std::vector<double> charge,  const Symmetries& sym) : sym_(sym) {
	name_ = name ; 
	charge_ = charge ; 
	vev_ = 0 ; 
	if (charge_.size() != sym.GetSizeSymmetries()) {
		std::cerr << "In definition of Field " << name_ << ":\n\tProblem of dimensionality between the charges and the symmetries!" << std::endl ; 
		}
}; 

Field::Field(std::string name, std::vector<double> charge,  const Symmetries& sym, double vev) : sym_(sym)  {
	name_ = name ; 
	charge_ = charge ; 
	vev_ = vev ; 
	if (charge_.size() != sym_.GetSizeSymmetries()) {
		std::cerr << "In definition of Field " << name_ << ":\n\tProblem of dimensionality between the charges and the symmetries!" << std::endl ; 
		}
}; 

Field::Field(const Field& field) :  name_(field.name_),
									charge_(field.charge_),
									vev_(field.vev_), 
									sym_(field.sym_) {} ; 

Scalar::Scalar(std::string name, std::vector<double> charge,  const Symmetries& sym): Field::Field(name,charge,sym){}; 

Scalar::Scalar(std::string name, std::vector<double> charge,  const Symmetries& sym, double vev):  Field::Field(name,charge,sym,vev){}; 

Scalar::Scalar(const Scalar& phi) :  Field(phi.name_, phi.charge_, phi.sym_, phi.vev_) {} ; 

Spinor::Spinor(std::string name, std::vector<double> charge,  const Symmetries& sym): Field::Field(name,charge,sym){}; 

Spinor::Spinor(std::string name, std::vector<double> charge,  const Symmetries& sym, double vev):  Field::Field(name,charge,sym,vev){}; 

Spinor::Spinor(const Spinor& psi) :  Field(psi.name_, psi.charge_, psi.sym_, psi.vev_) {} ; 

Vector::Vector(std::string name, std::vector<double> charge,  const Symmetries& sym): Field::Field(name,charge,sym){}; 

Vector::Vector(std::string name, std::vector<double> charge,  const Symmetries& sym, double vev):  Field::Field(name,charge,sym,vev){}; 

Vector::Vector(const Vector& Amu) :  Field(Amu.name_, Amu.charge_, Amu.sym_, Amu.vev_) {} ; 