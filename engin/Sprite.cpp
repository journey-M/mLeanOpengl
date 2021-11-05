
#include "include/Sprite.h"
#include <algorithm>
#include <memory>
#include <stdio.h>
#include <string>


Sprite::Sprite(std::shared_ptr<GraphicBase> graphic, std::string name){
	this->graphic = graphic;
	this->name = name;

}

Sprite::Sprite(std::shared_ptr<GraphicBase> graphic, std::string vertixPath, std::string fragmentPath){
	this->graphic = graphic;
	this->object = std::make_shared<GLObject>();
	this->shader = std::make_shared<Shader>("/home/gwj/workspaces/TowerDefends/engin/res/texture.vs", "/home/gwj/workspaces/TowerDefends/engin/res/texture.fs");

}


void Sprite::updateMyself(){


	shader->checkInit();
	object->checkInit();

	shader->use();

	object->drawObject();

}

