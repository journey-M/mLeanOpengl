#ifndef __LEANSHADER_H__
#define __LEANSHADER_H__

#include "./IOperator.h"

class LeanShader:public IOperator{
	private:
		void init() override;

    void destroy() override;


	unsigned int shaderProgram1;
unsigned int VAO1;
unsigned int VBO1;
	unsigned int vertexShader;
	unsigned int fragmentShader;


	public:
	 	void render() override;	
		
		void initShader();
		void initVertex();
};

#endif
