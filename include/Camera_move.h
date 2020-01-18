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

		char * strTest = "this is a test in char * ";

		float deltaTime;	// time between current frame and last frame
		float lastFrame;

		// camera
		glm::vec3 cameraPos;
		glm::vec3 cameraFront;
		glm::vec3 cameraUp;

	public:

		CameraMove();
	 	void render();
		void initShader();
		void initVertex();
        void initTexture();

		void proceessKeyEvent(int key);



};

#endif