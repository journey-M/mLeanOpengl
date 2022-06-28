#ifndef __COORDINATE_H_
#define __COORDINATE_H_

#include "./IOperator.h"
#include "./Shader.h"
#include "./glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "stb_image.h"
#include <GLFW/glfw3.h>

class Coordinate : public IOperator {
private:
  void init() override;
  void destroy() override;

  Shader *shader;
  unsigned int VAO;
  unsigned int VBO;
  unsigned int EBO;
  unsigned int texture1, texture2;

public:
  void render() override;

  void initShader();
  void initVertex();
  void initTexture();
};

#endif
