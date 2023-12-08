#ifndef Coupling_h
#define Coupling_h

#include <string>
#include <iostream>
#include <functional>
#include <map>
#include "../inc/Symmetry.h"
#include "../inc/Field.h"
#include "../inc/Superfield.h"
#include <memory>

typedef std::function<double(std::map<std::string, double>&)> RGE ; 

class Coupling {
	protected:
		const RGE& rge_ ;
		double value_EW_ = 0 ; 
		double value_GUT_ = 0 ; 
		double value_SUSY_ = 0  ;  
		double current_value_ = value_EW_ ;
		std::string name_ ; 
	public:
		Coupling(const RGE& rge, double value_EW, std::string name): rge_(rge)
							, value_EW_(value_EW)
							, value_GUT_(0)
							, value_SUSY_(0)
							, name_(name) {} ; 
		Coupling(const RGE& rge, double value_EW, double value_GUT, double value_SUSY, std::string name): rge_(rge)
							, value_EW_(value_EW)
							, value_GUT_(value_GUT)
							, value_SUSY_(value_SUSY)
							, name_(name) {} ; 
		Coupling(const Coupling& cpl) ; 
		virtual ~Coupling(){} ; 

		void SetCurrentValue(double value) {current_value_ = value; } ;

		RGE GetRGE() const {return rge_;} ; 
		double GetValue_EW() const {return value_EW_;} ; 
		double GetValue_SUSY() const {return value_SUSY_;} ; 
		double GetValue_GUT() const {return value_GUT_;} ; 
		double GetCurrentValue() const {return current_value_;} ; 
		std::string Getname() const {return name_;} ;
		
} ; 

class GaugeCoupling: public Coupling {
	private: 
		const Symmetry& sym_ ; 
	public: 
		GaugeCoupling(const Symmetry& sym, const RGE& rge, double value_EW, std::string name) ; 
		GaugeCoupling(const Symmetry& sym, const RGE& rge, double value_EW, double value_SUSY, double value_GUT, std::string name) ; 
		virtual ~GaugeCoupling() {} ;

		const Symmetry& GetSymmetry() const {return sym_;} ; 
} ;


class FieldCoupling: public Coupling {
	private:
		std::vector<std::shared_ptr<Field>> fields_ ; 
	public:
		FieldCoupling(std::vector<std::shared_ptr<Field>> fields, const RGE& rge, double value_EW, std::string name) ; 
		FieldCoupling(std::vector<std::shared_ptr<Field>> fields, const RGE& rge, double value_EW, double value_SUSY, double value_GUT, std::string name) ; 
		FieldCoupling(FieldCoupling& f_cpl) ; 
    	// Move constructor
   		FieldCoupling(FieldCoupling&& other) noexcept : Coupling(std::move(other)), fields_(std::move(other.fields_)) {} ; 

		virtual ~FieldCoupling() {} ;

		const std::vector<std::shared_ptr<Field>>& GetFields() const {return fields_;} ; 
} ; 

class SFCoupling: public Coupling {
	private:
		std::vector<std::shared_ptr<Superfield>> superfields_ ; 
	public:
		SFCoupling(std::vector<std::shared_ptr<Superfield>> superfields, const RGE& rge, double value_EW, std::string name) ; 
		SFCoupling(std::vector<std::shared_ptr<Superfield>> superfields, const RGE& rge, double value_EW, double value_SUSY, double value_GUT, std::string name) ; 
		SFCoupling(SFCoupling& sf_cpl) ; 
    	// Move constructor
   		SFCoupling(SFCoupling&& other) noexcept : Coupling(std::move(other)), superfields_(std::move(other.superfields_)) {} ; 

		virtual ~SFCoupling() {} ;

		const std::vector<std::shared_ptr<Superfield>>& GetSuperFields() const {return superfields_;} ; 
} ; 

class SoftCoupling: public Coupling {
	private:
		std::vector<std::shared_ptr<Superfield>> superfields_ ; 
	public:
		SoftCoupling(std::vector<std::shared_ptr<Superfield>> superfields, const RGE& rge, double value_EW, std::string name) ; 
		SoftCoupling(std::vector<std::shared_ptr<Superfield>> superfields, const RGE& rge, double value_EW, double value_SUSY, double value_GUT, std::string name) ; 
		SoftCoupling(SoftCoupling& sf_cpl) ; 
    	// Move constructor
   		SoftCoupling(SoftCoupling&& other) noexcept : Coupling(std::move(other)), superfields_(std::move(other.superfields_)) {} ; 

		virtual ~SoftCoupling() {} ;

		const std::vector<std::shared_ptr<Superfield>>& GetSuperFields() const {return superfields_;} ; 
} ; 

#endif
