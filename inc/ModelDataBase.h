#ifndef ModelDataBase_h
#define ModelDataBase_h
#include "../inc/Model.h"
#include <memory>

class ModelDataBase {
	public:
		ModelDataBase() {} ; 
		~ModelDataBase() {} ; 
//		SUSYModel* LoadMSSM() ; 
		std::unique_ptr<SUSYModel> LoadMSSM() ; 
} ; 

#endif
