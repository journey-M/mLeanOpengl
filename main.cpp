#include <stdio.h>
#include "include/glad/glad.h"
#include <GLFW/glfw3.h>
#include "include/IOperator.h"
#include "include/Camera.h"

Single Single::instance;

void processInput(GLFWwindow* window){

	if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS){
		glfwSetWindowShouldClose(window, true);				
	}
	IOperator * opt = Single::instance.getOperator();
	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
		opt -> proceessKeyEvent(GLFW_KEY_W);
	}
	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
		opt -> proceessKeyEvent(GLFW_KEY_A);
	}
	if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
		opt -> proceessKeyEvent(GLFW_KEY_D);
	}
	if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
		opt -> proceessKeyEvent(GLFW_KEY_S);
	}
}

void key_callback(GLFWwindow * window, int key, int scancode , int action , int mods){

	if (action != GLFW_PRESS)
	{
		return ;
	}
	
	if(Single::instance.getOperator()){
		IOperator * opt = Single::instance.getOperator();
		opt -> proceessKeyEvent(key);
	}

}



int main(int argc, char** argv){
	printf("this is in main function ! \n");

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window = glfwCreateWindow(800, 600, "lean gl",NULL, NULL);
	if(window == NULL){
		printf("Failed to create GLFW window ! \n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	// glfwSetKeyCallback(window, key_callback);

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
			printf("Failed to initialize GLAD ! \n");
			return -1;
	}
	glViewport(0,0,800,600);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	IOperator* opclz;
	opclz = Single::instance.getOperator(); 
	opclz ->init();


	while(!glfwWindowShouldClose(window)){
		processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
		
		opclz->render();


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
