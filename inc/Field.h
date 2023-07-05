#ifndef Field_h
#define Field_h

#include <string>
#include <vector>

class Field {
	protected: 
		std::string name_ ; 
		std::vector<int> charge_ ; 
		double vev_ ; 
	public: 
		Field(){}; 
		Field(std::string name, std::vector<int> charge) ; 
		Field(std::string name, std::vector<int> charge, double vev) ; 
		~Field(){} ; 

		std::string Getname() const {return name_;}; 	
		std::vector<int> Getcharge() const {return charge_;}; 
		double Getvev() const {return vev_;}; 

		void Setname(std::string name) {name_ = name ;}; 
		void Setcharge(std::vector<int> charge) {charge_ = charge ;}; 
		void Setvev(double vev) {vev_ = vev;}; 

		virtual double Getspin() const = 0 ; 
} ;

class Scalar: public Field {
	public: 
		Scalar(): Field() {} ; 
		Scalar(std::string name, std::vector<int> charge) ; 
		Scalar(std::string name, std::vector<int> charge, double vev) ; 
		~Scalar(){} ;

		virtual double Getspin() const {return 0 ;} ; 
} ; 

class Spinor: public Field {
	public: 
		Spinor(): Field() {} ; 
		Spinor(std::string name, std::vector<int> charge) ; 
		Spinor(std::string name, std::vector<int> charge, double vev) ; 
		~Spinor(){} ;

		virtual double Getspin() const {return 1./2. ;} ; 
} ; 

class Vector: public Field {
	public: 
		Vector(): Field() {} ; 
		Vector(std::string name, std::vector<int> charge) ; 
		Vector(std::string name, std::vector<int> charge, double vev) ; 
		~Vector(){} ;

		virtual double Getspin() const {return 1 ;} ; 
} ; 

#endif
