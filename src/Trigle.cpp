#include <stdio.h>
#include "../include/Trigle.h"
#include "../include/glad/glad.h"

void Trigle::init(){
	this->initShader();
	this->initVertex();
}


void Trigle::initVertex(){
	
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
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 3* sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);	


}
void Trigle::initShader(){

	//2. create gl shader
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

	//compile fragment shader
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
 	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);	
	if(!success){
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		printf("ERRO::SHARED: VERTEX compile er 22222 ");
	}
	
	//link shader
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

	// use program
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}


void Trigle::render(){
	printf("this is in runRenderProgram ! \n");
	
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO); 
	// seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_TRIANGLES, 0, 6);
}
