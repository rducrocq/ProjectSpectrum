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

typedef std::function<double(std::map<std::string, double>)> RGE ; 

class Coupling {
	protected:
		RGE rge_ ;
		double value_EW_  ; 
		double value_GUT_  ; 
		double value_SUSY_  ;  
		double current_value_ = value_EW_ ;
		std::string name_ ; 
	public:
		Coupling(){} ; 
		Coupling(RGE rge, double value_EW, std::string name): rge_(rge)
							, value_EW_(value_EW)
							, value_GUT_(0)
							, value_SUSY_(0)
							, name_(name) {std::cout << "In Coupling EW : " << value_SUSY_ << std::endl ; } ; 
		Coupling(RGE rge, double value_EW, double value_GUT, double value_SUSY, std::string name): rge_(rge)
							, value_EW_(value_EW)
							, value_GUT_(value_GUT)
							, value_SUSY_(value_SUSY)
							, name_(name) {} ; 
		Coupling(const Coupling& cpl) ; 
		virtual ~Coupling(){} ; 

		void SetRGE(RGE rge) {rge_ = rge; } ;
		void SetValue_EW(double value_EW) {value_EW_ = value_EW; } ;
		void SetValue_SUSY(double value_SUSY) {value_SUSY_ = value_SUSY; } ;
		void SetValue_GUT(double value_GUT) {value_GUT_ = value_GUT; } ;
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
		std::shared_ptr<Symmetry> sym_ ; 
	public: 
		GaugeCoupling() : Coupling() {} ;
		GaugeCoupling(std::shared_ptr<Symmetry>& sym, RGE rge, double value_EW, std::string name) ; 
		GaugeCoupling(std::shared_ptr<Symmetry>& sym, RGE rge, double value_EW, double value_SUSY, double value_GUT, std::string name) ; 
		GaugeCoupling(const GaugeCoupling& g_cpl) ;
		virtual ~GaugeCoupling() {} ;

		std::shared_ptr<Symmetry> GetSymmetry() const {return sym_;} ; 
		void SetSymmetry(std::shared_ptr<Symmetry> sym) {sym_ = sym;} ; 
} ;

class FieldCoupling: public Coupling {
	private:
		std::shared_ptr<std::vector<std::shared_ptr<Field>>> fields_ ; 
	public:
		FieldCoupling() {} ; 
		FieldCoupling(std::shared_ptr<std::vector<std::shared_ptr<Field>>>& fields, RGE rge, double value_EW, std::string name) ; 
		FieldCoupling(std::shared_ptr<std::vector<std::shared_ptr<Field>>>& fields, RGE rge, double value_EW, double value_SUSY, double value_GUT, std::string name) ; 
		FieldCoupling(const FieldCoupling& f_cpl) ; 
		virtual ~FieldCoupling() {} ;

		std::shared_ptr<std::vector<std::shared_ptr<Field>>> GetFields() const {return fields_;} ; 
		void SetFields(std::vector<std::shared_ptr<Field>>& fields) {fields_ = std::make_shared<std::vector<std::shared_ptr<Field>>>(fields);} ; 
} ; 

class SFCoupling: public Coupling {
	private:
		std::shared_ptr<std::vector<std::shared_ptr<Superfield>>> superfields_ ; 
	public:
		SFCoupling() {} ; 
		SFCoupling(std::shared_ptr<std::vector<std::shared_ptr<Superfield>>>& superfields, RGE rge, double value_EW, std::string name) ; 
		SFCoupling(std::shared_ptr<std::vector<std::shared_ptr<Superfield>>>& superfields, RGE rge, double value_EW, double value_SUSY, double value_GUT, std::string name) ; 
		SFCoupling(const SFCoupling& sf_cpl) ; 
		SFCoupling(std::shared_ptr<SFCoupling>& sf_cpl) ;
		virtual ~SFCoupling() {} ;

		std::shared_ptr<std::vector<std::shared_ptr<Superfield>>> GetSuperFields() const {return superfields_;} ; 
		void SetSuperFields(std::vector<std::shared_ptr<Superfield>>& superfields) {superfields_ = std::make_shared<std::vector<std::shared_ptr<Superfield>>>(superfields);} ; 
} ; 

#endif
