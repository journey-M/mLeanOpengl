#ifndef __ObjectBase__

#define __ObjectBase__

#include <memory>
#include <string>

#include "GraphicBase.h"

class ObjectBase{

    public:

        virtual bool checkInit() = 0;

        virtual void drawObject() = 0;

};


#endif