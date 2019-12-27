#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "./IOperator.h"

class Square:public IOperator{
	private:
		void init();
		
	public:
	 	void render();	
		
		void initShader();
		void initVertex();
};

#endif
