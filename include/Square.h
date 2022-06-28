#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "./IOperator.h"

class Square:public IOperator{
	private:
		void init() override;
		
	public:
	 	void render() override;	
		
		void initShader();
		void initVertex();
};

#endif
