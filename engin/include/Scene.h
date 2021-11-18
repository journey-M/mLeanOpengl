#ifndef __Scene_H__
#define __Scene_H__

#include "GraphicBase.h"
#include <memory>
#include <string>
#include <vector>
#include "ShaderBase.h"
#include "ResourceParser.h"
#include "../third-libs/tinygltf/tiny_gltf.h"
#include "Node.h"

namespace engin {


class Scene{
	private:
		std::shared_ptr<GraphicBase> graphic;
		
		// std::vector<std::shared_ptr<Sprite>> spritePools; 

		std::vector<std::shared_ptr<Node>> basicNodes;

		std::shared_ptr<ResourceParser> resParser;

		std::shared_ptr<std::vector<unsigned int>> vboIds;
		std::shared_ptr<std::vector<unsigned int>> textureIds;

		void traverseInternal(
			const std::shared_ptr<Node> &node,
			const std::function<void(std::shared_ptr<Node> node)> &nodeProcessor);
		std::vector<std::shared_ptr<Node>> nodes_;

	public:

		tinygltf::Model gltfModel;
		tinygltf::Scene gltfScene; 

		Scene(std::shared_ptr<GraphicBase> graphic, std::shared_ptr<ResourceParser> resParser);

		Scene(std::shared_ptr<GraphicBase> graphic, std::string vertixPath, std::string fragmentPath);

		bool loadAssest(std::string assestPath);


	 	void drawTraversal();	

		void traverse(const std::function<void(std::shared_ptr<Node> node)> &nodeProcessor);

		void addNode(std::shared_ptr<Node> node);


		std::shared_ptr<Node> buildNode(const tinygltf::Model &model, unsigned int nodeIndex,
                  const std::shared_ptr<std::vector<unsigned int>> &buffers,
                  const std::shared_ptr<std::vector<unsigned int>> &textures,
                  std::shared_ptr<Node> parent);

};

}
#endif
