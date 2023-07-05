#ifndef Symmetry_h
#define Symmetry_h

#include <string>

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
} ; 

class Symmetry_SU : public Symmetry {
	public : 
		// Constructor
		Symmetry_SU(): Symmetry() {} ; 
		Symmetry_SU(unsigned int n) ; 

		// Destructor
		~Symmetry_SU(){} ; 

		// Accessor
		virtual unsigned int Getdim() const ; 
} ; 

class Symmetry_U : public Symmetry {
	public : 
		// Constructor
		Symmetry_U(): Symmetry() {} ; 
		Symmetry_U(unsigned int n) ; 

		// Destructor
		~Symmetry_U(){} ; 

		// Accessor
		virtual unsigned int Getdim() const ; 
} ; 
/*
class u : public Symmetry {
	public : 
		// Constructor
		u(): Symmetry() {} ; 
		u(unsigned int n) ; 

		// Destructor
		~u(){} ; 

		// Accessor
		unsigned int Getdim() const ; 
}
*/
#endif
