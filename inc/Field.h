#ifndef Field_h
#define Field_h

#include <string>
#include <vector>
#include "../inc/Symmetry.h"

class Field {
	protected: 
		std::string name_ ; 
		std::vector<double> charge_ ; 
		double vev_ ; 
		Symmetries sym_ ; 
	public: 
		Field(){}; 
		Field(std::string name, std::vector<double> charge, Symmetries sym) ; 
		Field(std::string name, std::vector<double> charge, Symmetries sym, double vev) ; 
		Field(const Field& field) ; 
		virtual ~Field(){} ; 

		std::string Getname() const {return name_;}; 	
		std::vector<double> Getcharge() const {return charge_;}; 
		Symmetries GetSymmetry() const {return sym_;} ; 
		double Getvev() const {return vev_;}; 

		void Setname(std::string name) {name_ = name ;}; 
		void Setcharge(std::vector<double> charge) {charge_ = charge ;}; 
		void Setvev(double vev) {vev_ = vev;}; 

		virtual double Getspin() const = 0 ; 
} ;

class Scalar: public Field {
	public: 
		Scalar(): Field() {} ; 
		Scalar(std::string name, std::vector<double> charge, Symmetries sym) ; 
		Scalar(std::string name, std::vector<double> charge, Symmetries sym, double vev) ; 
		Scalar(const Scalar& phi) ; 
		Scalar(std::shared_ptr<Scalar>& phi) ;
		~Scalar(){} ;

		virtual double Getspin() const {return 0 ;} ; 
} ; 

class Spinor: public Field {
	public: 
		Spinor(): Field() {} ; 
		Spinor(std::string name, std::vector<double> charge, Symmetries sym) ; 
		Spinor(std::string name, std::vector<double> charge, Symmetries sym, double vev) ; 
		Spinor(const Spinor& psi) ; 
		Spinor(std::shared_ptr<Spinor>& psi) ;
		~Spinor(){} ;

		virtual double Getspin() const {return 1./2. ;} ; 
} ; 

class Vector: public Field {
	public: 
		Vector(): Field() {} ; 
		Vector(std::string name, std::vector<double> charge, Symmetries sym) ; 
		Vector(std::string name, std::vector<double> charge, Symmetries sym, double vev) ; 
		Vector(const Vector& Amu) ; 
		Vector(std::shared_ptr<Vector>& Amu) ;
		~Vector(){} ;

		virtual double Getspin() const {return 1 ;} ; 
} ; 

#endif
