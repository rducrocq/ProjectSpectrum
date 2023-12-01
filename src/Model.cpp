#include "../inc/Model.h"
#include <iostream>
#include <memory>

Model::Model(std::string name, Symmetries& sym, std::vector<std::shared_ptr<GaugeCoupling>>& g_cpl) : name_(name), sym_(sym), g_cpl_(g_cpl) {
	cpl_ = std::vector<std::shared_ptr<Coupling>>{} ; 
	if ( sym.GetSizeSymmetries() != g_cpl_.size() ) {
		std::cout << "In Model: Problem of dimensionality between Symmetries & GaugeCoupling!" << std::endl ; 
		}
	cpl_.insert(cpl_.end(), g_cpl_.begin(), g_cpl_.end());
	for (auto each_cpl : cpl_){
		par.insert({{each_cpl->Getname(),each_cpl->GetCurrentValue()}}) ; 
	}
	} ; 

SUSYModel::SUSYModel(std::string name, Symmetries& sym	, std::vector<std::shared_ptr<GaugeCoupling>>& g_cpl
							, std::vector<std::shared_ptr<ChiralSF>>& Phis
							, std::vector<std::shared_ptr<VectorSF>>& Vs
							, std::vector<std::shared_ptr<SFCoupling>>& SFcpl) : Model(name, sym, g_cpl) {
	Phis_ = std::vector<std::shared_ptr<ChiralSF>>(Phis) ; 
	Vs_ = std::vector<std::shared_ptr<VectorSF>>(Vs) ; 
	SFcpl_ = std::vector<std::shared_ptr<SFCoupling>>() ; 
	for (auto sfcpl : SFcpl){ 
		SFcpl_.push_back(std::make_shared<SFCoupling>(sfcpl)) ; 
	}
	
//	SFcpl_ = &SFcpl ; 
	for (auto a : SFcpl_){
		std::cout << "in constructor : " << a->GetValue_EW() << std::endl ; 
		}
	cpl_.insert(cpl_.end(), SFcpl_.begin(), SFcpl_.end());

	F_ = std::vector<std::shared_ptr<Field>>{} ;
	for (auto chiral : Phis_) {
		F_.push_back(chiral->GetScalar()) ; 
		F_.push_back(chiral->GetSpinor()) ; 
		}
	for (auto vector : Vs_) {
		F_.push_back(vector->GetVector()) ; 
		F_.push_back(vector->GetSpinor()) ; 
		}

	SF_ = std::vector<std::shared_ptr<Superfield>>() ; 
	SF_.insert(SF_.end(), Phis_.begin(),  Phis_.end()) ;
	SF_.insert(SF_.end(), Vs_.begin(),  Vs_.end()) ;

	} ; 

std::vector<std::shared_ptr<Field>> SUSYModel::GetFields() const {return F_ ;};  		

std::vector<std::shared_ptr<Superfield>> SUSYModel::GetSuperFields() const {return SF_ ;}; 		

bool SUSYModel::SolveRGE(double h, double t_end) {
	/* Implementation of SolveRGE... */
	std::cout << __FUNCTION__ << std::endl ;
	double k1 = 1 ; 
	double k2 = 1 ; 
	double k3 = 1 ; 
	double k4 = 1 ;
	for (double t=0; t <= t_end; t += h){
		std::cout << t << " " << g_cpl_.size() << std::endl ;
		std::cout << t << " " << g_cpl_[0]->Getname() << std::endl ;
		std::cout << t << " " << g_cpl_[1]->Getname()  << std::endl ;
		std::cout << t << " " << g_cpl_[2]->Getname()  << std::endl ;
		auto tmp_par = par ; 
		for (auto cpl : g_cpl_){
			auto rge = cpl->GetRGE() ; 
			k1 = rge(tmp_par) ; 
			tmp_par[cpl->Getname()] = par[cpl->Getname()] + h/2 * k1 ; 
			k2 = rge(tmp_par) ; 
			tmp_par[cpl->Getname()] = par[cpl->Getname()] + h/2 * k2 ; 
			k3 = rge(tmp_par) ;
			tmp_par[cpl->Getname()] = par[cpl->Getname()] + h * k3 ; 
			k4 = rge(tmp_par) ;
			tmp_par[cpl->Getname()] = par[cpl->Getname()] + h/6 * (k1 + 2*k2 + 2*k3 + k4) ; 
			}
		par = tmp_par ;
		}
	for (const auto& [key, value] : par) std::cout << key << " " << value << std::endl ; 

	return true ; 
	} ;  		

ClassicModel::ClassicModel(std::string name, Symmetries& sym	, std::vector<std::shared_ptr<GaugeCoupling>>& g_cpl
							, std::vector<std::shared_ptr<Scalar>>& phis
							, std::vector<std::shared_ptr<Spinor>>& psis
							, std::vector<std::shared_ptr<Vector>>& Amus
							, std::vector<std::shared_ptr<FieldCoupling>>& Fcpl) : Model(name, sym, g_cpl) {
								
	phis_ = std::vector<std::shared_ptr<Scalar>>(phis) ; 
	psis_ = std::vector<std::shared_ptr<Spinor>>(psis) ;
	Amus_ = std::vector<std::shared_ptr<Vector>>(Amus) ; 
	Fcpl_ = std::vector<std::shared_ptr<FieldCoupling>>(Fcpl) ; 
	cpl_.insert(cpl_.end(), Fcpl_.begin(), Fcpl_.end());

	F_ = std::vector<std::shared_ptr<Field>>{} ;
	F_.insert(F_.end(), phis_.begin(), phis_.end());
	F_.insert(F_.end(), psis_.begin(), psis_.end());
	F_.insert(F_.end(), Amus_.begin(), Amus_.end());

	} ; 

std::vector<std::shared_ptr<Field>> ClassicModel::GetFields() const {return F_ ; };  		

bool ClassicModel::SolveRGE(double h, double t_end) {
	/* Implementation of SolveRGE... */
	return true ; 
	} ;
