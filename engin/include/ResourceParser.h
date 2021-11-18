#ifndef __ResourceParser_H__
#define __ResourceParser_H__

#include "GraphicBase.h"
#include <memory>
#include <string>
#include <vector>
#include "ShaderBase.h"

class Scene;

namespace engin {

class ResourceParser{
	private:
		std::shared_ptr<GraphicBase> graphic;
		
		std::vector<std::shared_ptr<Scene>> scene; 


	public:


		ResourceParser(std::shared_ptr<GraphicBase> graphic);


		bool parsModeleForScene(Scene *scene, std::string path);


};
}

#endif
