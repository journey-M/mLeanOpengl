#ifndef __Material_H__
#define __Material_H__

#include "../IOperator.h"
#include "../Shader.h"
#include "../glm/glm.hpp"
#include "include/Camera.h"
#include "../stb_image.h"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "include/glm/fwd.hpp"
#include <GLFW/glfw3.h>


class Material:public IOperator{
	private:
		void init() override;
		void destroy() override;
    
	public:

		Camera camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
		float lastX = 800 / 2.0f;
		float lastY = 600 / 2.0f;
		bool firstMouse = true;

		// timing
		float deltaTime = 0.0f;
		float lastFrame = 0.0f;

		// lighting
		glm::vec3 lightPos = glm::vec3(1.2f, 1.0f, 2.0f);

		Shader* lightingShader;
		Shader* lightCubeShader;

		unsigned int VBO, cubeVAO;
 		unsigned int lightCubeVAO;
	 	
		void render() override;	
		void mouse_callback(double xoffset, double yoffset) override;
		void scroll_callback(double xoffset, double yoffset) override;
  		virtual void proceessKeyEvent(int key) override;
		void initShader();
		void initVertex();
};

#endif
