#ifndef __EventBase__

#define __EventBase__

#include <memory>
#include <string>


class EventBase{

    public:

        virtual void proceessKeyEvent(char key) = 0;

        virtual void mouse_callback(double xoffset, double yoffset) = 0;

        virtual void scroll_callback(double xoffset, double yoffset) = 0;

};


#endif