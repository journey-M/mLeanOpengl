#ifndef __GRAPHIC_BASE__

#define __GRAPHIC_BASE__

class GraphicBase{

    public:

    virtual bool create(int width, int height) = 0;

    virtual int clearPreFrame() = 0;

    virtual int renderFrame() = 0;

    virtual bool release() = 0;

};


#endif