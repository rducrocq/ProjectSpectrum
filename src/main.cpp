/*#include "../inc/Symmetry.h"
#include "../inc/Field.h"
#include "../inc/Superfield.h"
#include "../inc/Coupling.h"*/
#include "../inc/Model.h"
#include "../inc/ModelDataBase.h"
#include <iostream>
#include <vector>
#include <string>

double myRGE(std::vector<double> par){
	return 10 ; 
}

int main(){

std::cout << "BEGINNING OF PROGRAM" << std::endl ;

ModelDataBase mdb ;

SUSYModel* MSSM = mdb.LoadMSSM() ; 


/*
// Test of SFCoupling
std::vector<SFCoupling*>* SFcpl = MSSM->GetSFCoupling() ; 

//std::cout << "In Main ptr : " << (*SFcpl)[0] << std::endl ; 

auto all_sfcpl = MSSM->GetSFCoupling() ; 
//std::cout << "In Main : " << (*(MSSM->GetSFCoupling()))[0]->GetValue_EW()  << std::endl ; 
std::vector<double> a = {} ; 
for (auto sfcpl : (*SFcpl)) {
	std::cout << sfcpl->GetValue_EW() << " " << sfcpl->GetValue_SUSY() << " " << sfcpl->GetValue_GUT() << std::endl ; 
	}
auto mycpl = (*SFcpl)[0] ; 
auto rge = mycpl->GetRGE() ; 
std::cout << rge(a)<< std::endl ; 

mycpl->SetValue_SUSY(30.) ; 
mycpl->SetValue_GUT(34.) ;
mycpl->SetValue_EW(50.) ;  
std::cout << mycpl->GetValue_EW() << " " << mycpl->GetValue_SUSY() << " " << mycpl->GetValue_GUT() << std::endl ; 

mycpl->SetRGE(myRGE) ;  

std::cout << mycpl->GetRGE()(a) << std::endl ; 

auto sfs = mycpl->GetSuperFields() ; 

for (auto sf : (*sfs)){
	std::cout << sf->Getname() << std::endl ; 
}

ChiralSF HU("Higgs Up", {1,2,2},*(MSSM->GetSymmetries())) ; 
ChiralSF Q("Left handed quark", {3,2,2},*(MSSM->GetSymmetries())) ;  
ChiralSF U("Right handed up quark", {3,2,2},*(MSSM->GetSymmetries())) ;  

double Yu_EW {3.23} ; 
std::vector<Superfield*> sf_Yu {&HU,&Q,&U} ; 
SFCoupling Yu(sf_Yu, myRGE, Yu_EW) ; 

mycpl->SetSuperFields(sf_Yu) ; 

sfs = mycpl->GetSuperFields() ; 

for (auto sf : (*sfs)){
	std::cout << sf->Getname() << std::endl ; 
}
*/

/*
// Test of Coupling
std::vector<Coupling*>* cpl = MSSM->GetCoupling() ; 

for (auto mycpl : *cpl){
	std::cout << mycpl->GetValue_EW() << " " << mycpl->GetValue_SUSY() << " " << mycpl->GetValue_GUT() << std::endl ; 
}
*/

// Test of Field
std::vector<Field*>* F = MSSM->GetFields() ; 

/*
// Test of Superfield
std::vector<Superfield*>* SF = MSSM->GetSuperFields() ; 

// Test of SolveRGE()
std::cout << MSSM->SolveRGE() << std::endl ; 
*/

delete MSSM ; MSSM = 0 ; 

std::cout << "END OF PROGRAM" << std::endl ;

return 0 ; 
}	
