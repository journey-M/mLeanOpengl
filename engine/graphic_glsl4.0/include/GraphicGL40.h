#ifndef __GraphicGL40__

#define __GraphicGL40__


#include "../../include/GraphicBase.h"


#include "glad/glad.h"    
#include <GLFW/glfw3.h>



#include "Camera.h"


class GraphicGL40: public GraphicBase{

    public:
        bool create(int width, int height) override;


        int clearPreFrame() override;
        int renderFrame() override;

        bool release() override;


    private:
        
        GLFWwindow* window;

        void processInput(GLFWwindow* window);

        static void mouse_callback(GLFWwindow * window, double xoffset, double yoffset);

        static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

};

#endif 