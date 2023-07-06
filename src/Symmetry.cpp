#include <string>
#include "../inc/Symmetry.h" 
#include <vector>
#include "typeinfo"
#include <iostream>

Symmetry::Symmetry(unsigned int n): n_(n) {} ; 

unsigned int Symmetry::Getn() const {return n_;} ; 

void Symmetry::Setn(unsigned int n) {n_ = n ;} ; 

Symmetry_SU::Symmetry_SU(unsigned int n): Symmetry(n) {} ; 

unsigned int Symmetry_SU::Getdim() const {return n_*n_ - 1 ; } ; 

Symmetry_U::Symmetry_U(unsigned int n): Symmetry(n) {} ; 

unsigned int Symmetry_U::Getdim() const {return n_*n_ ; } ; 

bool Symmetry::IsEqual(const Symmetry& sym) const {
//	std::cout << this->Getn() << " " << sym.Getn() << " " << typeid(&sym).name() << " "<<  typeid(this).name() << std::endl ; 
	return  ( (n_ == sym.Getn()) && (typeid(sym) == typeid(*this)) );
	} ; 

bool operator==(const Symmetry& a, const Symmetry& b) {	return a.IsEqual(b) ;} ;
bool operator==(const Symmetry_SU& a, const Symmetry_SU& b) {return a.IsEqual(b) ;} ;
bool operator==(const Symmetry_U& a, const Symmetry_U& b) {return a.IsEqual(b) ;} ;
bool operator!=(const Symmetry& a, const Symmetry& b) {	return !(a.IsEqual(b)) ;} ;
bool operator!=(const Symmetry_SU& a, const Symmetry_SU& b) {return !(a.IsEqual(b)) ;} ;
bool operator!=(const Symmetry_U& a, const Symmetry_U& b) {return !(a.IsEqual(b)) ;} ;

bool Symmetries::AreEqual(const Symmetries& s) const {
	if (symmetries_.size() != s.GetSizeSymmetries() ) return false ; 
	std::vector<Symmetry*> sym = s.GetSymmetries() ; 
	for (int i = 0 ; i < symmetries_.size() ; i++) 
		if ( !(symmetries_[i]->IsEqual(*sym[i])) ) {
			return false ; 
		}
	return true ; 
	} ; 

bool operator==(const Symmetries& a, const Symmetries& b) {return a.AreEqual(b) ;} ;
bool operator!=(const Symmetries& a, const Symmetries& b) {return !(a.AreEqual(b)) ;}  ;
