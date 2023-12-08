#ifndef Superfield_h
#define Superfield_h

#include "Field.h"
#include <memory>

class Superfield {
	protected:
		std::string name_ ;
	public: 
		Superfield(std::string name): name_(name) {}; 
		virtual ~Superfield(){} ; 

		std::string Getname() const {return name_ ;} ;

		void Setname(std::string name) {name_ = name ;} ;

		virtual bool IsChiral() const = 0 ; 
		virtual std::vector<double> Getcharge() const = 0 ;
		virtual const Symmetries& GetSymmetry() const = 0 ;
} ; 


class ChiralSF: public Superfield {
	private:
		std::unique_ptr<Scalar> phi_ ; 
		std::unique_ptr<Spinor> psi_ ; 
	public:
		ChiralSF(std::string name, std::unique_ptr<Scalar> phi, std::unique_ptr<Spinor> psi) ; 
		ChiralSF(std::string name, std::vector<double> charge, const Symmetries& sym) ; 
		~ChiralSF() ; 

		bool IsChiral() const {return true;} ; 
		std::vector<double> Getcharge() const {return phi_->Getcharge() ;} ;
		const Symmetries& GetSymmetry() const {return phi_->GetSymmetry() ;} ;
		const Scalar& GetScalar() const {return *phi_;} ; 
		const Spinor& GetSpinor() const {return *psi_;} ; 
} ;

class VectorSF: public Superfield {
	private:
		std::unique_ptr<Vector> vmu_ ; 
		std::unique_ptr<Spinor> psi_ ; 
	public:
		VectorSF(std::string name, std::unique_ptr<Vector> vmu, std::unique_ptr<Spinor> psi) ; 
		VectorSF(std::string name, std::vector<double> charge, const Symmetries& sym) ; 
		~VectorSF() ; 

		bool IsChiral() const {return false;} ; 
		std::vector<double> Getcharge() const {return vmu_->Getcharge() ;} ;
		const Symmetries& GetSymmetry() const {return vmu_->GetSymmetry() ;} ;
		const Vector& GetVector() const {return *vmu_;} ; 	
		const Spinor& GetSpinor() const {return *psi_;} ; 	
} ; 
#endif
