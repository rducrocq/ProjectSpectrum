#include "../inc/ModelDataBase.h"
#include "../inc/Model.h"
#include "../models/RGE_MSSM.h"
#include <memory>
#include <map>
#include <string>

std::unique_ptr<SUSYModel> ModelDataBase::LoadMSSM() {
	// Define Symmetries of the MSSM 
	std::vector<std::shared_ptr<Symmetry>> sym ; 
	std::shared_ptr<Symmetry> su3 = std::make_shared<Symmetry_SU>(3) ; 
	sym.push_back(su3) ;
	std::shared_ptr<Symmetry> su2 = std::make_shared<Symmetry_SU>(2) ; 
	sym.push_back(su2) ; 
	std::shared_ptr<Symmetry> u1 = std::make_shared<Symmetry_U>(1) ; 
	sym.push_back(u1) ;
	Symmetries SM(sym) ;  
    
    std::cout << "dim : " << u1->Getdim() << std::endl ; 

	// Define gauge couplings 
	std::vector<std::shared_ptr<GaugeCoupling>> gauge_coupling ;
	double g1_EW = 1 ; 
	GaugeCoupling g1(u1,RGE_g1,g1_EW, "g1") ; 
	gauge_coupling.push_back(std::make_shared<GaugeCoupling>(g1)) ; 
	double g2_EW = 1 ; 
	GaugeCoupling g2(su2,RGE_g2,g2_EW, "g2") ; 
	gauge_coupling.push_back(std::make_shared<GaugeCoupling>(g2)) ; 
	double g3_EW = 1 ; 
	GaugeCoupling g3(su3,RGE_g3,g3_EW, "g3") ; 
	gauge_coupling.push_back(std::make_shared<GaugeCoupling>(g3)) ; 


	// Define Vector superfields
	// problem with definition of the color charge... -> change to rep ? 
	std::vector<std::shared_ptr<VectorSF>> vector_SF ; 
	VectorSF V3("gluon",{8,1,1},SM) ; 
	vector_SF.push_back(std::make_shared<VectorSF>(V3)) ; 
	VectorSF V2("W",{1,2,1},SM) ; 
	vector_SF.push_back(std::make_shared<VectorSF>(V2)) ; 
	VectorSF V1("B",{1,1,1},SM) ; 
	vector_SF.push_back(std::make_shared<VectorSF>(V1)) ; 

	// Define Chiral superfields
	std::vector<std::shared_ptr<ChiralSF>> chiral_SF ; 
	ChiralSF HU("Higgs Up", {1,2,2},SM) ; 
	chiral_SF.push_back(std::make_shared<ChiralSF>(HU)) ;  
	ChiralSF HD("Higgs Down", {1,2,2},SM) ;  
	chiral_SF.push_back(std::make_shared<ChiralSF>(HD)) ; 
	ChiralSF Q("Left handed quark", {3,2,2},SM) ;  
	chiral_SF.push_back(std::make_shared<ChiralSF>(Q)) ; 
	ChiralSF U("Right handed up quark", {3,2,2},SM) ;  
	chiral_SF.push_back(std::make_shared<ChiralSF>(U)) ; 
	ChiralSF D("Right handed down quark", {3,2,2},SM) ;  
	chiral_SF.push_back(std::make_shared<ChiralSF>(D)) ; 
	ChiralSF L("Left handed lepton", {3,2,2},SM) ;  
	chiral_SF.push_back(std::make_shared<ChiralSF>(L)) ; 
	ChiralSF E("Right handed lepton", {3,2,2},SM) ;  
	chiral_SF.push_back(std::make_shared<ChiralSF>(E)) ; 


	// Define SF couplings
	// Need to add specific conditions for potential minimisation
	std::vector<std::shared_ptr<SFCoupling>> couplings ; 
	double Mu_EW =32.23 ; 
	std::vector<std::shared_ptr<Superfield>> sf_Mu {std::make_shared<ChiralSF>(HU),std::make_shared<ChiralSF>(HD)} ; 
	auto ptr_sf_Mu = std::make_shared<std::vector<std::shared_ptr<Superfield>>>(sf_Mu) ; 
	SFCoupling Mu(ptr_sf_Mu, RGE_mu, Mu_EW, "mu") ; 
	couplings.push_back(std::make_shared<SFCoupling>(Mu)) ; 
	auto couplings_ptr = std::make_shared<std::vector<std::shared_ptr<SFCoupling>>>(couplings) ; 

	std::cout << "In DataBase : " << couplings[0]->GetValue_EW() << " " << couplings[0] << std::endl ; 


	// Definition of the model
//	SUSYModel MSSM("MSSM",SM,gauge_coupling, chiral_SF, vector_SF, couplings) ; 
//	SUSYModel* MSSM = new SUSYModel("MSSM",SM,gauge_coupling, chiral_SF, vector_SF, couplings) ;
	std::unique_ptr<SUSYModel> MSSM = std::make_unique<SUSYModel>("MSSM",SM,gauge_coupling, chiral_SF, vector_SF, couplings);
	auto all_sfcpl = MSSM->GetSFCoupling() ; 
	std::cout << "In DataBase : " << all_sfcpl[0]->GetValue_EW()  << std::endl ; 
	std::cout << "In DataBase ptr : " << all_sfcpl[0]  << std::endl ; 

	return MSSM ; 
	} ; 
