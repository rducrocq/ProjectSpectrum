#define _USE_MATH_DEFINES

#include <map>
#include <string>
#include "RGE_MSSM.h" 
#include <math.h>

// Generic implementation for symmetry group G ? 
double RGE_g1(std::map<std::string, double> par){
	double tmp = 1./(16*pow(M_PI,2)) ;
	double b = 33./5 ; 
	double g1 = par["g1"] ; 
	return tmp * b * pow(g1, 3) ; 
	}

double RGE_g2(std::map<std::string, double> par){
	double tmp = 1./(16*pow(M_PI,2)) ;
	double b = 1. ; 
	double g1 = par["g2"] ; 
	return tmp * b * pow(g1, 3) ;  
	}

double RGE_g3(std::map<std::string, double> par){
	double tmp = 1./(16*pow(M_PI,2)) ;
	double b = -3. ; 
	double g1 = par["g3"] ; 
	return tmp * b * pow(g1, 3) ; 
	}

double RGE_mu(std::map<std::string, double> par){
	return 1 ; 
	}

