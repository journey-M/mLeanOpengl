#include "include/engine.h"
#include "include/GraphicBase.h"
#include <memory>
#include <string>
#include <vector>
#include "include/ShaderBase.h"
#include "include/Scene.h"
#include "include/ResourceParser.h"

#include "third-libs/tinygltf/tiny_gltf.h"


ResourceParser::ResourceParser( std::shared_ptr<GraphicBase> graphic){
	this->graphic = graphic;
}


bool ResourceParser::parsModeleForScene(Scene *scene , std::string path){

	using namespace tinygltf;
	Model model;
	TinyGLTF loader;
	std::string err;
	std::string warn;
	bool ret = loader.LoadASCIIFromFile(&model, &err, &warn, path);

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

	scene->gltfModel = model;
	scene ->gltfScene = model.scenes[model.defaultScene];

	return true;	
}
