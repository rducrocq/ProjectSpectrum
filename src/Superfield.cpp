#include "../inc/Superfield.h"
#include <iostream>
#include <memory>

ChiralSF::ChiralSF() : Superfield() {
	phi_ = std::make_shared<Scalar>() ; 
	psi_ = std::make_shared<Spinor>() ; 
	} ;

ChiralSF::ChiralSF(std::string name, std::shared_ptr<Scalar> phi, std::shared_ptr<Spinor> psi) : Superfield(name) {
//	phi_ = new Scalar(*phi) ; 
//	psi_ = new Spinor(*psi) ; 
	phi_ = phi ; 
	psi_ = psi ;

	/* Need to check if scalar and spinor have the same sym and charges */
	if (phi_->GetSymmetry() != psi_->GetSymmetry()) std::cerr << "In ChiralSF " << name_ << ":\n\t Scalar and Fermion parts are not based on the same symmetry group!" << std::endl ; 
	if (phi_->Getcharge() != psi_->Getcharge()) std::cerr << "In ChiralSF " << name_ << ":\n\tProblem of dimensionality between the charges of Scalar and Spinor!" << std::endl ; 

	} ;

ChiralSF::ChiralSF(std::string name, std::vector<double> charge, Symmetries sym) : Superfield(name)  {
	phi_ = std::make_shared<Scalar>(name+"_phi",charge,sym) ; 
	psi_ = std::make_shared<Spinor>(name+"_psi",charge,sym) ; 
	}

ChiralSF::~ChiralSF() {
//	delete phi_ ; phi_ = 0 ; 
//	delete psi_ ; psi_ = 0 ; 
	}


VectorSF::VectorSF() : Superfield() {
	vmu_ = std::make_shared<Vector>() ; 
	psi_ = std::make_shared<Spinor>() ; 
	} ;

VectorSF::VectorSF(std::string name, std::shared_ptr<Vector> vmu, std::shared_ptr<Spinor> psi) : Superfield(name) {
//	vmu_ = new Vector(*vmu) ; 
//	psi_ = new Spinor(*psi) ; 
	vmu_ = std::make_shared<Vector>(vmu) ; 
	psi_ = std::make_shared<Spinor>(psi) ; 

	/* Need to check if scalar and spinor have the same sym and charges */
	if (vmu_->GetSymmetry() != psi_->GetSymmetry()) std::cerr << "In VectorSF " << name_ << ":\n\t Vector and Fermion parts are not based on the same symmetry group!" << std::endl ; 
	if (vmu_->Getcharge() != psi_->Getcharge()) std::cerr << "In VectorSF " << name_ << ":\n\tProblem of dimensionality between the charges of Vector and Spinor!" << std::endl ; 
	} ;

VectorSF::VectorSF(std::string name, std::vector<double> charge, Symmetries sym) : Superfield(name)  {
//	vmu_ = new Vector(name+"_vmu",charge,sym) ; 
//	psi_ = new Spinor(name+"_psi",charge,sym) ; 
	vmu_ = std::make_shared<Vector>(name+"_vmu",charge,sym) ; 
	psi_ = std::make_shared<Spinor>(name+"_psi",charge,sym) ; 

	}

VectorSF::~VectorSF() {
//	delete vmu_ ; vmu_ = 0 ; 
//	delete psi_ ; psi_ = 0 ; 
	}

