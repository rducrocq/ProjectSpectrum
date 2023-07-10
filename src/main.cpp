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

const SUSYModel MSSM = mdb.LoadMSSM() ; 

std::cout << "END OF PROGRAM" << std::endl ;

return 0 ; 
}	
