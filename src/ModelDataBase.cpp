#include "../inc/ModelDataBase.h"
#include "../inc/Model.h"
#include "../models/RGE_MSSM.h"
#include <memory>
#include <map>
#include <string>

std::unique_ptr<SUSYModel> ModelDataBase::LoadMSSM() {

	/////////////////////////////////
	// -- Symmetry of the model -- //
	/////////////////////////////////

	// Definition of the symmetries
	std::unique_ptr<Symmetry> su3 = std::make_unique<Symmetry_SU>(3) ; 
	std::unique_ptr<Symmetry> su2 = std::make_unique<Symmetry_SU>(2) ; 
	std::unique_ptr<Symmetry> u1 = std::make_unique<Symmetry_U>(1) ; 

	// SU(3)xSU(2)xU(1) symmetry
	std::vector<std::unique_ptr<Symmetry>> sym ; 
	sym.push_back(std::move(su3)) ;
	sym.push_back(std::move(su2)) ; 
	sym.push_back(std::move(u1)) ;
	Symmetries SM(std::move(sym)) ;  

	
	////////////////////////////////////
	// -- Superfields of the model -- //
	////////////////////////////////////

	// Vector Superfields
	std::shared_ptr<Superfield> V3 = std::make_shared<VectorSF>("gluon",std::vector<double>{8,1,1},SM) ; 
	std::shared_ptr<Superfield> V2 = std::make_shared<VectorSF>("W",std::vector<double>{1,2,1},SM) ; 
	std::shared_ptr<Superfield> V1 = std::make_shared<VectorSF>("B",std::vector<double>{1,1,1},SM) ; 

	std::vector<std::shared_ptr<Superfield>> vector_SF ; 
	vector_SF.push_back(V3) ; 
	vector_SF.push_back(V2) ; 
	vector_SF.push_back(V1) ; 

	// Define Chiral superfields
	std::shared_ptr<Superfield> HU = std::make_shared<ChiralSF>("Higgs Up", std::vector<double>{1,2,2},SM) ; 
	std::shared_ptr<Superfield> HD = std::make_shared<ChiralSF>("Higgs Down", std::vector<double>{1,2,2},SM) ;  
	std::shared_ptr<Superfield> D = std::make_shared<ChiralSF>("Right handed down quark", std::vector<double>{3,2,2},SM) ; 
	std::shared_ptr<Superfield> U = std::make_shared<ChiralSF>("Right handed up quark", std::vector<double>{3,2,2},SM) ;  
	std::shared_ptr<Superfield> Q = std::make_shared<ChiralSF>("Left handed quark", std::vector<double>{3,2,2},SM) ;
	std::shared_ptr<Superfield> L = std::make_shared<ChiralSF>("Left handed lepton", std::vector<double>{3,2,2},SM) ;
	std::shared_ptr<Superfield> E = std::make_shared<ChiralSF>("Right handed lepton", std::vector<double>{3,2,2},SM) ;  

	std::vector<std::shared_ptr<Superfield>> chiral_SF ; 
	chiral_SF.push_back(HU) ;  
	chiral_SF.push_back(HD) ;   
	chiral_SF.push_back(Q) ; 
	chiral_SF.push_back(U) ; 
	chiral_SF.push_back(D) ; 
	chiral_SF.push_back(E) ;
	chiral_SF.push_back(L) ;

	///////////////////////////////////
	// -- Couplings  of the model -- //
	///////////////////////////////////
	std::vector<std::unique_ptr<Coupling>> couplings ; 
	// Gauge couplings :
	std::unique_ptr<Coupling> g3 = std::make_unique<GaugeCoupling>(*su3, RGE_g3, 1., "g3") ; 
	std::unique_ptr<Coupling> g2 = std::make_unique<GaugeCoupling>(*su2, RGE_g2, 1, "g2") ; 
	std::unique_ptr<Coupling> g1 = std::make_unique<GaugeCoupling>(*u1, RGE_g1, 1, "g1") ; 

	couplings.push_back(std::move(g3)) ;  
	couplings.push_back(std::move(g2)) ; 
	couplings.push_back(std::move(g1)) ; 

	// Define SF couplings :
	// Mu Hu.Hd
	std::vector<std::shared_ptr<Superfield>> sf_Mu {HU,HD} ;
	std::unique_ptr<Coupling> Mu = std::make_unique<SFCoupling>(sf_Mu, RGE_mu, 1., "mu") ; 
	// Yt Q.Hu.U
	std::vector<std::shared_ptr<Superfield>> sf_Yt {Q,HU,U} ;
	std::unique_ptr<Coupling> Yt = std::make_unique<SFCoupling>(sf_Yt, RGE_yt, 1., "yt") ; 
	// Yb Q.Hu.D
	std::vector<std::shared_ptr<Superfield>> sf_Yb {Q,HU,D} ;
	std::unique_ptr<Coupling> Yb = std::make_unique<SFCoupling>(sf_Yb, RGE_yb, 1., "yb") ; 
	// Ytau L.Hd.E
	std::vector<std::shared_ptr<Superfield>> sf_Ytau {L,HD,E} ;
	std::unique_ptr<Coupling> Ytau = std::make_unique<SFCoupling>(sf_Ytau, RGE_ytau, 1., "ytau") ; 

	// Define Soft W couplings :
	// Mu Hu.Hd
	std::unique_ptr<Coupling> b = std::make_unique<SoftCoupling>(sf_Mu, RGE_b, 1., "b") ; 
	// Yt Q.Hu.U
	std::unique_ptr<Coupling> at = std::make_unique<SoftCoupling>(sf_Yt, RGE_at, 1., "at") ; 
	// Yb Q.Hu.D
	std::unique_ptr<Coupling> ab = std::make_unique<SoftCoupling>(sf_Yb, RGE_yb, 1., "ab") ; 
	// Ytau L.Hd.E
	std::unique_ptr<Coupling> atau = std::make_unique<SoftCoupling>(sf_Ytau, RGE_atau, 1., "atau") ; 

	// Define Soft mass couplings :
	// M1 \tilde{B}.\tidle{B}
	std::vector<std::shared_ptr<Superfield>> sf_M1 {V1,V1} ;
	std::unique_ptr<Coupling> M1 = std::make_unique<SoftCoupling>(sf_M1, RGE_M1, 1., "M1") ; 
	// M2 \tilde{W}.\tidle{W}
	std::vector<std::shared_ptr<Superfield>> sf_M2 {V2,V2} ;
	std::unique_ptr<Coupling> M2 = std::make_unique<SoftCoupling>(sf_M2, RGE_M2, 1., "M2") ; 
	// M3 \tilde{g}.\tidle{g}
	std::vector<std::shared_ptr<Superfield>> sf_M3 {V3,V3} ;
	std::unique_ptr<Coupling> M3 = std::make_unique<SoftCoupling>(sf_M3, RGE_M3, 1., "M3") ; 
	// mHu2 HU.HU
	std::vector<std::shared_ptr<Superfield>> sf_mHu2 {HU,HU} ;
	std::unique_ptr<Coupling> mHu2 = std::make_unique<SoftCoupling>(sf_mHu2, RGE_mHu2, 1., "mHu2") ; 
	// mHd2 HD.HD
	std::vector<std::shared_ptr<Superfield>> sf_mHd2 {HD,HD} ;
	std::unique_ptr<Coupling> mHd2 = std::make_unique<SoftCoupling>(sf_mHd2, RGE_mHd2, 1., "mHd2") ; 
	// mQ2 Q.Q
	std::vector<std::shared_ptr<Superfield>> sf_mQ2 {Q,Q} ;
	std::unique_ptr<Coupling> mQ2 = std::make_unique<SoftCoupling>(sf_mQ2, RGE_mQ2, 1., "mQ2") ; 
	// mU2 U.U
	std::vector<std::shared_ptr<Superfield>> sf_mU2 {U,U} ;
	std::unique_ptr<Coupling> mU2 = std::make_unique<SoftCoupling>(sf_mU2, RGE_mU2, 1., "mU2") ; 
	// mD2 D.D
	std::vector<std::shared_ptr<Superfield>> sf_mD2 {D,D} ;
	std::unique_ptr<Coupling> mD2 = std::make_unique<SoftCoupling>(sf_mD2, RGE_mD2, 1., "mD2") ; 
	// mL2 L.L
	std::vector<std::shared_ptr<Superfield>> sf_mL2 {L,L} ;
	std::unique_ptr<Coupling> mL2 = std::make_unique<SoftCoupling>(sf_mL2, RGE_mL2, 1., "mL2") ; 
	// mE2 E.E
	std::vector<std::shared_ptr<Superfield>> sf_mE2 {E,E} ;
	std::unique_ptr<Coupling> mE2 = std::make_unique<SoftCoupling>(sf_mE2, RGE_mE2, 1., "mE2") ; 

	std::vector<std::unique_ptr<Coupling>> sf_couplings ; 
	couplings.push_back(std::move(Mu)) ;
	couplings.push_back(std::move(Yt)) ;
	couplings.push_back(std::move(Yb)) ;
	couplings.push_back(std::move(Ytau)) ; 
	couplings.push_back(std::move(b)) ;
	couplings.push_back(std::move(at)) ;
	couplings.push_back(std::move(ab)) ;
	couplings.push_back(std::move(atau)) ; 
	couplings.push_back(std::move(b)) ;
	couplings.push_back(std::move(at)) ;
	couplings.push_back(std::move(ab)) ;
	couplings.push_back(std::move(atau)) ;
	couplings.push_back(std::move(M1)) ;
	couplings.push_back(std::move(M2)) ;
	couplings.push_back(std::move(M3)) ;
	couplings.push_back(std::move(mHu2)) ;
	couplings.push_back(std::move(mHd2)) ;
	couplings.push_back(std::move(mQ2)) ;
	couplings.push_back(std::move(mL2)) ;
	couplings.push_back(std::move(mU2)) ;
	couplings.push_back(std::move(mD2)) ;
	couplings.push_back(std::move(mE2)) ;

	std::unique_ptr<SUSYModel> MSSM = std::make_unique<SUSYModel>("MSSM",SM, chiral_SF, vector_SF, couplings);
//	auto all_sfcpl = MSSM->GetCoupling() ; 
//	std::cout << "In DataBase : " << all_sfcpl[0]->GetValue_EW()  << std::endl ; 
//	std::cout << "In DataBase ptr : " << all_sfcpl[0]  << std::endl ; 

	return MSSM ; 
	} ; 

