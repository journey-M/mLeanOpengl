#ifndef _LEANSHADER_H__
#define __LEANSHADER_H__

#include "./IOperator.h"

class LeanShader:public IOperator{
	private:
		void init();


	public:
	 	void render();	
		
		void initShader();
		void initVertex();
};

#endif
