#ifndef __CAMERA_MOVE_H__
#define __CAMERA_MOVE_H__

#include "./IOperator.h"
#include "./Shader.h"
#include "./glm/glm.hpp"
#include "stb_image.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <GLFW/glfw3.h>

class CameraMove:public IOperator{
	private:
		void init();

		Shader* shader;
        unsigned int VAO;
        unsigned int VBO;
		unsigned int texture1, texture2;
		// camera
		glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
		glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);


		char * strTest = "this is a test in char * ";

	public:

	 	void render();
		void initShader();
		void initVertex();
        void initTexture();

		void proceessKeyEvent(int key);

				// timing

};

#endif