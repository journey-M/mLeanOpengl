#ifndef __GRAPHIC_BASE__

#define __GRAPHIC_BASE__

#include "EventBase.h"
#include "../third-libs/tinygltf/tiny_gltf.h"
#include <iostream>

#include "Mesh.h"
#include "Material.h"
#include "Primitive.h"


namespace engin{



class GraphicBase{

    public:

    virtual bool create(int width, int height) = 0;

    virtual bool setEventCallback(EventBase* base) = 0;

    virtual int clearPreFrame() = 0;

    virtual int renderFrame() = 0;

    virtual bool release() = 0;

	virtual	void drawNode(tinygltf::Model &model, const tinygltf::Node &node) = 0;

	virtual	void DrawTest() = 0;


    virtual std::shared_ptr<std::vector<unsigned int>> buildBuffers(const tinygltf::Model &model) = 0;

    virtual std::shared_ptr<std::vector<unsigned int>> buildTextures(const tinygltf::Model &model) = 0;


};

}


#endif