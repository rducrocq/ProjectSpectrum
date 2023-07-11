#include "../inc/Model.h"
#include <iostream>

Model::Model(std::string name, Symmetries& sym, std::vector<GaugeCoupling*>& g_cpl) : name_(name), sym_(&sym), g_cpl_(&g_cpl) {
	cpl_ = new std::vector<Coupling*> {} ; 
	if ( sym.GetSizeSymmetries() != (*g_cpl_).size() ) {
		std::cout << "In Model: Problem of dimensionality between Symmetries & GaugeCoupling!" << std::endl ; 
		}
	cpl_->insert(cpl_->end(), g_cpl_->begin(), g_cpl_->end());
	} ; 

SUSYModel::SUSYModel(std::string name, Symmetries& sym	, std::vector<GaugeCoupling*>& g_cpl
							, std::vector<ChiralSF*>& Phis
							, std::vector<VectorSF*>& Vs
							, std::vector<SFCoupling*>& SFcpl) : Model(name, sym, g_cpl) {
	Phis_ = &Phis ; 
	Vs_ = &Vs ; 
	SFcpl_ = new std::vector<SFCoupling*> {} ; 
	for (auto sfcpl : SFcpl){ 
		SFcpl_->push_back(new SFCoupling(*sfcpl)) ; 
	}
	
//	SFcpl_ = &SFcpl ; 
//	for (auto a : (*SFcpl_)){
//		std::cout << "in constructor : " << a->GetValue_EW() << std::endl ; 
//		}
	cpl_->insert(cpl_->end(), SFcpl_->begin(), SFcpl_->end());

	F_ = new std::vector<Field*> {} ;
	for (auto chiral : *Phis_) {
		F_->push_back(chiral->GetScalar()) ; 
		F_->push_back(chiral->GetSpinor()) ; 
		}
	for (auto vector : *Vs_) {
		F_->push_back(vector->GetVector()) ; 
		F_->push_back(vector->GetSpinor()) ; 
		}

	SF_ = new std::vector<Superfield*> {} ; 
	SF_->insert(SF_->end(), Phis_->begin(),  Phis_->end()) ;
	SF_->insert(SF_->end(), Vs_->begin(),  Vs_->end()) ;

	} ; 

std::vector<Field*>* SUSYModel::GetFields() const {return F_ ;};  		

std::vector<Superfield*>* SUSYModel::GetSuperFields() const {return SF_ ;}; 		

bool SUSYModel::SolveRGE() const {
	/* Implementation of SolveRGE... */
	return true ; 
	} ;  		

ClassicModel::ClassicModel(std::string name, Symmetries& sym	, std::vector<GaugeCoupling*>& g_cpl
							, std::vector<Scalar*>& phis
							, std::vector<Spinor*>& psis
							, std::vector<Vector*>& Amus
							, std::vector<FieldCoupling*>& Fcpl) : Model(name, sym, g_cpl) {
	phis_ = &phis ; 
	psis_ = &psis ;
	Amus_ = &Amus ; 
	Fcpl_ = &Fcpl ; 
	cpl_->insert(cpl_->end(), Fcpl_->begin(), Fcpl_->end());

	F_ = new std::vector<Field*> {} ;
	F_->insert(F_->end(), phis_->begin(), phis_->end());
	F_->insert(F_->end(), psis_->begin(), psis_->end());
	F_->insert(F_->end(), Amus_->begin(), Amus_->end());

	} ; 

std::vector<Field*>* ClassicModel::GetFields() const {return F_ ; };  		

bool ClassicModel::SolveRGE() const {
	/* Implementation of SolveRGE... */
	return true ; 
	} ;  		
