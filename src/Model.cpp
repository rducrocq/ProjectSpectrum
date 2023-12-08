#include "../inc/Model.h"
#include <iostream>
#include <memory>

Model::Model(std::string name, const Symmetries& sym, std::vector<std::unique_ptr<Coupling>>& cpl) : name_(name), sym_(sym), cpl_(std::move(cpl)) {
	if ( sym.GetSizeSymmetries() != cpl_.size() ) {
		std::cout << "In Model: Problem of dimensionality between Symmetries & GaugeCoupling!" << std::endl ; 
		}
	for (auto const& each_cpl : cpl_){
		par.insert({{each_cpl->Getname(),each_cpl->GetCurrentValue()}}) ; 
	}
	} ; 


SUSYModel::SUSYModel(std::string name, const Symmetries& sym, const std::vector<std::shared_ptr<Superfield>>& Phis
							, const std::vector<std::shared_ptr<Superfield>>& Vs
							, std::vector<std::unique_ptr<Coupling>>& cpl) : Model(name, sym, cpl)
																				, Phis_(Phis)
																				, Vs_(Vs) {} ; 
	

bool SUSYModel::SolveRGE(const double& h, const double& t_end) {
	/* Implementation of SolveRGE... */
	return true ; 
	} ;  		

ClassicModel::ClassicModel(std::string name, const Symmetries& sym, const std::vector<std::shared_ptr<Scalar>>& phis
							, const std::vector<std::shared_ptr<Spinor>>& psis
							, const std::vector<std::shared_ptr<Vector>>& Amus
							, std::vector<std::unique_ptr<Coupling>>& cpl) : Model(name, sym, cpl), phis_(phis), psis_(psis), Amus_(Amus) {} ; 		

bool ClassicModel::SolveRGE(const double& h, const double& t_end) {
	/* Implementation of SolveRGE... */
	return true ; 
	} ;
