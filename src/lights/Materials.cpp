#include "../../include/lights/Materials.h"
#include <string>

void Material::init(){
  printf("init BasicLightgSpecular..");
  IOperator::init();

  initVertex();
  initShader();
  glEnable(GL_DEPTH_TEST);


}

void Material::destroy(){
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

void Material::initShader(){
  lightingShader = new Shader(std::string(baseDir).append("res/lights/3.1.materials.vs").c_str(), 
    std::string(baseDir).append("res/lights/3.1.materials.fs").c_str());
  lightCubeShader = new Shader(std::string(baseDir).append("res/lights/3.1.light_cube.vs").c_str(), 
    std::string(baseDir).append("res/lights/3.1.light_cube.fs").c_str());
}

void Material::initVertex(){
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

void Material::render(){

  float currentFrame = static_cast<float>(glfwGetTime());
  deltaTime = currentFrame - lastFrame;
  lastFrame = currentFrame;


  //clear the depth buffer noew !
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



  lightingShader->use();
  lightingShader->setVec3("light.position", lightPos);
  lightingShader->setVec3("viewPos", camera.Position);

  // light properties
  glm::vec3 lightColor;
  lightColor.x = static_cast<float>(sin(glfwGetTime() * 2.0));
  lightColor.y = static_cast<float>(sin(glfwGetTime() * 0.7));
  lightColor.z = static_cast<float>(sin(glfwGetTime() * 1.3));
  glm::vec3 diffuseColor = lightColor   * glm::vec3(0.5f); // decrease the influence
  glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f); // low influence
  lightingShader->setVec3("light.ambient", ambientColor);
  lightingShader->setVec3("light.diffuse", diffuseColor);
  lightingShader->setVec3("light.specular", 1.0f, 1.0f, 1.0f);

  // material properties
  lightingShader->setVec3("material.ambient", 1.0f, 0.5f, 0.31f);
  lightingShader->setVec3("material.diffuse", 1.0f, 0.5f, 0.31f);
  lightingShader->setVec3("material.specular", 0.5f, 0.5f, 0.5f); // specular lighting doesn't have full effect on this object's material
  lightingShader->setFloat("material.shininess", 32.0f);

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


void Material::proceessKeyEvent(int key) {

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
void Material::mouse_callback( double xposIn, double yposIn)
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
void Material::scroll_callback( double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
