#ifndef Coupling_h
#define Coupling_h

#include <string>
#include <iostream>
#include <functional>
#include "../inc/Symmetry.h"
#include "../inc/Field.h"
#include "../inc/Superfield.h"

typedef std::function<double(std::vector<double>)> RGE ; 

class Coupling {
	protected:
		RGE rge_ ;
		double value_EW_  ; 
		double value_GUT_  ; 
		double value_SUSY_  ;  
	public:
		Coupling(){} ; 
		Coupling(RGE rge, double value_EW): rge_(rge)
							, value_EW_(value_EW)
							, value_GUT_(0)
							, value_SUSY_(0) {std::cout << "In Coupling EW : " << value_SUSY_ << std::endl ; } ; 
		Coupling(RGE rge, double value_EW, double value_GUT, double value_SUSY): rge_(rge)
							, value_EW_(value_EW)
							, value_GUT_(value_GUT)
							, value_SUSY_(value_SUSY) {} ; 
		Coupling(const Coupling& cpl) ; 
		virtual ~Coupling(){} ; 

		void SetRGE(RGE rge) {rge_ = rge; } ;
		void SetValue_EW(double value_EW) {value_EW_ = value_EW; } ;
		void SetValue_SUSY(double value_SUSY) {value_SUSY_ = value_SUSY; } ;
		void SetValue_GUT(double value_GUT) {value_GUT_ = value_GUT; } ;

		RGE GetRGE() const {return rge_;} ; 
		double GetValue_EW() const {return value_EW_;} ; 
		double GetValue_SUSY() const {return value_SUSY_;} ; 
		double GetValue_GUT() const {return value_GUT_;} ; 

		
} ; 

class GaugeCoupling: public Coupling {
	private: 
		Symmetry* sym_ ; 
	public: 
		GaugeCoupling() : Coupling() {} ;
		GaugeCoupling(Symmetry& sym, RGE rge, double value_EW) ; 
		GaugeCoupling(Symmetry& sym, RGE rge, double value_EW, double value_SUSY, double value_GUT) ; 
		GaugeCoupling(const GaugeCoupling& g_cpl) ;
		virtual ~GaugeCoupling() {} ;

		Symmetry* GetSymmetry() const {return sym_;} ; 
		void SetSymmetry(Symmetry* sym) {sym_ = sym;} ; 
} ;

class FieldCoupling: public Coupling {
	private:
		std::vector<Field*>* fields_ ; 
	public:
		FieldCoupling() {} ; 
		FieldCoupling(std::vector<Field*>& fields, RGE rge, double value_EW) ; 
		FieldCoupling(std::vector<Field*>& fields, RGE rge, double value_EW, double value_SUSY, double value_GUT) ; 
		FieldCoupling(const FieldCoupling& f_cpl) ; 
		virtual ~FieldCoupling() {} ;

		std::vector<Field*>* GetFields() const {return fields_;} ; 
		void SetFields(std::vector<Field*>& fields) {fields_ = &fields;} ; 
} ; 

class SFCoupling: public Coupling {
	private:
		std::vector<Superfield*>* superfields_ ; 
	public:
		SFCoupling() {} ; 
		SFCoupling(std::vector<Superfield*>& superfields, RGE rge, double value_EW) ; 
		SFCoupling(std::vector<Superfield*>& superfields, RGE rge, double value_EW, double value_SUSY, double value_GUT) ; 
		SFCoupling(const SFCoupling& sf_cpl) ; 
		virtual ~SFCoupling() {} ;

		std::vector<Superfield*>* GetSuperFields() const {return superfields_;} ; 
		void SetSuperFields(std::vector<Superfield*>& superfields) {superfields_ = &superfields;} ; 
} ; 

#endif
