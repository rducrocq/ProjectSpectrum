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
		std::shared_ptr<Symmetries> sym_ ; 
		std::shared_ptr<std::vector<std::shared_ptr<GaugeCoupling>>> g_cpl_ ; 
		std::shared_ptr<std::vector<std::shared_ptr<Coupling>>> cpl_ ; 
	public: 
		Model() {} ; 
		Model(std::string name, Symmetries& sym, std::vector<std::shared_ptr<GaugeCoupling>>& g_cpl) ; 
		virtual ~Model() {
//			delete cpl_ ; cpl_ = 0 ;
			} ;
 
		std::vector<std::shared_ptr<GaugeCoupling>>& GetGaugeCoupling() const {return *g_cpl_;} ; 

//		virtual void SetCoupling(std::vector<Coupling*>& cpl) = 0 ; 
		virtual std::shared_ptr<std::vector<std::shared_ptr<Coupling>>> GetCoupling() const = 0 ; 
		virtual std::shared_ptr<std::vector<std::shared_ptr<Field>>> GetFields() const = 0 ; 		
		virtual bool SolveRGE() const = 0 ; 		
} ; 

class SUSYModel: public Model {
	private:
		std::shared_ptr<std::vector<std::shared_ptr<ChiralSF>>> Phis_ ; 
		std::shared_ptr<std::vector<std::shared_ptr<VectorSF>>> Vs_ ; 
		std::shared_ptr<std::vector<std::shared_ptr<SFCoupling>>> SFcpl_ ; 
		std::shared_ptr<std::vector<std::shared_ptr<Superfield>>> SF_ ; 
		std::shared_ptr<std::vector<std::shared_ptr<Field>>> F_ ; 
 
	public:
		SUSYModel() : Model() {} ; 
		SUSYModel(std::string name_, Symmetries& sym	, std::vector<std::shared_ptr<GaugeCoupling>>& g_cpl
								, std::vector<std::shared_ptr<ChiralSF>>& Phis
								, std::vector<std::shared_ptr<VectorSF>>& Vs
								, std::vector<std::shared_ptr<SFCoupling>>& SFcpl) ; 
		~SUSYModel() {
/*			for (auto sfcpl : *SFcpl_){
				delete sfcpl ; sfcpl = 0 ; 
			}
			delete SFcpl_ ; SFcpl_ = 0 ; 
			delete SF_ ; SF_ = 0 ; 
			delete F_; F_ = 0 ; 
			*/
			} ; 

		void SetSFCoupling(std::shared_ptr<std::vector<std::shared_ptr<SFCoupling>>>& SFcpl) {SFcpl_ = SFcpl; } ; 
		std::shared_ptr<std::vector<std::shared_ptr<SFCoupling>>> GetSFCoupling() const {return SFcpl_;} ; 
		virtual std::shared_ptr<std::vector<std::shared_ptr<Coupling>>> GetCoupling() const {return cpl_;} ; 
		virtual std::shared_ptr<std::vector<std::shared_ptr<Field>>> GetFields() const ; 		
		virtual std::shared_ptr<std::vector<std::shared_ptr<Superfield>>> GetSuperFields() const ; 		
		virtual bool SolveRGE() const ; 		
} ; 

class ClassicModel: public Model {
	private:
		std::shared_ptr<std::vector<std::shared_ptr<Scalar>>> phis_ ; 
		std::shared_ptr<std::vector<std::shared_ptr<Spinor>>> psis_ ;
 		std::shared_ptr<std::vector<std::shared_ptr<Vector>>> Amus_ ;
		std::shared_ptr<std::vector<std::shared_ptr<FieldCoupling>>> Fcpl_ ; 
		std::shared_ptr<std::vector<std::shared_ptr<Field>>> F_ ; 
	public:
		ClassicModel() : Model() {} ; 
		ClassicModel(std::string name_, Symmetries& sym	, std::vector<std::shared_ptr<GaugeCoupling>>& g_cpl
								, std::vector<std::shared_ptr<Scalar>>& phis
								, std::vector<std::shared_ptr<Spinor>>& psis
								, std::vector<std::shared_ptr<Vector>>& Amus
								, std::vector<std::shared_ptr<FieldCoupling>>& Fcpl) ; 
		~ClassicModel() {
			//delete F_ ; F_ = 0 ;
			} ; 

		void SetFieldCoupling(std::shared_ptr<std::vector<std::shared_ptr<FieldCoupling>>>& Fcpl) {Fcpl_ = Fcpl; } ; 
		std::shared_ptr<std::vector<std::shared_ptr<FieldCoupling>>> GetFieldCoupling() const {return Fcpl_;} ; 
		virtual std::shared_ptr<std::vector<std::shared_ptr<Coupling>>> GetCoupling() const {return cpl_;} ; 
		virtual std::shared_ptr<std::vector<std::shared_ptr<Field>>> GetFields() const ; 		
		virtual bool SolveRGE() const ; 		
} ; 

#endif
