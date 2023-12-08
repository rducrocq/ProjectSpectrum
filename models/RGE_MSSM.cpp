#define _USE_MATH_DEFINES

#include <map>
#include <string>
#include "RGE_MSSM.h" 
#include <math.h>

double f1 = 1./(16*pow(M_PI,2)) ;

// Generic implementation for symmetry group G ? 
double RGE_g1(std::map<std::string, double>& par){
	double g1 = par["g1"] ; 
	return f1 * 33./5 * pow(g1, 3) ; 
	} ;

double RGE_g2(std::map<std::string, double>& par){
	double g1 = par["g2"] ; 
	return f1 * 1. * pow(g1, 3) ;  
	} ;

double RGE_g3(std::map<std::string, double>& par){
	double g1 = par["g3"] ; 
	return f1 * -3. * pow(g1, 3) ; 
	} ;

double RGE_mu(std::map<std::string, double>& par){
	double mu = par["mu"] ; 
	double yt = par["yt"] ; 
	double yb = par["yb"] ; 
	double ytau = par["ytau"] ; 
	double g2 = par["g2"] ; 
	double g1 = par["g1"] ; 
	return f1 * mu * ( 3*yt*yt + 3*yb*yb + ytau*ytau - 3*g2*g2 -3./5.*g1*g1 ) ; 
	} ;

double RGE_yt(std::map<std::string, double>& par){
	double yt = par["yt"] ; 
	double yb = par["yb"] ; 
	double g3 = par["g3"] ; 
	double g2 = par["g2"] ; 
	double g1 = par["g1"] ; 
	return f1 * yt * ( 6*yt*yt + yb*yb -16./3.*g3*g3 - 3*g2*g2 - 13./15.*g1*g1 ) ;
	} ;

double RGE_yb(std::map<std::string, double>& par){
	double yt = par["yt"] ; 
	double yb = par["yb"] ; 
	double ytau = par["ytau"] ; 
	double g3 = par["g3"] ; 
	double g2 = par["g2"] ; 
	double g1 = par["g1"] ; 
	return f1 * yb * ( 6*yb*yb + yt*yt + ytau*ytau -16./3.*g3*g3 - 3*g2*g2 - 7./15.*g1*g1 ) ;
	} ;

double RGE_ytau(std::map<std::string, double>& par){
	double yb = par["yb"] ; 
	double ytau = par["ytau"] ; 
	double g2 = par["g2"] ; 
	double g1 = par["g1"] ; 
	return f1 * ytau * ( 3*yb*yb + 4*ytau*ytau - 3*g2*g2 - 9./15.*g1*g1 ) ;
	} ;

double RGE_b(std::map<std::string, double>& par){
	double yt = par["yt"] ; 
	double b = par["b"] ; 
	double mu = par["mu"] ; 
	double yb = par["yb"] ; 
	double ytau = par["ytau"] ; 
	double at = par["at"] ; 
	double ab = par["ab"] ; 
	double atau = par["atau"] ; 
	double g2 = par["g2"] ; 
	double g1 = par["g1"] ; 
	double M1 = par["M1"] ; 
	double M2 = par["M2"] ; 
	return f1 * b * ( 3*yt*yt + 3*yb*yb + ytau*ytau - 3*g2*g2 - 3./5.*g1*g1 ) + f1 * mu * ( 6*at*yt + 6*ab*yb + 2*atau*ytau + 6*g2*g2*M2 + 6./5.*g1*g1*M1 ) ;
	} ;

double RGE_at(std::map<std::string, double>& par){
	double yt = par["yt"] ; 
	double yb = par["yb"] ; 
	double at = par["at"] ; 
	double ab = par["ab"] ; 
	double g3 = par["g3"] ; 
	double g2 = par["g2"] ; 
	double g1 = par["g1"] ; 
	double M1 = par["M1"] ; 
	double M2 = par["M2"] ; 
	double M3 = par["M3"] ; 
	return f1 * at * ( 18*yt*yt + yb*yb - 16./3.*g3*g3 - 3*g2*g2 - 13./15*g1*g1 ) + f1 * 2*ab*yb*yt + f1 * yt * (32./3*g3*g3*M3 + 6*g2*g2*M2 + 26./15*g1*g1*M1) ;
	} ; 

double RGE_ab(std::map<std::string, double>& par){
	double yt = par["yt"] ; 
	double yb = par["yb"] ; 
	double ytau = par["ytau"] ; 
	double at = par["at"] ; 
	double ab = par["ab"] ; 
	double atau = par["atau"] ; 
	double g3 = par["g3"] ; 
	double g2 = par["g2"] ; 
	double g1 = par["g1"] ; 
	double M1 = par["M1"] ; 
	double M2 = par["M2"] ; 
	double M3 = par["M3"] ; 
	return f1 * ab * ( 18*yb*yb + yt*yt + ytau*ytau - 16./3.*g3*g3 - 3*g2*g2 - 7./15*g1*g1 ) + f1 * 2*at*yb*yt + 2*atau*ytau*yb + f1 * yb * (32./3*g3*g3*M3 + 6*g2*g2*M2 + 14./15*g1*g1*M1) ;
	} ; 

double RGE_atau(std::map<std::string, double>& par){ 
	double yb = par["yb"] ; 
	double ytau = par["ytau"] ; 
	double ab = par["ab"] ; 
	double atau = par["atau"] ; 
	double g2 = par["g2"] ; 
	double g1 = par["g1"] ; 
	double M1 = par["M1"] ; 
	double M2 = par["M2"] ; 
	return f1 * atau * ( 3*yb*yb + 12*ytau*ytau - 3*g2*g2 - 9./5*g1*g1 ) + f1 * 6*ab*yb*ytau + f1 * ytau * (6*g2*g2*M2 + 18./5*g1*g1*M1) ;
	} ; 

double S(std::map<std::string, double>& par){ 
	double mHu2 = par["mHu2"] ; 
	double mHd2 = par["mHd2"] ; 
	double mQ2 = par["mQ2"] ; 
	double mL2 = par["mL2"] ; 
	double mU2 = par["mU2"] ; 
	double mD2 = par["mD2"] ; 
	double mE2 = par["mE2"] ; 
	return mHu2 - mHd2 + mQ2 - mL2 - 2*mU2 + mD2 + mE2 ; 
	} ; 

double Xt(std::map<std::string, double>& par){ 
	double yt = par["yt"] ; 
	double at = par["at"] ; 
	double mHu2 = par["mHu2"] ; 
	double mQ2 = par["mQ2"] ; 
	double mU2 = par["mU2"] ; 
	return 2*yt*yt * (mHu2 + mQ2 + mU2) + 2*at*at  ; 
	} ; 

double Xb(std::map<std::string, double>& par){ 
	double yb = par["yb"] ; 
	double ab = par["ab"] ; 
	double mHd2 = par["mHd2"] ; 
	double mQ2 = par["mQ2"] ; 
	double mD2 = par["mD2"] ; 
	return 2*yb*yb * (mHd2 + mQ2 + mD2) + 2*ab*ab  ; 
	} ; 

double Xtau(std::map<std::string, double>& par){ 
	double ytau = par["ytau"] ; 
	double atau = par["atau"] ; 
	double mHd2 = par["mHd2"] ; 
	double mL2 = par["mL2"] ; 
	double mE2 = par["mE2"] ; 
	return 2*ytau*ytau * (mHd2 + mL2 + mE2) + 2*atau*atau  ; 
	} ; 

double RGE_mHu2(std::map<std::string, double>& par){  
	double g2 = par["g2"] ; 
	double g1 = par["g1"] ; 
	double M1 = par["M1"] ; 
	double M2 = par["M2"] ; 
	return f1 * ( 3*Xt(par) - 6*g2*g2*M2*M2 - 6./5*g1*g1*M1*M1 + 3./5*g1*g1*S(par) ) ; 
	} ; 

double RGE_mHd2(std::map<std::string, double>& par){ 
	double g2 = par["g2"] ; 
	double g1 = par["g1"] ; 
	double M1 = par["M1"] ; 
	double M2 = par["M2"] ; 
	return f1 * ( 3*Xb(par) + Xtau(par) - 6*g2*g2*M2*M2 - 6./5*g1*g1*M1*M1 + 3./5*g1*g1*S(par) ) ; 
	} ; 

double RGE_mQ2(std::map<std::string, double>& par){ 
	double g3 = par["g3"] ; 
	double g2 = par["g2"] ; 
	double g1 = par["g1"] ; 
	double M1 = par["M1"] ; 
	double M2 = par["M2"] ; 
	double M3 = par["M3"] ; 
	return f1 * ( Xt(par) + Xb(par) - 32./3*g3*g3*M3*M3 - 6*g2*g2*M2*M2 - 2./15*g1*g1*M1*M1 + 1./5*g1*g1*S(par) ) ; 
	} ; 

double RGE_mU2(std::map<std::string, double>& par){ 
	double g3 = par["g3"] ; 
	double g1 = par["g1"] ; 
	double M1 = par["M1"] ; 
	double M3 = par["M3"] ; 
	return f1 * ( 2*Xt(par) - 32./3*g3*g3*M3*M3 - 32./15*g1*g1*M1*M1 - 4./5*g1*g1*S(par) ) ; 
	} ; 

double RGE_mD2(std::map<std::string, double>& par){ 
	double g3 = par["g3"] ; 
	double g1 = par["g1"] ; 
	double M1 = par["M1"] ; 
	double M3 = par["M3"] ; 
	return f1 * ( 2*Xb(par) - 32./3*g3*g3*M3*M3 - 8./15*g1*g1*M1*M1 + 2./5*g1*g1*S(par) ) ; 
	} ; 


double RGE_mL2(std::map<std::string, double>& par){ 
	double g2 = par["g2"] ; 
	double g1 = par["g1"] ; 
	double M1 = par["M1"] ; 
	double M2 = par["M2"] ; 
	return f1 * ( Xtau(par) - 6./5*g1*g1*M1*M1 - 6*g2*g2*M2*M2 - 3./5*g1*g1*S(par) ) ; 
	} ; 

double RGE_mE2(std::map<std::string, double>& par){ 
	double g1 = par["g1"] ; 
	double M1 = par["M1"] ; 
	return f1 * ( 2*Xtau(par) - 24./5*g1*g1*M1*M1 + 6./5*g1*g1*S(par) ) ; 
	} ; 

double RGE_M1(std::map<std::string, double>& par){
	double M1 = par["M1"] ; 
	double g1 = par["g1"] ; 
	return 2*f1 * 33./5.*g1*g1*M1 ;
}

double RGE_M2(std::map<std::string, double>& par){
	double M2 = par["M2"] ; 
	double g2 = par["g2"] ; 
	return 2*f1 * 1.*g2*g2*M2 ;
}

double RGE_M3(std::map<std::string, double>& par){
	double M3 = par["M3"] ; 
	double g3 = par["g3"] ; 
	return 2*f1 * (-3)*g3*g3*M3 ;
}