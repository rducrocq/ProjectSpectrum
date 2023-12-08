#include "../inc/Superfield.h"
#include <iostream>
#include <memory>

ChiralSF::ChiralSF(std::string name, std::unique_ptr<Scalar> phi, std::unique_ptr<Spinor> psi) : Superfield(name), phi_(std::move(phi)),   psi_(std::move(psi)){
	/* Need to check if scalar and spinor have the same sym and charges */
	if (phi_->GetSymmetry() != psi_->GetSymmetry()) std::cerr << "In ChiralSF " << name_ << ":\n\t Scalar and Fermion parts are not based on the same symmetry group!" << std::endl ; 
	if (phi_->Getcharge() != psi_->Getcharge()) std::cerr << "In ChiralSF " << name_ << ":\n\tProblem of dimensionality between the charges of Scalar and Spinor!" << std::endl ; 
	} ;

ChiralSF::ChiralSF(std::string name, std::vector<double> charge, const Symmetries& sym) : Superfield(name)  {
	phi_ = std::make_unique<Scalar>(name+"_phi",charge,sym) ; 
	psi_ = std::make_unique<Spinor>(name+"_psi",charge,sym) ; 
	} ;

ChiralSF::~ChiralSF() {} ;


VectorSF::VectorSF(std::string name, std::unique_ptr<Vector> vmu, std::unique_ptr<Spinor> psi) : Superfield(name), vmu_(std::move(vmu)), psi_(std::move(psi)) {
	/* Need to check if scalar and spinor have the same sym and charges */
	if (vmu_->GetSymmetry() != psi_->GetSymmetry()) std::cerr << "In VectorSF " << name_ << ":\n\t Vector and Fermion parts are not based on the same symmetry group!" << std::endl ; 
	if (vmu_->Getcharge() != psi_->Getcharge()) std::cerr << "In VectorSF " << name_ << ":\n\tProblem of dimensionality between the charges of Vector and Spinor!" << std::endl ; 
	} ;

VectorSF::VectorSF(std::string name, std::vector<double> charge, const Symmetries& sym) : Superfield(name)  {
	vmu_ = std::make_unique<Vector>(name+"_vmu",charge,sym) ; 
	psi_ = std::make_unique<Spinor>(name+"_psi",charge,sym) ; 
	} ;

VectorSF::~VectorSF() {} ;

