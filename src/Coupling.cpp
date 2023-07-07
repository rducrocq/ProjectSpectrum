#include "../inc/Coupling.h"

GaugeCoupling::GaugeCoupling(Symmetry& sym, RGE rge, double value_EW) : Coupling(rge,value_EW) {
	sym_ = &sym ;
	} ; 

GaugeCoupling::GaugeCoupling(Symmetry& sym, RGE rge, double value_EW, double value_SUSY, double value_GUT) :   Coupling(rge, value_EW, value_SUSY, value_GUT) {
	sym_ = &sym ; 
	} ; 

FieldCoupling::FieldCoupling(std::vector<Field*>& fields, RGE rge, double value_EW): Coupling(rge,value_EW) {
	fields_ = &fields ;
	} ;  

FieldCoupling::FieldCoupling(std::vector<Field*>& fields, RGE rge, double value_EW, double value_SUSY, double value_GUT):
  Coupling(rge, value_EW, value_SUSY, value_GUT) {
	fields_ = &fields ;
	} ; 

SFCoupling::SFCoupling(std::vector<Superfield*>& superfields, RGE rge, double value_EW): Coupling(rge,value_EW) {
	superfields_ = &superfields ;
	} ;  

SFCoupling::SFCoupling(std::vector<Superfield*>& superfields, RGE rge, double value_EW, double value_SUSY, double value_GUT):
  Coupling(rge, value_EW, value_SUSY, value_GUT) {
	superfields_ = &superfields ;
	} ; 

