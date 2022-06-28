#ifndef __TRANSFORMATIONS_H__
#define __TRANSFORMATIONS_H__

#include "./IOperator.h"
#include "stb_image.h"
#include "Shader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <GLFW/glfw3.h>


class Transformation :public IOperator{
	private:
		void init() override;
    void destroy() override;

        unsigned int shaderProgram;
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
        unsigned int texture1;
        unsigned int texture2;
        Shader * shader;

	public:
	 	void render() override;	
		
		void initShader();
		void initVertex();
        void initTexture();
};

#endif
