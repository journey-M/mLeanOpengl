#ifndef __CAMERA_MOUSE_H__
#define __CAMERA_MOUSE_H__

#include "./Shader.h"
#include "./glm/glm.hpp"
#include "stb_image.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <GLFW/glfw3.h>

class CameraMouse {
	private:
		void init();

		Shader* shader;
        unsigned int VAO;
        unsigned int VBO;
		unsigned int texture1, texture2;


		float deltaTime;	// time between current frame and last frame
		float lastFrame;

		// camera
		glm::vec3 cameraPos;
		glm::vec3 cameraFront;
		glm::vec3 cameraUp;

		bool firstMouse = true;
		float yaw   = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
		float pitch =  0.0f;
		float lastX =  800.0f / 2.0;
		float lastY =  600.0 / 2.0;
		float fov   =  45.0f;

	public:

		CameraMouse();
	 	void render();
		void initShader();
		void initVertex();
        void initTexture();

		void proceessKeyEvent(int key);
		void mouse_callback(double xoffset, double yoffset);
		void scroll_callback(double xoffset, double yoffset);


};

#endif