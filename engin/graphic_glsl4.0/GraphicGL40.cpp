#include <bits/types/FILE.h>
#include <cstddef>
#include <stdio.h>


#include "include/GraphicGL40.h"

EventBase * GraphicGL40::eventBase = nullptr;

bool GraphicGL40::create(int widht, int height){
	printf("GraphicGL40 init start ! \n");

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(widht, height, "lean gl",NULL, NULL);
 	if(window == NULL){
		printf("Failed to create GLFW window ! \n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		printf("Failed to initialize GLAD ! \n");
		return -1;
	}
	glViewport(0,0,widht,height);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	return true;
}


	bool GraphicGL40::setEventCallback(EventBase* base) {
		GraphicGL40::eventBase = base;
		return true;
	}


	int GraphicGL40::clearPreFrame() {
		glad_glClearColor(0.8f, 0.5f, 0.5f, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		return 0;
	}


	int GraphicGL40::renderFrame(){

		if(!glfwWindowShouldClose(window)){
			processInput(window);
			glfwPollEvents();
		}

		glfwSwapBuffers(window);
		return 0;
	}



	bool GraphicGL40::release(){
		glfwTerminate();
		return true;
	}


	void GraphicGL40::processInput(GLFWwindow* window){

		if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS){
			glfwSetWindowShouldClose(window, true);				
		}

		if(this->eventBase == nullptr){
			return ;
		}

		if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
			// opt -> proceessKeyEvent(GLFW_KEY_W);
			this->eventBase->proceessKeyEvent('W');
		}
		if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
			// opt -> proceessKeyEvent(GLFW_KEY_A);
			this->eventBase->proceessKeyEvent('A');
		}
		if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
			// opt -> proceessKeyEvent(GLFW_KEY_D);
			this->eventBase->proceessKeyEvent('D');
		}
		if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
			// opt -> proceessKeyEvent(GLFW_KEY_S);
			this->eventBase->proceessKeyEvent('S');
		}
		
	}

	void GraphicGL40::mouse_callback(GLFWwindow * window, double xoffset, double yoffset){
		// Single::instance.getOperator()->mouse_callback(xoffset, yoffset);
		if(GraphicGL40::eventBase == nullptr){
			return ;
		}
		GraphicGL40::eventBase->mouse_callback(xoffset, yoffset);
	}

	void GraphicGL40::scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
		// Single::instance.getOperator()->scroll_callback(xoffset, yoffset);
		if(GraphicGL40::eventBase == nullptr){
			return ;
		}
		GraphicGL40::eventBase->scroll_callback(xoffset, yoffset);

	};
