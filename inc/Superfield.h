#ifndef Superfield_h
#define Superfield_h

#include "Field.h"

class Superfield {
	protected:
		std::string name_ ;
	public: 
		Superfield(){} ; 
		Superfield(std::string name): name_(name) {}; 
		virtual ~Superfield(){} ; 

		std::string Getname() const {return name_ ;} ;

		void Setname(std::string name) {name_ = name ;} ;

		virtual bool IsChiral() const = 0 ; 
		virtual std::vector<double> Getcharge() const = 0 ;
		virtual Symmetries GetSymmetry() const = 0 ;
} ; 


class ChiralSF: public Superfield {
	private:
		Scalar* phi_ ; 
		Spinor* psi_ ; 
	public:
		ChiralSF() ; 
		ChiralSF(std::string name, Scalar* phi, Spinor* psi) ; 
		ChiralSF(std::string name, std::vector<double> charge, Symmetries sym) ; 
		~ChiralSF() ; 

		bool IsChiral() const {return true;} ; 
		std::vector<double> Getcharge() const {return phi_->Getcharge() ;} ;
		Symmetries GetSymmetry() const {return phi_->GetSymmetry() ;} ;
		
} ;

class VectorSF: public Superfield {
	private:
		Vector* vmu_ ; 
		Spinor* psi_ ; 
	public:
		VectorSF() ; 
		VectorSF(std::string name, Vector* vmu, Spinor* psi) ; 
		VectorSF(std::string name, std::vector<double> charge, Symmetries sym) ; 
		~VectorSF() ; 

		bool IsChiral() const {return false;} ; 
		std::vector<double> Getcharge() const {return vmu_->Getcharge() ;} ;
		Symmetries GetSymmetry() const {return vmu_->GetSymmetry() ;} ;
		
} ; 
#endif