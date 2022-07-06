#include "../../include/lights/MultipleLights.h"
#include "../../include/IOperator.h"
#include <string>

void MultipleLights::init() {
  printf("init MultipleLights.. \n");
  IOperator::init();

  initVertex();
  initShader();
  initTexture();
  glEnable(GL_DEPTH_TEST);
}

void MultipleLights::destroy() {
  glDeleteVertexArrays(1, &cubeVAO);
  glDeleteBuffers(1, &VBO);
  if (lightingShader != NULL) {
    if (lightingShader->vertixShader > 0) {
      glDeleteShader(lightingShader->vertixShader);
    }
    if (lightingShader->fragmentShader > 0) {
      glDeleteShader(lightingShader->fragmentShader);
    }
    if (lightingShader->ID > 0) {
      glDeleteProgram(lightingShader->ID);
    }
  }

  if (lightCubeShader != NULL) {
    if (lightCubeShader->vertixShader > 0) {
      glDeleteShader(lightCubeShader->vertixShader);
    }
    if (lightCubeShader->fragmentShader > 0) {
      glDeleteShader(lightCubeShader->fragmentShader);
    }
    if (lightCubeShader->ID > 0) {
      glDeleteProgram(lightCubeShader->ID);
    }
  }
}

void MultipleLights::initShader() {
  lightingShader = new Shader(
      std::string(baseDir).append("res/lights/6.multiple_lights.vs").c_str(),
      std::string(baseDir).append("res/lights/6.multiple_lights.fs").c_str());
  lightCubeShader = new Shader(
      std::string(baseDir).append("res/lights/6.light_cube.vs").c_str(),
      std::string(baseDir).append("res/lights/6.light_cube.fs").c_str());

  // shader configuration
  // --------------------
  lightingShader->use();
  lightingShader->setInt("material.diffuse", 0);
  lightingShader->setInt("material.specular", 1);
}

void MultipleLights::initVertex() {


  // first, configure the cube's VAO (and VBO)
  glGenVertexArrays(1, &cubeVAO);
  glGenBuffers(1, &VBO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindVertexArray(cubeVAO);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                        (void *)(6 * sizeof(float)));
  glEnableVertexAttribArray(2);

  // second, configure the light's VAO (VBO stays the same; the vertices are the
  // same for the light object which is also a 3D cube)
  glGenVertexArrays(1, &lightCubeVAO);
  glBindVertexArray(lightCubeVAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // note that we update the lamp's position attribute's stride to reflect the
  // updated buffer data
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
}

void MultipleLights::initTexture() {
  // load textures (we now use a utility function to keep the code more
  // organized)
  // -----------------------------------------------------------------------------
  diffuseMap = loadTexture(
      std::string(baseDir).append("res/textures/container2.png").c_str());
  specularMap =
      loadTexture(std::string(baseDir)
                      .append("res/textures/container2_specular.png")
                      .c_str());
}

void MultipleLights::render() {

  float currentFrame = static_cast<float>(glfwGetTime());
  deltaTime = currentFrame - lastFrame;
  lastFrame = currentFrame;

  // clear the depth buffer noew !
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // be sure to activate shader when setting uniforms/drawing objects
  lightingShader->use();
  lightingShader->setVec3("viewPos", camera.Position);
  lightingShader->setFloat("material.shininess", 32.0f);

  /*
      Here we set all the uniforms for the 5/6 types of lights we have. We have to set them manually and index 
      the proper PointLight struct in the array to set each uniform variable. This can be done more code-friendly
      by defining light types as classes and set their values in there, or by using a more efficient uniform approach
      by using 'Uniform buffer objects', but that is something we'll discuss in the 'Advanced GLSL' tutorial.
  */
  // directional light
  lightingShader->setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
  lightingShader->setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
  lightingShader->setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
  lightingShader->setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
  // point light 1
  lightingShader->setVec3("pointLights[0].position", pointLightPositions[0]);
  lightingShader->setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
  lightingShader->setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
  lightingShader->setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
  lightingShader->setFloat("pointLights[0].constant", 1.0f);
  lightingShader->setFloat("pointLights[0].linear", 0.09f);
  lightingShader->setFloat("pointLights[0].quadratic", 0.032f);
  // point light 2
  lightingShader->setVec3("pointLights[1].position", pointLightPositions[1]);
  lightingShader->setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
  lightingShader->setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
  lightingShader->setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
  lightingShader->setFloat("pointLights[1].constant", 1.0f);
  lightingShader->setFloat("pointLights[1].linear", 0.09f);
  lightingShader->setFloat("pointLights[1].quadratic", 0.032f);
  // point light 3
  lightingShader->setVec3("pointLights[2].position", pointLightPositions[2]);
  lightingShader->setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
  lightingShader->setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
  lightingShader->setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
  lightingShader->setFloat("pointLights[2].constant", 1.0f);
  lightingShader->setFloat("pointLights[2].linear", 0.09f);
  lightingShader->setFloat("pointLights[2].quadratic", 0.032f);
  // point light 4
  lightingShader->setVec3("pointLights[3].position", pointLightPositions[3]);
  lightingShader->setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
  lightingShader->setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
  lightingShader->setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
  lightingShader->setFloat("pointLights[3].constant", 1.0f);
  lightingShader->setFloat("pointLights[3].linear", 0.09f);
  lightingShader->setFloat("pointLights[3].quadratic", 0.032f);
  // spotLight
  lightingShader->setVec3("spotLight.position", camera.Position);
  lightingShader->setVec3("spotLight.direction", camera.Front);
  lightingShader->setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
  lightingShader->setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
  lightingShader->setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
  lightingShader->setFloat("spotLight.constant", 1.0f);
  lightingShader->setFloat("spotLight.linear", 0.09f);
  lightingShader->setFloat("spotLight.quadratic", 0.032f);
  lightingShader->setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
  lightingShader->setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));     

  // view/projection transformations
  glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)800 / (float)600, 0.1f, 100.0f);
  glm::mat4 view = camera.GetViewMatrix();
  lightingShader->setMat4("projection", projection);
  lightingShader->setMat4("view", view);

  // world transformation
  glm::mat4 model = glm::mat4(1.0f);
  lightingShader->setMat4("model", model);

  // bind diffuse map
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, diffuseMap);
  // bind specular map
  glActiveTexture(GL_TEXTURE1);
  glBindTexture(GL_TEXTURE_2D, specularMap);

  // render containers
  glBindVertexArray(cubeVAO);
  for (unsigned int i = 0; i < 10; i++)
  {
      // calculate the model matrix for each object and pass it to shader before drawing
      glm::mat4 model = glm::mat4(1.0f);
      model = glm::translate(model, cubePositions[i]);
      float angle = 20.0f * i;
      model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
      lightingShader->setMat4("model", model);

      glDrawArrays(GL_TRIANGLES, 0, 36);
  }

    // also draw the lamp object(s)
    lightCubeShader->use();
    lightCubeShader->setMat4("projection", projection);
    lightCubeShader->setMat4("view", view);

    // we now draw as many light bulbs as we have point lights.
    glBindVertexArray(lightCubeVAO);
    for (unsigned int i = 0; i < 4; i++)
    {
        model = glm::mat4(1.0f);
        model = glm::translate(model, pointLightPositions[i]);
        model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
        lightCubeShader->setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }

}

unsigned int MultipleLights::loadTexture(char const *path) {
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

void MultipleLights::proceessKeyEvent(int key) {

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
void MultipleLights::mouse_callback(double xposIn, double yposIn) {
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
void MultipleLights::scroll_callback(double xoffset, double yoffset) {
  camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
