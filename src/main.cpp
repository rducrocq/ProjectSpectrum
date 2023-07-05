#include "../inc/Symmetry.h"
#include "../inc/Field.h"
#include <iostream>
#include <vector>

typedef std::vector<Symmetry*> Symmetries ; 

int main(){

Symmetry_SU su3(3) ; 
Symmetry_SU su2(2) ; 
Symmetry_U u1(1) ;

Symmetries sym = {&su3,&su2,&u1} ;  

for (auto s : sym) std::cout << s->Getdim() <<std::endl ; 

double vev = 174. ; 
std::vector<int> repH {0,1,1} ; 
Scalar Higgs("Higgs", repH, vev) ; 

std::cout << Higgs.Getvev() << std::endl ; 
return 0 ; 
}
