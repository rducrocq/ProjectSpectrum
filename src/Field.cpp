#include "../inc/Field.h"
#include <iostream>

Field::Field(std::string name, std::vector<double> charge, Symmetries sym) {
	name_ = name ; 
	charge_ = charge ; 
	vev_ = 0 ; 
	sym_ = sym ; 
//	assert(charge_.size == sym_.size) ; 
	if (charge_.size() != sym.GetSizeSymmetries()) {
		std::cerr << "In definition of Field " << name_ << ":\n\tProblem of dimensionality between the charges and the symmetries!" << std::endl ; 
		}
}; 

Field::Field(std::string name, std::vector<double> charge, Symmetries sym, double vev) {
	name_ = name ; 
	charge_ = charge ; 
	vev_ = vev ; 
	sym_ = sym ; 
//	assert(charge_.size == sym_.size) ; 
	if (charge_.size() != sym_.GetSizeSymmetries()) {
		std::cerr << "In definition of Field " << name_ << ":\n\tProblem of dimensionality between the charges and the symmetries!" << std::endl ; 
		}
}; 

Field::Field(const Field& field) : Field() {
	name_ = field.name_ ;
	charge_ = field.charge_ ; 
	vev_ = field.vev_ ; 
	sym_ = field.sym_ ; 
	}

Scalar::Scalar(std::string name, std::vector<double> charge, Symmetries sym): Field::Field(name,charge,sym){}; 

Scalar::Scalar(std::string name, std::vector<double> charge, Symmetries sym, double vev):  Field::Field(name,charge,sym,vev){}; 

Scalar::Scalar(const Scalar& phi) : Scalar() {
	name_ = phi.name_ ;
	charge_ = phi.charge_ ; 
	vev_ = phi.vev_ ; 
	sym_ = phi.sym_ ; 
	}

Scalar::Scalar(std::shared_ptr<Scalar>& phi) : Scalar() {
	name_ = phi->name_ ;
	charge_ = phi->charge_ ; 
	vev_ = phi->vev_ ; 
	sym_ = phi->sym_ ; 
}

Spinor::Spinor(std::string name, std::vector<double> charge, Symmetries sym): Field::Field(name,charge,sym){}; 

Spinor::Spinor(std::string name, std::vector<double> charge, Symmetries sym, double vev):  Field::Field(name,charge,sym,vev){}; 

Spinor::Spinor(const Spinor& psi) : Spinor() {
	name_ = psi.name_ ;
	charge_ = psi.charge_ ; 
	vev_ = psi.vev_ ; 
	sym_ = psi.sym_ ; 
	}

Spinor::Spinor(std::shared_ptr<Spinor>& psi) : Spinor() {
	name_ = psi->name_ ;
	charge_ = psi->charge_ ; 
	vev_ = psi->vev_ ; 
	sym_ = psi->sym_ ; 
}

Vector::Vector(std::string name, std::vector<double> charge, Symmetries sym): Field::Field(name,charge,sym){}; 

Vector::Vector(std::string name, std::vector<double> charge, Symmetries sym, double vev):  Field::Field(name,charge,sym,vev){}; 

Vector::Vector(const Vector& Amu) : Vector() {	
	name_ = Amu.name_ ;
	charge_ = Amu.charge_ ; 
	vev_ = Amu.vev_ ; 
	sym_ = Amu.sym_ ; 
	}

Vector::Vector(std::shared_ptr<Vector>& Amu) : Vector() {
	name_ = Amu->name_ ;
	charge_ = Amu->charge_ ; 
	vev_ = Amu->vev_ ; 
	sym_ = Amu->sym_ ; 
}