#include "../include/TestFileShader.h"

void TestFileShader::init(){
  IOperator::init();
	printf("init  TestFielShader! \n"	);
    this->initShader();
    this->initVertex();
}

  void TestFileShader:: destroy() {
	    glDeleteVertexArrays(1,&VAO);
  glDeleteBuffers(1, &VBO);
  if(shader== NULL){
	  return ;
  }
  if(shader->vertixShader > 0){
    glDeleteShader(shader->vertixShader);
  }
  if(shader->fragmentShader >0){
    glDeleteShader(shader->fragmentShader);

  }
  if(shader->ID >0){
    glDeleteProgram(shader->ID);
  }
  }

void TestFileShader::initShader(){
    shader = new Shader("res/trigle.sc", "res/frag.sc");
}



void TestFileShader::initVertex(){
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


void TestFileShader::render(){
    shader->use();
    glBindVertexArray(VAO); 
	// seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_TRIANGLES, 0, 6);

}
	
