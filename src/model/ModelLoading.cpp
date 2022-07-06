#include "../../include/model/ModelLoading.h"
#include <string>


void ModelLoading::init() {
  printf("init ModelLoading..");
  IOperator::init();

  initVertex();
  initShader();
  initModel();
  glEnable(GL_DEPTH_TEST);
}

void ModelLoading::destroy() {
  if (ourShader != NULL) {
    if (ourShader->vertixShader > 0) {
      glDeleteShader(ourShader->vertixShader);
    }
    if (ourShader->fragmentShader > 0) {
      glDeleteShader(ourShader->fragmentShader);
    }
    if (ourShader->ID > 0) {
      glDeleteProgram(ourShader->ID);
    }
  }

}

void ModelLoading::initShader() {
  ourShader = new Shader(
      std::string(baseDir).append("res/modelshader/1.model_loading.vs").c_str(),
      std::string(baseDir).append("res/modelshader/1.model_loading.fs").c_str());

}

void ModelLoading::initModel(){
  // load models
  ourModel = new Model(std::string(baseDir).append(("res/objects/nanosuit/nanosuit.obj")).c_str());

}

void ModelLoading::initVertex() {

}

void ModelLoading::render() {

  float currentFrame = static_cast<float>(glfwGetTime());
  deltaTime = currentFrame - lastFrame;
  lastFrame = currentFrame;

  // clear the depth buffer noew !
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // don't forget to enable shader before setting uniforms
  ourShader->use();

  // view/projection transformations
  glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)800 / (float)600, 0.1f, 100.0f);
  glm::mat4 view = camera.GetViewMatrix();
  ourShader->setMat4("projection", projection);
  ourShader->setMat4("view", view);

  // render the loaded model
  glm::mat4 model = glm::mat4(1.0f);
  model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
  model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
  ourShader->setMat4("model", model);
  ourModel->Draw(ourShader);

}

void ModelLoading::proceessKeyEvent(int key) {

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
void ModelLoading::mouse_callback(double xposIn, double yposIn) {
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
void ModelLoading::scroll_callback(double xoffset, double yoffset) {
  camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
