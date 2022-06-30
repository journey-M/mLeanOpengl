#include "../include/Texture.h"



void Texture::init(){
  IOperator::init();
    this->initVertex();
    this->initShader();
    this->initTexture();
}

  void Texture::destroy() {
        glDeleteVertexArrays(1,&VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);

  glDeleteTextures(1, &texture); 
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
void Texture::initShader(){
  shader = new Shader(std::string(baseDir).append("res/texture.vs").c_str(),std::string(baseDir).append("res/texture.fs").c_str()); 

}

void Texture::initVertex(){
    float vertices[] = {
    //     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
    };
    unsigned int indices[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

	// 1.intput vertices
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW );

	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 8* sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2,GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)) );
    glEnableVertexAttribArray(2);
   
    // // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);	
}

void Texture::initTexture(){
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char *data = stbi_load(std::string(baseDir).append("res/container.jpg").c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}

void Texture::render(){

    // printf("this is in Texture... \n");
    glBindTexture(GL_TEXTURE_2D ,texture);

    shader->use();
    glBindVertexArray(VAO); 
	// seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	// glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}
