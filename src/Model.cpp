#include "../inc/Model.h"
#include <iostream>

Model::Model(std::string name, Symmetries& sym, std::vector<GaugeCoupling*>& g_cpl) : name_(name), sym_(&sym), g_cpl_(&g_cpl) {
	if ( sym.GetSizeSymmetries() != (*g_cpl_).size() ) {
		std::cout << "In Model: Problem of dimensionality between Symmetries & GaugeCoupling!" << std::endl ; 
		}
	(*cpl_).insert((*cpl_).end(), (*g_cpl_).begin(), (*g_cpl_).end());
	} ; 

SUSYModel::SUSYModel(std::string name, Symmetries& sym	, std::vector<GaugeCoupling*>& g_cpl
							, std::vector<ChiralSF*>& Phis
							, std::vector<VectorSF*>& Vs
							, std::vector<SFCoupling*>& SFcpl) : Model(name, sym, g_cpl) {
	Phis_ = &Phis ; 
	Vs_ = &Vs ; 
	SFcpl_ = &SFcpl ; 
	(*cpl_).insert((*cpl_).end(), (*SFcpl_).begin(), (*SFcpl_).end());
	} ; 

std::vector<Field*>* SUSYModel::GetFields() const {
	std::vector<Field*>* F = nullptr ;
	for (auto chiral : *Phis_) {
		(*F).push_back(chiral->GetScalar()) ; 
		(*F).push_back(chiral->GetSpinor()) ; 
		}
	for (auto vector : *Vs_) {
		(*F).push_back(vector->GetVector()) ; 
		(*F).push_back(vector->GetSpinor()) ; 
		}
	return F ; 
	};  		

std::vector<Superfield*>* SUSYModel::GetSuperFields() const {
	std::vector<Superfield*>* SF = nullptr ; 
	(*SF).insert((*SF).end(), (*Phis_).begin(),  (*Phis_).end()) ;
	(*SF).insert((*SF).end(), (*Vs_).begin(),  (*Vs_).end()) ;
	return SF ;  
	}; 		

bool SUSYModel::SolveRGE() {
	/* Implementation of SolveRGE... */
	return true ; 
	} ;  		
