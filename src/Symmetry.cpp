#include <string>
#include "../inc/Symmetry.h" 
#include <vector>
#include "typeinfo"
#include <iostream>
#include <algorithm>
#include <memory>

Symmetry_SU::Symmetry_SU(unsigned int n): Symmetry(n) {} ; 

unsigned int Symmetry_SU::Getdim() const {return n_*n_ - 1 ; } ; 

Symmetry_U::Symmetry_U(unsigned int n): Symmetry(n) {} ; 

unsigned int Symmetry_U::Getdim() const {return n_*n_ ; } ; 


bool Symmetry::IsEqual(const Symmetry& sym) const {
	return  ( (n_ == sym.Getn()) && (typeid(sym) == typeid(*this)) );
	} ; 


bool operator==(const Symmetry& a, const Symmetry& b) {	return a.IsEqual(b) ;} ;
bool operator==(const Symmetry_SU& a, const Symmetry_SU& b) {return a.IsEqual(b) ;} ;
bool operator==(const Symmetry_U& a, const Symmetry_U& b) {return a.IsEqual(b) ;} ;
bool operator!=(const Symmetry& a, const Symmetry& b) {	return !(a.IsEqual(b)) ;} ;
bool operator!=(const Symmetry_SU& a, const Symmetry_SU& b) {return !(a.IsEqual(b)) ;} ;
bool operator!=(const Symmetry_U& a, const Symmetry_U& b) {return !(a.IsEqual(b)) ;} ;

bool Symmetries::AreEqual(const Symmetries& s) const {
	const auto& sym = s.GetSymmetries() ; 
	if (symmetries_.size() != sym.size()) {
        return false;
    }
	// We can't simply use std::equal since it makes a copy of the object which can't be done with unique_ptr...
	// Bypass the issue with the lambda function...
    return std::equal(symmetries_.begin(), symmetries_.end(), sym.begin(),
                      [](const auto& a, const auto& b) {
                          return *a == *b;
                      }); 
	} ; 

bool operator==(const Symmetries& a, const Symmetries& b) {return a.AreEqual(b) ;} ;
bool operator!=(const Symmetries& a, const Symmetries& b) {return !(a.AreEqual(b)) ;}  ;
