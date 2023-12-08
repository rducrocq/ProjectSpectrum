#include "../inc/Coupling.h"
#include <iostream>
#include <memory>

Coupling::Coupling(const Coupling& cpl): rge_(cpl.rge_) {
		value_EW_ = cpl.value_EW_ ; 
		value_GUT_ = cpl.value_GUT_ ; 
		value_SUSY_ = cpl.value_SUSY_ ; 
		current_value_ = value_EW_ ;
		name_ = cpl.name_ ; 
} ;

GaugeCoupling::GaugeCoupling(const Symmetry& sym, const RGE& rge, double value_EW, std::string name) : Coupling(rge,value_EW,name), sym_(sym) {} ; 

GaugeCoupling::GaugeCoupling(const Symmetry& sym, const RGE& rge, double value_EW, double value_SUSY, 
							  double value_GUT, std::string name) : Coupling(rge, value_EW, value_SUSY, value_GUT, name)
																	,	sym_(sym) {} ; 

FieldCoupling::FieldCoupling(std::vector<std::shared_ptr<Field>> fields, const RGE& rge, double value_EW, std::string name) : Coupling(rge,value_EW, name), fields_(fields) {} ;  

FieldCoupling::FieldCoupling(std::vector<std::shared_ptr<Field>> fields, const RGE& rge, double value_EW, double value_SUSY, double value_GUT, std::string name) : Coupling(rge, value_EW, value_SUSY, value_GUT, name), fields_(fields) {} ; 


SFCoupling::SFCoupling(std::vector<std::shared_ptr<Superfield>> superfields, const RGE& rge, double value_EW, std::string name) : Coupling(rge,value_EW,name), superfields_(superfields) {} ;  

SFCoupling::SFCoupling(std::vector<std::shared_ptr<Superfield>> superfields, const RGE& rge, double value_EW, double value_SUSY, double value_GUT, std::string name) : Coupling(rge, value_EW, value_SUSY, value_GUT, name), superfields_(superfields) {} ; 

SoftCoupling::SoftCoupling(std::vector<std::shared_ptr<Superfield>> superfields, const RGE& rge, double value_EW, std::string name) : Coupling(rge,value_EW,name), superfields_(superfields) {} ;  

SoftCoupling::SoftCoupling(std::vector<std::shared_ptr<Superfield>> superfields, const RGE& rge, double value_EW, double value_SUSY, double value_GUT, std::string name) : Coupling(rge, value_EW, value_SUSY, value_GUT, name), superfields_(superfields) {} ; 
