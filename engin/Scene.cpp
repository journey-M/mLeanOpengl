
#include "include/Scene.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>

#include "third-libs/json11-master/json11.hpp"
#include "third-libs/tinygltf/tiny_gltf.h"



Scene::Scene(std::shared_ptr<GraphicBase> graphic){
	this->graphic = graphic;
}


void Scene::updateFrame(){

	auto sprite = spritePools.begin();
	while (sprite!= spritePools.end()) {
		sprite->get()->updateMyself();
		sprite++;
	}

}


bool Scene::loadAssest(std::string assestPath){

	// std::string vertexCode;
	// std::ifstream vShaderFile;
			
	// vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	// try{
	// 	vShaderFile.open(assestPath);
	// 	std::stringstream vShaderStream;
	// 	vShaderStream << vShaderFile.rdbuf();
	// 	vShaderFile.close();
	// 	vertexCode = vShaderStream.str();
	// }catch(std::ifstream::failure e){
	// 	std::cout << "ERROR:: load Assest :: FILE_NOT_SUCCESFULL_READ"<<std::endl;
	// }

	// std::string err;
	// auto resource = json11::Json::parse(vertexCode, err);

	// if (!err.empty()) {
	// 	std::cout << "ERROR:: load Assest :: parse error :" << err <<std::endl;
	// 	return false;
	// }

	// bool b = resource["asset"].is_object();


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


	std::cout << "ERROR:: is asset :" << ret <<std::endl;



	
	return true;
}


std::shared_ptr<Sprite> Scene::addSprite(std::string name){
	auto sprite = std::make_shared<Sprite>(graphic, name, "");
	spritePools.push_back(sprite);
}