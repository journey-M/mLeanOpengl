#include "../include/Player.h"
#include <thread>



void Player::init(){
    decoder =new  Decoder();
    decoder ->init("/home/guoweiji/test.mp4", "audio.pcm", "vidoe.yuv");
    std::thread th (&Decoder::startDecode, decoder);
    th.detach();


    this->initVertex();
    this->initShader();
    this->initTexture();
    
}

void Player::initShader(){
    shader = new Shader("res/player.vs", "res/player.fs");
    int errNo = glGetError();
    printf( "inishader : %d \n", errNo);

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

    int err =  glad_glGetError();
    printf("before init texture  :  %d  \n", err);

    glGenTextures(1, &textureY);
    // glActiveTexture(0);
    glBindTexture(GL_TEXTURE_2D, textureY);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    err =  glad_glGetError();
    printf("before init texture  1:  %d  \n", err);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, decoder->width, decoder->height, 0, GL_RED, GL_UNSIGNED_BYTE, NULL);
    err =  glad_glGetError();
    printf("before init texture  1:  %d  width : %d   height :  %d \n", err, decoder->width, decoder->height);

    GL_NO_ERROR;
    glGenTextures(1, &textureU);
    glBindTexture(GL_TEXTURE_2D, textureU);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, decoder->width/2, decoder->height/2, 0, GL_RED, GL_UNSIGNED_BYTE, NULL);
    
    err =  glad_glGetError();
    printf("before init texture  2:  %d  width : %d   height :  %d \n", err, decoder->width, decoder->height);

    glGenTextures(1, &textureV);
    glBindTexture(GL_TEXTURE_2D, textureV);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, decoder->width/2, decoder->height/2, 0, GL_RED, GL_UNSIGNED_BYTE, NULL);
    
    err =  glad_glGetError();
    printf("before init texture  3:  %d  width : %d   height :  %d \n", err, decoder->width, decoder->height);
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
    err =  glad_glGetError();
    printf(" init texture  :  %d  \n", err);
}

void Player::render(){
    // printf("this is in render start ... \n");
    //

    shader->use();

    bool render = true;
    if(decoder->decodyuv.size()>0 && render ){
      uint8_t * tmp = decoder->decodyuv.top();
      decoder->decodyuv.pop();

      uint8_t *y = tmp;
      uint8_t *u = tmp + decoder->width * decoder->height ;
      uint8_t *v = u + decoder->width * decoder->height/ 4; 
      
      glActiveTexture(GL_TEXTURE0);
      glBindTexture(GL_TEXTURE_2D ,textureY);
      glTexSubImage2D(GL_TEXTURE_2D, 0,  0,0, decoder->width, decoder->height, GL_RED, GL_UNSIGNED_BYTE, y);
      glGenerateMipmap(GL_TEXTURE_2D);
      shader->setInt("texturey", 0);

      
      glActiveTexture(GL_TEXTURE1);
      glBindTexture(GL_TEXTURE_2D ,textureU);
      glTexSubImage2D(GL_TEXTURE_2D, 0,0,0 , decoder->width/2, decoder->height/2,GL_RED, GL_UNSIGNED_BYTE, u);
      glGenerateMipmap(GL_TEXTURE_2D);
      shader->setInt("textureu", 1);

      glActiveTexture(GL_TEXTURE2);
      glBindTexture(GL_TEXTURE_2D ,textureV);
      glTexSubImage2D(GL_TEXTURE_2D,0,0, 0, decoder->width/2, decoder->height/2, GL_RED, GL_UNSIGNED_BYTE, v);
      glGenerateMipmap(GL_TEXTURE_2D);
      shader->setInt("textureV", 2);

      int err =  glad_glGetError();
      if(err != 0){
        printf("err after settexture  :  %d  \n", err);
        exit(-1) ;
      }
      free(tmp);

      glBindVertexArray(VAO); 
      // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
      // glDrawArrays(GL_TRIANGLES, 0, 6);
      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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

//    printf("err end in render  \n");
}
