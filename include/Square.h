#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "./IOperator.h"

class Square:public IOperator{
	private:
	void init() override;

  	unsigned int shaderProgram;
	unsigned int vertexShader; 
    unsigned int fragmentShader;

unsigned int VAO;
unsigned int VBO;
unsigned int EBO;
		
	public:
  		void destroy() override;

	 	void render() override;	
		
		void initShader();
		void initVertex();
};

#endif
