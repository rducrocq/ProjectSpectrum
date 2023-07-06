#include "../inc/Symmetry.h"
#include "../inc/Field.h"
#include "../inc/Superfield.h"
#include <iostream>
#include <vector>

int main(){

Symmetry_SU su3(3) ; 
Symmetry_SU su2(2) ; 
Symmetry_U u1(1) ;
Symmetry_U u2(2) ;
Symmetries SM({&su3,&su2,&u1}) ;  
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

if (SM == SM) std::cout << "sym"  ;
if (SM == symc) std::cout << "symc"  ;
if (SM == symc2) std::cout << "symc2"  ;
if (SM == symc3) std::cout << "symc3" << std::endl  ;

std::vector<double> charge {1/2., 0, 0} ; 
std::vector<double> charge2 {1/2., 0, 2} ; 
Scalar hu0("hu0",charge, SM) ; 
Spinor hu0_tilde("hu0_tilde",charge, SM) ;
Vector huvec("huvec", charge, SM) ;  
ChiralSF HU0("Higgs Up 0", &hu0, &hu0_tilde) ;  
ChiralSF HU02("HU0",charge, SM) ;  


VectorSF f0("Higgs Up 0", &huvec, &hu0_tilde) ;  
Scalar hu02("hu0",charge, symc2) ;
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
