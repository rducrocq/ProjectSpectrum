#ifndef Model_h
#define Model_h

#include "../inc/Symmetry.h"
#include "../inc/Coupling.h"
#include "../inc/Field.h"
#include "../inc/Superfield.h"
#include <string>

class Model {
	protected:
		std::string name_ ; 
		Symmetries* sym_ ; 
		std::vector<GaugeCoupling*>* g_cpl_ ; 
		std::vector<Coupling*>* cpl_ ; 
	public: 
		Model() {} ; 
		Model(std::string name, Symmetries& sym, std::vector<GaugeCoupling*>& g_cpl) ; 
		virtual ~Model() {delete cpl_ ; cpl_ = 0 ;} ;
 
		std::vector<GaugeCoupling*>& GetGaugeCoupling() const {return *g_cpl_;} ; 
		Symmetries* GetSymmetries() const {return sym_ ;} ; 

//		virtual void SetCoupling(std::vector<Coupling*>& cpl) = 0 ; 
		virtual std::vector<Coupling*>* GetCoupling() const = 0 ; 
		virtual std::vector<Field*>* GetFields() const = 0 ; 		
		virtual bool SolveRGE() const = 0 ; 		
} ; 

class SUSYModel: public Model {
	private:
		std::vector<ChiralSF*>* Phis_ ; 
		std::vector<VectorSF*>* Vs_ ; 
		std::vector<SFCoupling*>* SFcpl_ ; 
		std::vector<Superfield*>* SF_ ; 
		std::vector<Field*>* F_ ; 
 
	public:
		SUSYModel() : Model() {} ; 
		SUSYModel(std::string name_, Symmetries& sym	, std::vector<GaugeCoupling*>& g_cpl
								, std::vector<ChiralSF*>& Phis
								, std::vector<VectorSF*>& Vs
								, std::vector<SFCoupling*>& SFcpl) ; 
		~SUSYModel() {
			for (auto sfcpl : *SFcpl_){
				delete sfcpl ; sfcpl = 0 ; 
			}
			delete SFcpl_ ; SFcpl_ = 0 ; 
			delete SF_ ; SF_ = 0 ; 
			delete F_; F_ = 0 ; 
			} ; 

		void SetSFCoupling(std::vector<SFCoupling*>* SFcpl) {SFcpl_ = SFcpl; } ; 
		std::vector<SFCoupling*>* GetSFCoupling() const {return SFcpl_;} ; 
		virtual std::vector<Coupling*>* GetCoupling() const {return cpl_;} ; 
		virtual std::vector<Field*>* GetFields() const ; 		
		virtual std::vector<Superfield*>* GetSuperFields() const ; 		
		virtual bool SolveRGE() const ; 		
} ; 

class ClassicModel: public Model {
	private:
		std::vector<Scalar*>* phis_ ; 
		std::vector<Spinor*>* psis_ ;
 		std::vector<Vector*>* Amus_ ;
		std::vector<FieldCoupling*>* Fcpl_ ; 
		std::vector<Field*>* F_ ; 
	public:
		ClassicModel() : Model() {} ; 
		ClassicModel(std::string name_, Symmetries& sym	, std::vector<GaugeCoupling*>& g_cpl
								, std::vector<Scalar*>& phis
								, std::vector<Spinor*>& psis
								, std::vector<Vector*>& Amus
								, std::vector<FieldCoupling*>& Fcpl) ; 
		~ClassicModel() {delete F_ ; F_ = 0 ;} ; 

		void SetFieldCoupling(std::vector<FieldCoupling*>& Fcpl) {Fcpl_ = &Fcpl; } ; 
		std::vector<FieldCoupling*>* GetFieldCoupling() const {return Fcpl_;} ; 
		virtual std::vector<Coupling*>* GetCoupling() const {return cpl_;} ; 
		virtual std::vector<Field*>* GetFields() const ; 		
		virtual bool SolveRGE() const ; 		
} ; 

#endif
