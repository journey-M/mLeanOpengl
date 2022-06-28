#ifndef __LCOLOR1_H__
#define __LCOLOR1_H__

#include "./IOperator.h"

class LColor1:public IOperator{
	private:
		void init() override;
		
		void destroy() override;
	public:
	 	void render() override;	
		
		void initShader();
		void initVertex();
};

#endif
