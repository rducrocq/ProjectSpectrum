#include "../inc/Symmetry.h"
#include "../inc/Field.h"
#include <iostream>
#include <vector>

int main(){

Symmetry_SU su3(3) ; 
Symmetry_SU su2(2) ; 
Symmetry_U u1(1) ;
Symmetry_U u2(2) ;
Symmetries sym({&su3,&su2,&u1}) ;  

Symmetry_SU su3c(3) ; 
Symmetry_SU su2c(2) ; 
Symmetry_U u1c(1) ;
Symmetries symc({&su3c,&su2c,&u1c}) ;  

Symmetries symc2({&su3c,&su2c,&u1c,&u2}) ;  

Symmetries symc3({&su2c,&u1c,&u2}) ;  

if (su2 == su2) std::cout << "su2"  ;
if (su2 == su2c) std::cout << "su2c"  ;
if (su2 == su3) std::cout << "su3"  ;
if (su2 == u2) std::cout << "u2"  ;

if (sym == sym) std::cout << "sym"  ;
if (sym == symc) std::cout << "symc"  ;
if (sym == symc2) std::cout << "symc2"  ;
if (sym == symc3) std::cout << "symc3"  ;
/*
for (auto s : sym) std::cout << s->Getdim() <<std::endl ; 

double vev = 174. ; 
std::vector<double> repH {0,1,1} ; 
Scalar Higgs("Higgs", repH, sym, vev) ; 

std::cout << Higgs.Getvev() << std::endl ; 

Scalar CopyHiggs(Higgs) ;  



//for (int i = 0 ; i < sym.size(); i++){
//	if (*sym[i] != *symc[i]) std::cout << "no" << std::endl ; 
//	}
*/
return 0 ; 
}
