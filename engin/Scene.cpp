#include "include/Scene.h"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>
#include <string>

#include "graphic_glsl4.0/include/GLNode.h"
#include "graphic_glsl4.0/include/glm/glm.hpp"

#include "third-libs/json11-master/json11.hpp"
#include "third-libs/tinygltf/tiny_gltf.h"



Scene::Scene(std::shared_ptr<GraphicBase> graphic,std::shared_ptr<ResourceParser> resParser){
	this->graphic = graphic;
	this->resParser = resParser;

}


void Scene::drawTraversal(){

	// auto sprite = spritePools.begin();
	// while (sprite!= spritePools.end()) {
	// 	sprite->get()->updateMyself();
	// 	sprite++;
	// }


	auto sprite = basicNodes.begin();
	while (sprite!= basicNodes.end()) {
		sprite->get()->drawObject();
		sprite++;
	}

	// graphic->DrawTest();


}


void Scene::addNode(std::shared_ptr<Node> node){

	basicNodes.push_back(node);
}

void Scene::traverse(
    const std::function<void(std::shared_ptr<Node> node)> &callback) {
  for (auto &node : nodes_) {
    traverseInternal(node, callback);
  }
}

void Scene::traverseInternal(
    const std::shared_ptr<Node> &node,
    const std::function<void(std::shared_ptr<Node>)> &nodeProcessor) {
  nodeProcessor(node);
  auto &children = node->getChildren();
  for (auto &child : children) {
    traverseInternal(child, nodeProcessor);
  }
}


bool Scene::loadAssest(std::string assestPath){

	using namespace tinygltf;
	Model model;
	TinyGLTF loader;
	std::string err;
	std::string warn;
	bool ret = loader.LoadASCIIFromFile(&model, &err, &warn, assestPath);

	if (!warn.empty()) {
		printf("Warn: %s\n", warn.c_str());
	}

	if (!err.empty()) {
		printf("Err: %s\n", err.c_str());
	}

	if (!ret) {
		printf("Failed to parse glTF\n");
		return -1;
	}

	if (model.scenes.size() <= 0 || model.defaultScene < 0) {
		return false;
	}

	//构建缓存和场景
	vboIds = graphic->buildBuffers(model);
	textureIds =  graphic->buildTextures(model);

	//创建默认场景
	gltfModel = model;
	gltfScene = model.scenes[model.defaultScene];
	for (auto i = 0; i < gltfScene.nodes.size(); ++i) {
		addNode(
			buildNode(model, gltfScene.nodes[i], vboIds, textureIds));
	}

	return true;
}



std::shared_ptr<Node> Scene::buildNode(const tinygltf::Model &model, unsigned int nodeIndex,
                  const std::shared_ptr<std::vector<unsigned int>> &buffers,
                  const std::shared_ptr<std::vector<unsigned int>> &textures,
                  std::shared_ptr<Node> parent){
	auto node = std::make_shared<GLNode>();

	// using namespace tinygltf;
	// for (int i =0 ; i< gltfScene.nodes.size() ; i++) {
	// 	tinygltf::Node tfnode = gltfModel.nodes[gltfScene.nodes[i]];
	// 	if (tfnode.mesh> -1) {
	// 		node->setMeshData(gltfModel, gltfModel.meshes[tfnode.mesh]);
	// 	}
	// }
	// basicNodes.push_back(node);



	auto nodeMatrix = model.nodes[nodeIndex].matrix;
	glm::mat4 matrix(1.0f);
	if (nodeMatrix.size() == 16) {
		matrix[0].x = nodeMatrix[0], matrix[0].y = nodeMatrix[1],
		matrix[0].z = nodeMatrix[2], matrix[0].w = nodeMatrix[3];
		matrix[1].x = nodeMatrix[4], matrix[1].y = nodeMatrix[5],
		matrix[1].z = nodeMatrix[6], matrix[1].w = nodeMatrix[7];
		matrix[2].x = nodeMatrix[8], matrix[2].y = nodeMatrix[9],
		matrix[2].z = nodeMatrix[10], matrix[2].w = nodeMatrix[11];
		matrix[3].x = nodeMatrix[12], matrix[3].y = nodeMatrix[13],
		matrix[3].z = nodeMatrix[14], matrix[3].w = nodeMatrix[15];
	} else {
		if (model.nodes[nodeIndex].translation.size() == 3) {
		glm::translate(matrix, glm::vec3(model.nodes[nodeIndex].translation[0],
										model.nodes[nodeIndex].translation[1],
										model.nodes[nodeIndex].translation[2]));
		}
		if (model.nodes[nodeIndex].rotation.size() == 4) {
		matrix *= glm::mat4_cast(glm::quat(model.nodes[nodeIndex].rotation[3],
											model.nodes[nodeIndex].rotation[0],
											model.nodes[nodeIndex].rotation[1],
											model.nodes[nodeIndex].rotation[2]));
		}
		if (model.nodes[nodeIndex].scale.size() == 3) {
		glm::scale(matrix, glm::vec3(model.nodes[nodeIndex].scale[0],
									model.nodes[nodeIndex].scale[1],
									model.nodes[nodeIndex].scale[2]));
		}
	}
	node->setMatrix(matrix);
	if (model.nodes[nodeIndex].mesh >= 0) {
		node->setMesh(
			buildMesh(model, model.nodes[nodeIndex].mesh, buffers, textures));
	}
	for (auto &childNodeIndex : model.nodes[nodeIndex].children) {
		node->addChild(buildNode(model, childNodeIndex, buffers, textures, node));
	}

	return node;
}
