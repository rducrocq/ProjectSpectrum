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
		const Symmetries& sym_ ; 
	public: 
		Field(std::string name, std::vector<double> charge, const Symmetries& sym) ; 
		Field(std::string name, std::vector<double> charge, const Symmetries& sym, double vev) ; 
		Field(const Field& field) ; 
		virtual ~Field(){} ; 

		std::string Getname() const {return name_;}; 	
		std::vector<double> Getcharge() const {return charge_;}; 
		const Symmetries& GetSymmetry() const {return sym_;} ; 
		double Getvev() const {return vev_;}; 

		virtual double Getspin() const = 0 ; 
} ;

class Scalar: public Field {
	public: 
		Scalar(std::string name, std::vector<double> charge, const Symmetries& sym) ; 
		Scalar(std::string name, std::vector<double> charge, const Symmetries& sym, double vev) ; 
		Scalar(const Scalar& phi) ; 
		~Scalar(){} ;

		virtual double Getspin() const {return 0 ;} ; 
} ; 

class Spinor: public Field {
	public:
		Spinor(std::string name, std::vector<double> charge, const Symmetries& sym) ; 
		Spinor(std::string name, std::vector<double> charge, const Symmetries& sym, double vev) ; 
		Spinor(const Spinor& psi) ; 
		~Spinor(){} ;

		virtual double Getspin() const {return 1./2. ;} ; 
} ; 

class Vector: public Field {
	public: 
		Vector(std::string name, std::vector<double> charge,  const Symmetries& sym) ; 
		Vector(std::string name, std::vector<double> charge,  const Symmetries& sym, double vev) ; 
		Vector(const Vector& Amu) ; 
		~Vector(){} ;

		virtual double Getspin() const {return 1 ;} ; 
} ; 

#endif
