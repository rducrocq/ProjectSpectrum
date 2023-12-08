#ifndef ModelDataBase_h
#define ModelDataBase_h
#include "../inc/Model.h"
#include <memory>

class ModelDataBase {
	public:
		ModelDataBase() {} ; 
		~ModelDataBase() {} ; 
 
		std::unique_ptr<SUSYModel> LoadMSSM() ; 
} ; 

#endif
