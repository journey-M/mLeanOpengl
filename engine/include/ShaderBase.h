#ifndef __ShaderBase__

#define __ShaderBase__

#include <memory>
#include <string>

#include "GraphicBase.h"

class ShaderBase{

    public:


    virtual bool checkInit() = 0;


    virtual void use() = 0;
};


#endif