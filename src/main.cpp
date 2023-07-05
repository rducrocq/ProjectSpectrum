#include "../inc/Symmetry.h"
#include <iostream>
#include <vector>

typedef std::vector<Symmetry*> Symmetries ; 

int main(){

Symmetry_SU su3(3) ; 
Symmetry_SU su2(2) ; 
Symmetry_U u1(1) ;

Symmetries sym = {&su3,&su2,&u1} ;  

for (auto s : sym) std::cout << s->Getdim() <<std::endl ; 

return 0 ; 
}
