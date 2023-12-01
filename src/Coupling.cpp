#include "../inc/Coupling.h"
#include <iostream>
#include <memory>

Coupling::Coupling(const Coupling& cpl){
		rge_ = cpl.rge_;
		value_EW_ = cpl.value_EW_ ; 
		value_GUT_ = cpl.value_GUT_ ; 
		value_SUSY_ = cpl.value_SUSY_ ; 
}

GaugeCoupling::GaugeCoupling(const GaugeCoupling& g_cpl) : Coupling(g_cpl) {
	sym_ = g_cpl.sym_ ;
}

GaugeCoupling::GaugeCoupling(std::shared_ptr<Symmetry>& sym, RGE rge, double value_EW) : Coupling(rge,value_EW) {
	sym_ = sym ;
	} ; 

GaugeCoupling::GaugeCoupling(std::shared_ptr<Symmetry>& sym, RGE rge, double value_EW, double value_SUSY, double value_GUT) : Coupling(rge, value_EW, value_SUSY, value_GUT) {
	sym_ = sym ; 
	} ; 

FieldCoupling::FieldCoupling(const FieldCoupling& f_cpl) : Coupling(f_cpl) {
	fields_ = f_cpl.fields_ ; 
}

FieldCoupling::FieldCoupling(std::shared_ptr<std::vector<std::shared_ptr<Field>>>& fields, RGE rge, double value_EW) : Coupling(rge,value_EW) {
	fields_ = fields ;
	} ;  

FieldCoupling::FieldCoupling(std::shared_ptr<std::vector<std::shared_ptr<Field>>>& fields, RGE rge, double value_EW, double value_SUSY, double value_GUT) : Coupling(rge, value_EW, value_SUSY, value_GUT) {
	fields_ = fields ;
	} ; 

SFCoupling::SFCoupling(const SFCoupling& sf_cpl) : Coupling(sf_cpl) {
	superfields_ = sf_cpl.superfields_ ; 
}

SFCoupling::SFCoupling(std::shared_ptr<std::vector<std::shared_ptr<Superfield>>>& superfields, RGE rge, double value_EW) : Coupling(rge,value_EW) {
	superfields_ = superfields ;
	std::cout << "In Coupling CPP EW : " << value_EW_ <<  " " << value_EW << std::endl ;
	} ;  

SFCoupling::SFCoupling(std::shared_ptr<std::vector<std::shared_ptr<Superfield>>>& superfields, RGE rge, double value_EW, double value_SUSY, double value_GUT) : Coupling(rge, value_EW, value_SUSY, value_GUT) {
	superfields_ = superfields ;
	} ; 

SFCoupling::SFCoupling(std::shared_ptr<SFCoupling>& sf_cpl) {
    superfields_ = sf_cpl->GetSuperFields() ; 
   	rge_ = sf_cpl->GetRGE() ;
	value_EW_ = sf_cpl->GetValue_EW() ; 
	value_GUT_ = sf_cpl->GetValue_GUT() ; 
	value_SUSY_ = sf_cpl->GetValue_SUSY() ; 
}
