
#include "include/Scene.h"
#include <algorithm>
#include <memory>
#include <string>


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

std::shared_ptr<Sprite> Scene::addSprite(std::string name){
	auto sprite = std::make_shared<Sprite>(graphic, name, "");
	spritePools.push_back(sprite);
}