#ifndef __COORDINATE_H_
#define __COORDINATE_H_

#include "./IOperator.h"
#include "./Shader.h"
#include "./glm/glm.hpp"
#include "stb_image.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Coordinate :public IOperator{
	private:
		void init();

		Shader* shader;
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
		unsigned int texture1, texture2;

	public:
	 	void render();	
		
		void initShader();
		void initVertex();
        void initTexture();
};

#endif
