#ifndef __TRAGLE_H__
#define __TRAGLE_H__

#include "./IOperator.h"

class Trigle : public IOperator {
private:

  const char *vertexShaderSource =
      "#version 330 core\n"
      "layout (location = 0) in vec3 aPos;\n"
      "void main()\n"
      "{\n"
      "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
      "}\0";
  const char *fragmentShaderSource =
      "#version 330 core\n"
      "out vec4 FragColor;\n"
      "void main()\n"
      "{\n"
      "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
      "}\n\0";
  unsigned int shaderProgram;
  unsigned int VAO;
  unsigned int VBO;
	unsigned int vertexShader;
	unsigned int fragmentShader;


public:
  void init() override;
  void destroy() override;
  void render() override;

  void initShader();
  void initVertex();
};

#endif
