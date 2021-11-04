#ifndef __CAMERA_01_H__
#define __CAMERA_01_H__

#include "./Shader.h"
#include "./glm/glm.hpp"
#include "stb_image.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <GLFW/glfw3.h>

class Camera01 {
	private:
		void init();

		Shader* shader;
        unsigned int VAO;
        unsigned int VBO;
		unsigned int texture1, texture2;
		// camera


	public:
	 	void render();
		void initShader();
		void initVertex();
        void initTexture();

		void proceessKeyEvent(int key);

};

#endif