#include "../../include/lights/BasicLightingSpecular.h"
#include <string>

void BasicLightingSpecular::init(){
  IOperator::init();

  initVertex();
  initShader();

}

void BasicLightingSpecular::destroy(){
  glDeleteVertexArrays(1,&cubeVAO);
  glDeleteBuffers(1, &VBO);
  if(lightingShader!= NULL){
    if(lightingShader->vertixShader > 0){
      glDeleteShader(lightingShader->vertixShader);
    }
    if(lightingShader->fragmentShader >0){
      glDeleteShader(lightingShader->fragmentShader);

    }
    if(lightingShader->ID >0){
      glDeleteProgram(lightingShader->ID);
    }
  }

  if(lightCubeShader!= NULL){
    if(lightCubeShader->vertixShader > 0){
      glDeleteShader(lightCubeShader->vertixShader);
    }
    if(lightCubeShader->fragmentShader >0){
      glDeleteShader(lightCubeShader->fragmentShader);

    }
    if(lightCubeShader->ID >0){
      glDeleteProgram(lightCubeShader->ID);
    }
  }

}

void BasicLightingSpecular::initShader(){
  lightingShader = new Shader(std::string(baseDir).append("res/lights/2.basic_lighting.vs").c_str(), 
    std::string(baseDir).append("res/lights/2.basic_lighting.fs").c_str());
  lightCubeShader = new Shader(std::string(baseDir).append("res/lights/2.ligth_cube.vs").c_str(), 
    std::string(baseDir).append("res/lights/2.ligth_cube.fs").c_str());
}

void BasicLightingSpecular::initVertex(){
  float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };


  glGenVertexArrays(1, &cubeVAO);
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindVertexArray(cubeVAO);

  // position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  // normal attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  //lightCubeVAO vao
  glGenVertexArrays(1, &lightCubeVAO);
  glBindVertexArray(lightCubeVAO);

  // we only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need (it's already bound, but we do it again for educational purposes)
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);


}

void BasicLightingSpecular::render(){
  float currentFrame = static_cast<float>(glfwGetTime());
  deltaTime = currentFrame - lastFrame;
  lastFrame = currentFrame;

  lightingShader->use();
  lightingShader->setVec3("objectColor", 1.0f, 0.5f, 0.31f);
  lightingShader->setVec3("lightColor",  0.1f, 1.0f, 1.0f);
  lightingShader->setVec3("lightPos", lightPos);
  lightingShader->setVec3("viewPos", camera.Position);

  // view/projection transformations
  glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)800 / (float)600, 0.1f, 100.0f);
  glm::mat4 view = camera.GetViewMatrix();
  lightingShader->setMat4("projection", projection);
  lightingShader->setMat4("view", view);

  // world transformation
  glm::mat4 model = glm::mat4(1.0f);
  lightingShader->setMat4("model", model);

  // render the cube
  glBindVertexArray(cubeVAO);
  glDrawArrays(GL_TRIANGLES, 0, 36);


  // also draw the lamp object
  lightCubeShader->use();
  lightCubeShader->setMat4("projection", projection);
  lightCubeShader->setMat4("view", view);
  model = glm::mat4(1.0f);
  model = glm::translate(model, lightPos);
  model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
  lightCubeShader->setMat4("model", model);

  glBindVertexArray(lightCubeVAO);
  glDrawArrays(GL_TRIANGLES, 0, 36);
}


void BasicLightingSpecular::proceessKeyEvent(int key) {

  switch (key) {
  case GLFW_KEY_W:
        camera.ProcessKeyboard(FORWARD, deltaTime);
    break;
  case GLFW_KEY_A:
        camera.ProcessKeyboard(LEFT, deltaTime);

    break;
  case GLFW_KEY_S:
        camera.ProcessKeyboard(BACKWARD, deltaTime);

    break;
  case GLFW_KEY_D:
        camera.ProcessKeyboard(RIGHT, deltaTime);
    break;
  default:
    break;
  }
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void BasicLightingSpecular::mouse_callback( double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void BasicLightingSpecular::scroll_callback( double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}