#ifndef Superfield_h
#define Superfield_h

#include "Field.h"
#include <memory>

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
		std::shared_ptr<Scalar> phi_ ; 
		std::shared_ptr<Spinor> psi_ ; 
	public:
		ChiralSF() ; 
		ChiralSF(std::string name, std::shared_ptr<Scalar> phi, std::shared_ptr<Spinor> psi) ; 
		ChiralSF(std::string name, std::vector<double> charge, Symmetries sym) ; 
		~ChiralSF() ; 

		bool IsChiral() const {return true;} ; 
		std::vector<double> Getcharge() const {return phi_->Getcharge() ;} ;
		Symmetries GetSymmetry() const {return phi_->GetSymmetry() ;} ;
		std::shared_ptr<Scalar> GetScalar() const {return phi_;} ; 
		std::shared_ptr<Spinor> GetSpinor() const {return psi_;} ; 
} ;

class VectorSF: public Superfield {
	private:
		std::shared_ptr<Vector> vmu_ ; 
		std::shared_ptr<Spinor> psi_ ; 
	public:
		VectorSF() ; 
		VectorSF(std::string name, std::shared_ptr<Vector> vmu, std::shared_ptr<Spinor> psi) ; 
		VectorSF(std::string name, std::vector<double> charge, Symmetries sym) ; 
		~VectorSF() ; 

		bool IsChiral() const {return false;} ; 
		std::vector<double> Getcharge() const {return vmu_->Getcharge() ;} ;
		Symmetries GetSymmetry() const {return vmu_->GetSymmetry() ;} ;
		std::shared_ptr<Vector> GetVector() const {return vmu_;} ; 	
		std::shared_ptr<Spinor> GetSpinor() const {return psi_;} ; 	
} ; 
#endif
