#include "../inc/Symmetry.h"
#include "../inc/Field.h"
#include "../inc/Superfield.h"
#include "../inc/Coupling.h"
#include <iostream>
#include <vector>

double RGE_g1(std::vector<double> par){
	return 1 ; 
	}

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

if (su2 == su2) std::cout << "su2"  << std::endl;
if (su2 == su2c) std::cout << "su2c"  << std::endl;
if (su2 == su3) std::cout << "su3"  << std::endl;
if (su2 == u2) std::cout << "u2"  << std::endl;

if (SM == SM) std::cout << "sym"  << std::endl;
if (SM == symc) std::cout << "symc"  << std::endl;
if (SM == symc2) std::cout << "symc2" << std::endl ;
if (SM == symc3) std::cout << "symc3" << std::endl  ;

std::vector<double> charge {1/2., 0, 0} ; 
std::vector<double> charge2 {1/2., 0, 2} ; 
Scalar hu0("hu0",charge, SM) ; 
Spinor hu0_tilde("hu0_tilde",charge, SM) ;
Vector huvec("huvec", charge, SM) ;  
ChiralSF HU0("Higgs Up 0", &hu0, &hu0_tilde) ;  
ChiralSF HU02("HU0",charge, SM) ;  

VectorSF f0("Higgs Up 0", &huvec, &hu0_tilde) ;  

double g1_EW = 18.2 ; 
GaugeCoupling g1(u1,RGE_g1,g1_EW) ; 

std::vector<Field*> f = {&hu0, &hu0} ; 
FieldCoupling mphi2(f,RGE_g1, g1_EW) ; 

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
