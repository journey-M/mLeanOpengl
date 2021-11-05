#ifndef __Sprite_BASE__

#define __Sprite_BASE__

#include <memory>
#include <string>

#include "GraphicBase.h"
#include "ObjectBase.h"
#include "../graphic_glsl4.0/include/Shader.h"
#include "../graphic_glsl4.0/include/GLObject.h"



class Sprite{

    public:

        Sprite(std::shared_ptr<GraphicBase> graphic, std::string name);

        Sprite(std::shared_ptr<GraphicBase> graphic, std::string vertixPath, std::string fragmentPath);

        void updateMyself();


    private:
    
        std::shared_ptr<GraphicBase> graphic;
        std::string name;

		std::shared_ptr<ShaderBase> shader;

        std::shared_ptr<ObjectBase> object;


};


#endif