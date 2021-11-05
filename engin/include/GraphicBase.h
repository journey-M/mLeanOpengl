#ifndef __GRAPHIC_BASE__

#define __GRAPHIC_BASE__

#include "EventBase.h"

class GraphicBase{

    public:

    virtual bool create(int width, int height) = 0;

    virtual bool setEventCallback(EventBase* base) = 0;

    virtual int clearPreFrame() = 0;

    virtual int renderFrame() = 0;

    virtual bool release() = 0;

};


#endif