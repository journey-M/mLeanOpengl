#ifndef __Scene_H__
#define __Scene_H__

#include "GraphicBase.h"
#include <memory>
#include <string>
#include <vector>
#include "Sprite.h"
#include "ShaderBase.h"

class Scene{
	private:
		std::shared_ptr<GraphicBase> graphic;
		
		std::vector<std::shared_ptr<Sprite>> spritePools; 


	public:


		Scene(std::shared_ptr<GraphicBase> graphic);


		Scene(std::shared_ptr<GraphicBase> graphic, std::string vertixPath, std::string fragmentPath);



	 	void updateFrame();	


		std::shared_ptr<Sprite> addSprite(std::string name);

};

#endif
