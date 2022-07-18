#include "../../include/advancegl/CubeSkyBox.h"
#include <string>


void CubeSkyBox::init() {
  printf("init CubeSkyBox..");
  IOperator::init();

  initVertex();
  initShader();
  initModel();
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS); 
}

void CubeSkyBox::destroy() {
  if (shader != NULL) {
    if (shader->vertixShader > 0) {
      glDeleteShader(shader->vertixShader);
    }
    if (shader->fragmentShader > 0) {
      glDeleteShader(shader->fragmentShader);
    }
    if (shader->ID > 0) {
      glDeleteProgram(shader->ID);
    }
  }

}

void CubeSkyBox::initShader() {
  shader = new Shader(
      std::string(baseDir).append("res/advancegl/6.1.cubemaps.vs").c_str(),
      std::string(baseDir).append("res/advancegl/6.1.cubemaps.fs").c_str());

  skyboxShader = new Shader(
      std::string(baseDir).append("res/advancegl/6.1.skybox.vs").c_str(),
      std::string(baseDir).append("res/advancegl/6.1.skybox.fs").c_str());

}

void CubeSkyBox::initModel(){
  // load models

  cubeTexture  = loadTexture(std::string(baseDir).append("res/container.jpg").c_str());
  cubeMapTexture = loadCubemap(faces);
  shader->use();
  shader->setInt("texture1", 0);

  skyboxShader->use();
  skyboxShader->setInt("skybox", 0);


}



unsigned int CubeSkyBox::loadTexture(char const *path) {
  unsigned int textureID;
  glGenTextures(1, &textureID);

  int width, height, nrComponents;
  unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
  if (data) {
    GLenum format;
    if (nrComponents == 1)
      format = GL_RED;
    else if (nrComponents == 3)
      format = GL_RGB;
    else if (nrComponents == 4)
      format = GL_RGBA;

    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,
                 GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(data);
  } else {
    std::cout << "Texture failed to load at path: " << path << std::endl;
    stbi_image_free(data);
  }

  return textureID;
}

// loads a cubemap texture from 6 individual texture faces
// order:
// +X (right)
// -X (left)
// +Y (top)
// -Y (bottom)
// +Z (front) 
// -Z (back)
// -------------------------------------------------------
unsigned int CubeSkyBox::loadCubemap(std::vector<std::string> faces)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

    int width, height, nrChannels;
    for (unsigned int i = 0; i < faces.size(); i++)
    {
        unsigned char *data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
            stbi_image_free(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return textureID;
}




void CubeSkyBox::initVertex() {
  // cube VAO
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &cubeVBO);
    glBindVertexArray(cubeVAO);
    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), &cubeVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glBindVertexArray(0);


// plane VAO
    glGenVertexArrays(1, &skyboxVAO);
    glGenBuffers(1, &skyboxVBO);
    glBindVertexArray(skyboxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}

void CubeSkyBox::render() {

  float currentFrame = static_cast<float>(glfwGetTime());
  deltaTime = currentFrame - lastFrame;
  lastFrame = currentFrame;

   // render
    // ------
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  shader->use();
  glm::mat4 model = glm::mat4(1.0f);
  glm::mat4 view = camera.GetViewMatrix();
  glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)800 / (float)600, 0.1f, 100.0f);
  shader->setMat4("model", model);
  shader->setMat4("view", view);
  shader->setMat4("projection", projection);
   // cubes
  glBindVertexArray(cubeVAO);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, cubeTexture);
  glDrawArrays(GL_TRIANGLES, 0, 36);
  glBindVertexArray(0);
 

  // draw skybox as last
  glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
  skyboxShader->use();
  view = glm::mat4(glm::mat3(camera.GetViewMatrix())); // remove translation from the view matrix
  skyboxShader->setMat4("view", view);
  skyboxShader->setMat4("projection", projection);
  // skybox cube
  glBindVertexArray(skyboxVAO);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_CUBE_MAP, cubeMapTexture);
  glDrawArrays(GL_TRIANGLES, 0, 36);
  glBindVertexArray(0);
  glDepthFunc(GL_LESS); // set depth function back to default

}

void CubeSkyBox::proceessKeyEvent(int key) {

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
void CubeSkyBox::mouse_callback(double xposIn, double yposIn) {
  float xpos = static_cast<float>(xposIn);
  float ypos = static_cast<float>(yposIn);

  if (firstMouse) {
    lastX = xpos;
    lastY = ypos;
    firstMouse = false;
  }

  float xoffset = xpos - lastX;
  float yoffset =
      lastY - ypos; // reversed since y-coordinates go from bottom to top

  lastX = xpos;
  lastY = ypos;

  camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void CubeSkyBox::scroll_callback(double xoffset, double yoffset) {
  camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
