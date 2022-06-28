#include <stdio.h>
#include "../include/LeanShader.h"
#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <math.h>

void LeanShader::init(){
	printf("init  lenaSahder! \n"	);
  IOperator::init();
	this->initShader();
	this->initVertex();
}

    void LeanShader::destroy() {
  glDeleteVertexArrays(1,&VAO1);
  glDeleteBuffers(1, &VBO1);
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
  glDeleteProgram(shaderProgram1);
    }
const char *vertexShaderSource1 = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
/** const char *fragmentShaderSource1 = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";
**/

const char *fragmentShaderSource1 = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"uniform vec4 ourColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = ourColor;\n"
		"}\n\0";



void LeanShader::initVertex(){
	
	printf("this is in initVertex ! \n"	);

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f,	-0.5f, 0.0f,
		0.0f, 0.5f, 0.0f,
		// second triangle
		0.0f, -0.0f, 0.0f,  // left
		-0.5f, 0.5f, 0.0f,  // right
		0.5f, 0.5f, 0.0f   // top 
	};
	// 1.intput vertices
	glGenVertexArrays(1, &VAO1);
	glGenBuffers(1, &VBO1);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO1);

	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 3* sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO1 as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// You can unbind the VAO1 afterwards so other VAO1 calls won't accidentally modify this VAO1, but this rarely happens. Modifying other
	// VAO1s requires a call to glBindVertexArray anyways so we generally don't unbind VAO1s (nor VBO1s) when it's not directly necessary.
	glBindVertexArray(0);	


}
void LeanShader::initShader(){

	//2. create gl shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource1, NULL);
	glCompileShader(vertexShader);

	int success ;
	char infoLog[512];
 	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);	
	if(!success){
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		printf("ERRO::SHARED: VERTEX compile er ");
	}

	//compile fragment shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource1, NULL);
	glCompileShader(fragmentShader);
 	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);	
	if(!success){
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		printf("ERRO::SHARED: VERTEX compile er 22222 ");
	}
	
	//link shader
	shaderProgram1 = glCreateProgram();
	glAttachShader(shaderProgram1, vertexShader);
	glAttachShader(shaderProgram1, fragmentShader);
	glLinkProgram(shaderProgram1);

	//check is success
	glGetProgramiv(shaderProgram1, GL_LINK_STATUS, &success);
	if(!success){
		glGetProgramInfoLog(shaderProgram1, 512, NULL, infoLog);
		printf("Error : error link shader program!");
	}

	// use program
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}


void LeanShader::render(){
	printf("this is in runRenderProgram ! \n");

	//实时设置颜色 uniform
	float timeValue = glfwGetTime();
	float greenValue = (sin(timeValue)/2.0f)+0.5;
	int vertextColorLocation = glGetUniformLocation(shaderProgram1, "ourColor");
	glUniform4f(vertextColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
	
	glUseProgram(shaderProgram1);
	glBindVertexArray(VAO1); 
	// seeing as we only have a single VAO1 there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_TRIANGLES, 0, 6);
}
