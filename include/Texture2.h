#ifndef __TEXTURE2_H__
#define __TEXTURE2_H__

#include "./IOperator.h"
#include "stb_image.h"
#include "Shader.h"


class Texture2 :public IOperator{
	private:
		void init() override;

  void destroy() override;
        void initShader();
		void initVertex();
        void initTexture();
        void afterInit();
    

        unsigned int shaderProgram;
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
        unsigned int texture1;
        unsigned int texture2;
        Shader * shader;

	public:
	 	void render() override;	
		

};

#endif
