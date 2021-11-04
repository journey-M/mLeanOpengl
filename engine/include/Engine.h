#ifndef __ENGINE__

#define __ENGINE__

#include "GraphicBase.h"
#include "Scene.h"
#include <vector>
#include <memory>

class Engine{

    public:
        static Engine* getInstance();

        void init();

        void release();

        Scene* createScene();


    private:
        static Engine *instance ;

        std::shared_ptr<GraphicBase> graphic;

        std::vector<Scene*> scenes;


        void createGraphics();

        void createSoundPlayer();

        static void startPolling(Engine* engine);

        Engine(){}

};


#endif