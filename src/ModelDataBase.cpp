#include "../inc/ModelDataBase.h"
#include "../inc/Model.h"
#include "../models/RGE_MSSM.h"

std::shared_ptr<SUSYModel> ModelDataBase::LoadMSSM() {
	// Define Symmetries of the MSSM 
	std::vector<Symmetry*> sym ; 
	Symmetry_SU su3(3) ; 
	sym.push_back(&su3) ;
	Symmetry_SU su2(2) ;
	sym.push_back(&su2) ; 
	Symmetry_U u1(1) ;
	sym.push_back(&u1) ;
	Symmetries SM(sym) ;  

	// Define gauge couplings 
	std::vector<GaugeCoupling*> gauge_coupling ;
	double g1_EW {1} ; 
	GaugeCoupling g1(u1,RGE_g1,g1_EW) ; 
	gauge_coupling.push_back(&g1) ; 
	double g2_EW {1} ; 
	GaugeCoupling g2(su2,RGE_g2,g2_EW) ; 
	gauge_coupling.push_back(&g2) ; 
	double g3_EW {1} ; 
	GaugeCoupling g3(su3,RGE_g3,g3_EW) ; 
	gauge_coupling.push_back(&g3) ; 

	// Define Vector superfields
	// problem with definition of the color charge... -> change to rep ? 
	std::vector<VectorSF*> vector_SF ; 
	VectorSF V3("gluon",{8,1,1},SM) ; 
	vector_SF.push_back(&V3) ; 
	VectorSF V2("W",{1,2,1},SM) ; 
	vector_SF.push_back(&V2) ; 
	VectorSF V1("B",{1,1,1},SM) ; 
	vector_SF.push_back(&V1) ; 

	// Define Chiral superfields
	std::vector<ChiralSF*> chiral_SF ; 
	ChiralSF HU("Higgs Up", {1,2,2},SM) ; 
	chiral_SF.push_back(&HU) ;  
	ChiralSF HD("Higgs Down", {1,2,2},SM) ;  
	chiral_SF.push_back(&HD) ; 
	ChiralSF Q("Left handed quark", {3,2,2},SM) ;  
	chiral_SF.push_back(&Q) ; 
	ChiralSF U("Right handed up quark", {3,2,2},SM) ;  
	chiral_SF.push_back(&U) ; 
	ChiralSF D("Right handed down quark", {3,2,2},SM) ;  
	chiral_SF.push_back(&D) ; 
	ChiralSF L("Left handed lepton", {3,2,2},SM) ;  
	chiral_SF.push_back(&L) ; 
	ChiralSF E("Right handed lepton", {3,2,2},SM) ;  
	chiral_SF.push_back(&E) ; 

	// Define SF couplings
	// Need to add specific conditions for potential minimisation
	std::vector<SFCoupling*> couplings ; 
	double Mu_EW {32.23} ; 
	std::vector<Superfield*> sf_Mu {&HU,&HD} ; 
	SFCoupling Mu(sf_Mu, RGE_mu, Mu_EW) ; 
	couplings.push_back(&Mu) ; 
	std::vector<SFCoupling*>* couplings_ptr = &couplings ; 

	std::cout << "In DataBase : " << couplings[0]->GetValue_EW() << " " << couplings[0] << std::endl ; 
	// Definition of the model
//	SUSYModel MSSM("MSSM",SM,gauge_coupling, chiral_SF, vector_SF, couplings) ; 
//	SUSYModel* MSSM = new SUSYModel("MSSM",SM,gauge_coupling, chiral_SF, vector_SF, couplings) ;
	std::shared_ptr<SUSYModel> MSSM = std::make_shared<SUSYModel>("MSSM",SM,gauge_coupling, chiral_SF, vector_SF, couplings);
	auto all_sfcpl = MSSM->GetSFCoupling() ; 
	std::cout << "In DataBase : " << (*all_sfcpl)[0]->GetValue_EW()  << std::endl ; 
	std::cout << "In DataBase ptr : " << (*all_sfcpl)[0]  << std::endl ; 
	return MSSM ; 
	} ; 
