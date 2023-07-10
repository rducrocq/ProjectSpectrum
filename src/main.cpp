#include "../inc/Symmetry.h"
#include "../inc/Field.h"
#include "../inc/Superfield.h"
#include "../inc/Coupling.h"
#include "../inc/Model.h"
#include "../models/MSSM.h"
#include <iostream>
#include <vector>
#include <string>

int main(){

std::cout << "BEGINNING OF PROGRAM" << std::endl ;

const SUSYModel MSSM = LoadMSSM() ; 

std::cout << "END OF PROGRAM" << std::endl ;

return 0 ; 
}	
