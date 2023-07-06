#ifndef Symmetry_h
#define Symmetry_h

#include <string>
#include <vector>

class Symmetry {
	protected: 
		unsigned int n_ ;  

	public:
		// Constructor
		Symmetry(){} ; 
		Symmetry(unsigned int n) ; 

		// Destructor
		virtual ~Symmetry(){} ; 

		// Accessor
		unsigned int Getn() const ; 
		virtual unsigned int Getdim() const = 0 ; 

		// Mutator
		void Setn(unsigned int n) ; 

		bool IsEqual(const Symmetry& sym) const ; 
} ; 

class Symmetry_SU : public Symmetry {
	public : 
		// Constructor
		Symmetry_SU(): Symmetry() {} ; 
		Symmetry_SU(unsigned int n) ; 

		// Destructor
		~Symmetry_SU(){} ; 

		// Accessor
		virtual unsigned int Getdim() const override ;  
} ; 

class Symmetry_U : public Symmetry {
	public : 
		// Constructor
		Symmetry_U(): Symmetry() {} ; 
		Symmetry_U(unsigned int n) ; 

		// Destructor
		~Symmetry_U(){} ; 

		// Accessor
		virtual unsigned int Getdim() const override ; 
} ; 


class Symmetries {
	private:
		std::vector<Symmetry*> symmetries_ ;
	public:
		Symmetries() {}; 
		Symmetries(std::vector<Symmetry*> symmetries) : symmetries_(symmetries) {};
		~Symmetries() {} ;
		void SetSymmetries(std::vector<Symmetry*> symmetries) {symmetries_ = symmetries ;} ; 
		std::vector<Symmetry*> GetSymmetries() const {return symmetries_ ;} ;  
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
