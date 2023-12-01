#include "../inc/Model.h"
#include <iostream>
#include <memory>

Model::Model(std::string name, Symmetries& sym, std::vector<std::shared_ptr<GaugeCoupling>>& g_cpl) : name_(name), sym_(&sym), g_cpl_(&g_cpl) {
	cpl_ = std::make_shared<std::vector<std::shared_ptr<Coupling>>>() ; 
	if ( sym.GetSizeSymmetries() != (*g_cpl_).size() ) {
		std::cout << "In Model: Problem of dimensionality between Symmetries & GaugeCoupling!" << std::endl ; 
		}
	cpl_->insert(cpl_->end(), g_cpl_->begin(), g_cpl_->end());
	} ; 

SUSYModel::SUSYModel(std::string name, Symmetries& sym	, std::vector<std::shared_ptr<GaugeCoupling>>& g_cpl
							, std::vector<std::shared_ptr<ChiralSF>>& Phis
							, std::vector<std::shared_ptr<VectorSF>>& Vs
							, std::vector<std::shared_ptr<SFCoupling>>& SFcpl) : Model(name, sym, g_cpl) {
	Phis_ = std::make_shared<std::vector<std::shared_ptr<ChiralSF>>>(Phis) ; 
	Vs_ = std::make_shared<std::vector<std::shared_ptr<VectorSF>>>(Vs) ; 
	SFcpl_ = std::make_shared<std::vector<std::shared_ptr<SFCoupling>>>() ; 
	for (auto sfcpl : SFcpl){ 
		SFcpl_->push_back(std::make_shared<SFCoupling>(sfcpl)) ; 
	}
	
//	SFcpl_ = &SFcpl ; 
	for (auto a : (*SFcpl_)){
		std::cout << "in constructor : " << a->GetValue_EW() << std::endl ; 
		}
	cpl_->insert(cpl_->end(), SFcpl_->begin(), SFcpl_->end());

	F_ = std::make_shared<std::vector<std::shared_ptr<Field>>>() ;
	for (auto chiral : *Phis_) {
		F_->push_back(chiral->GetScalar()) ; 
		F_->push_back(chiral->GetSpinor()) ; 
		}
	for (auto vector : *Vs_) {
		F_->push_back(vector->GetVector()) ; 
		F_->push_back(vector->GetSpinor()) ; 
		}

	SF_ = std::make_shared<std::vector<std::shared_ptr<Superfield>>>() ; 
	SF_->insert(SF_->end(), Phis_->begin(),  Phis_->end()) ;
	SF_->insert(SF_->end(), Vs_->begin(),  Vs_->end()) ;

	} ; 

std::shared_ptr<std::vector<std::shared_ptr<Field>>> SUSYModel::GetFields() const {return F_ ;};  		

std::shared_ptr<std::vector<std::shared_ptr<Superfield>>> SUSYModel::GetSuperFields() const {return SF_ ;}; 		

bool SUSYModel::SolveRGE() const {
	/* Implementation of SolveRGE... */
	return true ; 
	} ;  		

ClassicModel::ClassicModel(std::string name, Symmetries& sym	, std::vector<std::shared_ptr<GaugeCoupling>>& g_cpl
							, std::vector<std::shared_ptr<Scalar>>& phis
							, std::vector<std::shared_ptr<Spinor>>& psis
							, std::vector<std::shared_ptr<Vector>>& Amus
							, std::vector<std::shared_ptr<FieldCoupling>>& Fcpl) : Model(name, sym, g_cpl) {
								
	phis_ = std::make_shared<std::vector<std::shared_ptr<Scalar>>>(phis) ; 
	psis_ = std::make_shared<std::vector<std::shared_ptr<Spinor>>>(psis) ;
	Amus_ = std::make_shared<std::vector<std::shared_ptr<Vector>>>(Amus) ; 
	Fcpl_ = std::make_shared<std::vector<std::shared_ptr<FieldCoupling>>>(Fcpl) ; 
	cpl_->insert(cpl_->end(), Fcpl_->begin(), Fcpl_->end());

	F_ = std::make_shared<std::vector<std::shared_ptr<Field>>>() ;
	F_->insert(F_->end(), phis_->begin(), phis_->end());
	F_->insert(F_->end(), psis_->begin(), psis_->end());
	F_->insert(F_->end(), Amus_->begin(), Amus_->end());

	} ; 

std::shared_ptr<std::vector<std::shared_ptr<Field>>> ClassicModel::GetFields() const {return F_ ; };  		

bool ClassicModel::SolveRGE() const {
	/* Implementation of SolveRGE... */
	return true ; 
	} ;  		
