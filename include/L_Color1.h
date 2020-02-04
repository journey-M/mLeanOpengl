#ifndef __LCOLOR1_H__
#define __LCOLOR1_H__

#include "./IOperator.h"

class LColor1:public IOperator{
	private:
		void init();
		
		
	public:
	 	void render();	
		
		void initShader();
		void initVertex();
};

#endif
