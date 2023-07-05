#include <string>
#include "../inc/Symmetry.h" 
#include <vector>

Symmetry::Symmetry(unsigned int n): n_(n) {} ; 

unsigned int Symmetry::Getn() const {return n_;} ; 

void Symmetry::Setn(unsigned int n) {n_ = n ;} ; 

Symmetry_SU::Symmetry_SU(unsigned int n): Symmetry(n) {} ; 

unsigned int Symmetry_SU::Getdim() const {return n_*n_ - 1 ; } ; 

Symmetry_U::Symmetry_U(unsigned int n): Symmetry(n) {} ; 

unsigned int Symmetry_U::Getdim() const {return n_*n_ ; } ; 
