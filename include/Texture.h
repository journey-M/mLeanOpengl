#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "./IOperator.h"
#include "stb_image.h"
#include "Shader.h"


class Texture :public IOperator{
	private:
		void init() override;

  void destroy() override;
        unsigned int shaderProgram;
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
        unsigned int texture;
        Shader * shader;

	public:
	 	void render() override;	
		
		void initShader();
		void initVertex();
        void initTexture();
};

#endif
