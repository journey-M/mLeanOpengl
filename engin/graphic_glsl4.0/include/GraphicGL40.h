#ifndef __GraphicGL40__

#define __GraphicGL40__


#include "glad/glad.h"    
#include <GLFW/glfw3.h>

#include "../../include/GraphicBase.h"

#include "../../include/EventBase.h"
#include "../../include/Common.h"


namespace engin {
class GraphicGL40: public GraphicBase{

    public:
        bool create(int width, int height) override;

        bool setEventCallback(EventBase* base) override;

        int clearPreFrame() override;
        int renderFrame() override;

        bool release() override;

	    void drawNode(tinygltf::Model &model, const tinygltf::Node &node) override;

        void DrawMesh(tinygltf::Model &model, const tinygltf::Mesh &mesh);

        std::shared_ptr<std::vector<unsigned int>> buildBuffers(const tinygltf::Model &model) override;

        std::shared_ptr<std::vector<unsigned int>> buildTextures(const tinygltf::Model &model) override;


        std::shared_ptr<Material> buildMaterial(const tinygltf::Model &model, unsigned int materialIndex,
						const std::shared_ptr<std::vector<GLuint>> &textures) ;


	    std::shared_ptr<Primitive> buildPrimitive(const tinygltf::Model &model, unsigned int meshIndex,
						unsigned int primitiveIndex,
						const std::shared_ptr<std::vector<GLuint>> &vaos,
						const std::shared_ptr<std::vector<GLuint>> &buffers,
						const std::shared_ptr<std::vector<GLuint>> &textures);


        void DrawTest() override;


    private:
        
        GLFWwindow* window;

        static EventBase * eventBase;

        void processInput(GLFWwindow* window);

        static void mouse_callback(GLFWwindow * window, double xoffset, double yoffset);

        static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

};

}

#endif 