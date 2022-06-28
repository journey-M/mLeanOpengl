#ifndef __TEST_FILE_SHADER_H__
#define __TEST_FILE_SHADER_H__

#include "glad/glad.h"
#include "IOperator.h"
#include "Shader.h"


class TestFileShader: public IOperator{
	private:

	Shader* shader = nullptr;
	unsigned int VAO;
	unsigned int VBO;

		void init() override;
		
  void destroy() override;
	public:

		void initShader();
		void initVertex();

	 	void render() override;	

};

#endif
