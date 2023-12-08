#ifndef Symmetry_h
#define Symmetry_h

#include <string>
#include <vector>
#include <memory>

// Generic class for Symmetry (will define SU(n) & U(n) symmetry)
class Symmetry {
	protected: 
		unsigned int n_ ;  

	public:
		// Constructor
		Symmetry(unsigned int n) : n_(n) {} ; 
		Symmetry(Symmetry& sym) : n_(sym.Getn()) {} ; 
		// Destructor
		virtual ~Symmetry(){} ; 

		// Accessor
		unsigned int Getn() const {return n_;} ; 
		virtual unsigned int Getdim() const = 0 ; 

		bool IsEqual(const Symmetry& sym) const ; 
} ; 

// Inheritance of Symmetry class: SU(n) symmetry
class Symmetry_SU : public Symmetry {
	public : 
		// Constructor
		Symmetry_SU(unsigned int n) ; 
		Symmetry_SU(Symmetry_SU& sym) ; 
		// Destructor
		~Symmetry_SU(){} ; 

		// Accessor
		virtual unsigned int Getdim() const override ;  
} ; 

// Inheritance of Symmetry class: U(n) symmetry
class Symmetry_U : public Symmetry {
	public : 
		// Constructor
		Symmetry_U(unsigned int n) ; 
		Symmetry_U(Symmetry_U& sym) ; 

		// Destructor
		~Symmetry_U(){} ; 

		// Accessor
		virtual unsigned int Getdim() const override ; 
} ; 

// Symmetry of a model: product of SU(n) & U(n): considered as a vector of sevral symmetries
class Symmetries {
	private:
		std::vector<std::unique_ptr<Symmetry>> symmetries_ ;
	public:
		Symmetries(std::vector<std::unique_ptr<Symmetry>> symmetries) : symmetries_(std::move(symmetries)) {};
		~Symmetries() {} ;
		const std::vector<std::unique_ptr<Symmetry>>& GetSymmetries() const {return symmetries_ ;} ;  
		unsigned int GetSizeSymmetries() const {return symmetries_.size() ;} ; 
		bool AreEqual(const Symmetries& sym) const ; 
} ; 


bool operator==(const Symmetry&, const Symmetry&) ; 
bool operator==(const Symmetry_SU&, const Symmetry_SU&) ; 
bool operator==(const Symmetry_U&, const Symmetry_U&) ; 
bool operator!=(const Symmetry&, const Symmetry&) ; 
bool operator!=(const Symmetry_SU&, const Symmetry_SU&) ; 
bool operator!=(const Symmetry_U&, const Symmetry_U&) ; 

bool operator==(const Symmetries&, const Symmetries&) ; 
bool operator!=(const Symmetries&, const Symmetries&) ; 


#endif
