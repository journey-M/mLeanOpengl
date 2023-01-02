#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "./IOperator.h"
#include "stb_image.h"
#include "Shader.h"
#include "Decoder.h"


class Player:public IOperator{
	private:
    
    Decoder * decoder;
		void init();
    unsigned int shaderProgram;
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    unsigned int textureY;
    unsigned int textureU;
    unsigned int textureV;
    Shader * shader;

	public:
	 	void render();	
		
		void initShader();
		void initVertex();
    void initTexture();
};

#endif
