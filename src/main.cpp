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


std::cout << "test" << std::endl ;

ModelDataBase mdb ;

auto MSSM = mdb.LoadMSSM() ; 

/*
// Test of SFCoupling
auto SFcpl = MSSM->GetSFCoupling() ; 

std::cout << "In Main ptr : " << (*SFcpl)[0] << std::endl ; 

auto all_sfcpl = MSSM->GetSFCoupling() ; 
std::cout << "In Main : " << (*(MSSM->GetSFCoupling()))[0]->GetValue_EW()  << std::endl ; 

for (auto sfcpl : (*SFcpl)) {
	std::cout << sfcpl->GetValue_EW() << " " << sfcpl->GetValue_SUSY() << " " << sfcpl->GetValue_GUT() << std::endl ; 
	}

// Test of Coupling
auto cpl = MSSM->GetCoupling() ; 

// Test of Field
auto F = MSSM->GetFields() ; 

// Test of Superfield
auto SF = MSSM->GetSuperFields() ; 

// Test of SolveRGE()

*/
std::cout << MSSM->SolveRGE(0.01, 0.1) << std::endl ; 

std::cout << "END OF PROGRAM" << std::endl ;

return 0 ; 
}	
