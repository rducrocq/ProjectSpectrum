#ifndef Model_h
#define Model_h

#include "../inc/Symmetry.h"
#include "../inc/Coupling.h"
#include "../inc/Field.h"
#include "../inc/Superfield.h"
#include <string>
#include <memory>

class Model {
	protected:
		std::string name_ ; 
		const Symmetries& sym_ ; 
		std::vector<std::unique_ptr<Coupling>> cpl_ ; 
		std::map<std::string, double> par ;
	public: 
		Model(std::string name, const Symmetries& sym, std::vector<std::unique_ptr<Coupling>>& cpl) ; 
		virtual ~Model() {} ;
 
		const std::vector<std::unique_ptr<Coupling>>& GetCoupling() const {return cpl_;} ; 

		
		virtual bool SolveRGE(const double& h, const double& t_end) = 0 ; 		
} ; 

class SUSYModel: public Model {
	private:
		const std::vector<std::shared_ptr<Superfield>>& Phis_ ; 
		const std::vector<std::shared_ptr<Superfield>>& Vs_ ; 
 
	public:
		SUSYModel(std::string name_, const Symmetries& sym	
								, const std::vector<std::shared_ptr<Superfield>>& Phis
								, const std::vector<std::shared_ptr<Superfield>>& Vs 
								, std::vector<std::unique_ptr<Coupling>>& cpl) ; 

		~SUSYModel() {} ; 
	
		const std::vector<std::shared_ptr<Superfield>>& GetChiral() const {return Phis_;}; 		
		const std::vector<std::shared_ptr<Superfield>>& GetVector() const {return Vs_;}; 
		virtual bool SolveRGE(const double& h, const double& t_end) ; 		
} ; 

class ClassicModel: public Model {
	private:
		const std::vector<std::shared_ptr<Scalar>>& phis_ ; 
		const std::vector<std::shared_ptr<Spinor>>& psis_ ;
 		const std::vector<std::shared_ptr<Vector>>& Amus_ ;
	public:
		ClassicModel(std::string name_, const Symmetries& sym	
								, const std::vector<std::shared_ptr<Scalar>>& phis
								, const std::vector<std::shared_ptr<Spinor>>& psis
								, const std::vector<std::shared_ptr<Vector>>& Amus
								, std::vector<std::unique_ptr<Coupling>>& cpl) ; 

		~ClassicModel() {} ; 
	
		const std::vector<std::shared_ptr<Scalar>>& GetScalar() const {return phis_;}; 		
		const std::vector<std::shared_ptr<Spinor>>& GetSpinor() const {return psis_;}; 		
		const std::vector<std::shared_ptr<Vector>>& GetVector() const {return Amus_;}; 		
		virtual bool SolveRGE(const double& h, const double& t_end) ; 		
} ; 

#endif
