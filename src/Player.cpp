#include "../include/Player.h"
#include <thread>



void Player::init(){
    decoder =new  Decoder();
    decoder ->init("/home/gwj/bb.mp4", "audio.pcm", "vidoe.yuv");
    std::thread th (&Decoder::startDecode, decoder);
    th.detach();


    this->initVertex();
    this->initShader();
    this->initTexture();
    
}

void Player::initShader(){
    shader = new Shader("res/player.vs", "res/player.fs");
}

void Player::initVertex(){
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

void Player::initTexture(){

    glGenTextures(1, &textureY);
    glBindTexture(GL_TEXTURE_2D, textureY);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);   
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glGenTextures(1, &textureU);
    glBindTexture(GL_TEXTURE_2D, textureU);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);   
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    

    glGenTextures(1, &textureV);
    glBindTexture(GL_TEXTURE_2D, textureV);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);   
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // int width, height, nrchannels;
    // unsigned char *data = stbi_load("res/container.jpg", &width, &height, &nrchannels, 0);
    // if (data)
    // {
    //     glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, width, height, 0, GL_ALPHA, GL_UNSIGNED_BYTE, data);
    //     glGenerateMipmap(GL_TEXTURE_2D);
    // }
    // else
    // {
    //     std::cout << "failed to load texture" << std::endl;
    // }
    // stbi_image_free(data);
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D ,textureY); 
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D ,textureU);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D ,textureV);
}

void Player::render(){
    printf("this is in render start ... \n");

    if(decoder->decodyuv.size()>0 ){
      uint8_t * tmp = decoder->decodyuv.top();
      decoder->decodyuv.pop();

      uint8_t *y = tmp;
      uint8_t *u = tmp + decoder->width * decoder->height ;
      uint8_t *v = u + decoder->width * decoder->height/ 4; 
      
      glBindTexture(GL_TEXTURE_2D ,textureY);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, decoder->width, decoder->height,0, GL_ALPHA, GL_UNSIGNED_BYTE, y);
      glGenerateMipmap(GL_TEXTURE_2D);
      
      glBindTexture(GL_TEXTURE_2D ,textureU);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, decoder->width, decoder->height,0, GL_ALPHA, GL_UNSIGNED_BYTE, u);
      glGenerateMipmap(GL_TEXTURE_2D);
      
      glBindTexture(GL_TEXTURE_2D ,textureV);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, decoder->width, decoder->height,0, GL_ALPHA, GL_UNSIGNED_BYTE, v);
      glGenerateMipmap(GL_TEXTURE_2D);

      shader->setInt("textureY", 0);
      shader->setInt("textureU", 1);
      shader->setInt("textureV", 2);

      int err =  glad_glGetError();
      printf("err is settexture  :  %d  \n", err);
      free(tmp);
    }

    // 解码 rgb数据
    // if(decoder->decodrgb.size()>0 ){
    //   uint8_t * tmp = decoder->decodrgb.top();
    //   decoder->decodrgb.pop();
    //
    //   uint8_t *y = tmp;
    //   uint8_t *u = tmp + decoder->width / 4;
    //   uint8_t *v = u + decoder->width / 4; 
    //   
    //   glBindTexture(GL_TEXTURE_2D ,textureY);
    //   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, decoder->width, decoder->height,0, GL_RGB, GL_UNSIGNED_BYTE, y);
    //   glGenerateMipmap(GL_TEXTURE_2D);
    //
    //   shader->setInt("textureY", 0);
    //   free(tmp);
    // }

    shader->use();

    int err =  glad_glGetError();
    printf("err after settexture  :  %d  \n", err);

    glBindVertexArray(VAO); 
    // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    // glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    printf("redner  time   end  \n ");
}
