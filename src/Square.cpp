#include <stdio.h>

#include "../include/Square.h"
#include "../include/glad/glad.h"


const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.2f, 0.2f, 1.0f);\n"
    "}\n\0";

unsigned int shaderProgram;
unsigned int VAO;
unsigned int VBO;
unsigned int EBO;

float vertices [] = {
    0.5f, 0.5f , 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f, 0.5f, 0.0f
};
unsigned int indices [] = {
    0, 1, 3, 
    1, 2, 3   
};

void Square::init() {
  IOperator::init();
	this->initVertex();
	this->initShader();
}


void Square::initShader(){
	unsigned int vertexShader; 
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

	int success ;
	char infoLog[512];
 	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);	
	if(!success){
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		printf("ERRO::SHARED: VERTEX compile er ");
	}

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
 	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);	
	if(!success){
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		printf("ERRO::SHARED: VERTEX compile er 22222 ");
	}

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
	//check is success
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if(!success){
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		printf("Error : error link shader program!");
	}

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

}



void Square::initVertex(){

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER , VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 3. 复制我们的索引数组到一个索引缓冲中，供OpenGL使用
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // // 4. 设定顶点属性指针
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);	
}

void Square::render(){
	// printf("this is in Square render Game! \n");

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    // printf("error  ====  %d  \n", glGetError());

}
