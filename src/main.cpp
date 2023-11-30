/*#include "../inc/Symmetry.h"
#include "../inc/Field.h"
#include "../inc/Superfield.h"
#include "../inc/Coupling.h"*/
#include "../inc/Model.h"
#include "../inc/ModelDataBase.h"
#include <iostream>
#include <vector>
#include <string>

int main(){

std::cout << "BEGINNING OF PROGRAM" << std::endl ;

ModelDataBase mdb ;

std::unique_ptr<SUSYModel> MSSM = mdb.LoadMSSM() ; 


// Test of SFCoupling
std::vector<SFCoupling*>* SFcpl = MSSM->GetSFCoupling() ; 

std::cout << "In Main ptr : " << (*SFcpl)[0] << std::endl ; 

auto all_sfcpl = MSSM->GetSFCoupling() ; 
std::cout << "In Main : " << (*(MSSM->GetSFCoupling()))[0]->GetValue_EW()  << std::endl ; 

for (auto sfcpl : (*SFcpl)) {
	std::cout << sfcpl->GetValue_EW() << " " << sfcpl->GetValue_SUSY() << " " << sfcpl->GetValue_GUT() << std::endl ; 
	}

// Test of Coupling
std::vector<Coupling*>* cpl = MSSM->GetCoupling() ; 

// Test of Field
std::vector<Field*>* F = MSSM->GetFields() ; 

// Test of Superfield
std::vector<Superfield*>* SF = MSSM->GetSuperFields() ; 

// Test of SolveRGE()
std::cout << MSSM->SolveRGE() << std::endl ; 

std::cout << "END OF PROGRAM" << std::endl ;

return 0 ; 
}	
