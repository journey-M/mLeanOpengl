#ifndef __NODEBase__

#define __NODEBase__

#include <memory>
#include <string>

#include "GraphicBase.h"
#include "Mesh.h"
#include "../third-libs/tinygltf/tiny_gltf.h"
#include "../third-libs/glm/glm.hpp"

namespace engin {
class Node{

public:
  Node(std::shared_ptr<Node> parent = nullptr);
  void setMatrix(const glm::mat4 &mat);
  const glm::mat4 &getMatrix();
  glm::mat4 getWorldMatrix();
  void addChild(const std::shared_ptr<Node> &node);
  void setMesh(std::shared_ptr<Mesh> mesh);
  const std::vector<std::shared_ptr<Node>> &getChildren();
  void draw();

private:
  std::vector<std::shared_ptr<Node>> children_;
  std::shared_ptr<Node> parent_;
  glm::mat4 matrix_;
  std::shared_ptr<Mesh> mesh_;

};

}

#endif