#include <iterator>
#include <memory>
#include <stdio.h>
#include <thread>

#include "include/GraphicBase.h"
#include "include/Engine.h"
#include "graphic_glsl4.0/include/GraphicGL40.h"
#include "include/Scene.h"


    Engine* Engine::instance = nullptr;

    Engine*  Engine::getInstance(){
        
        if (instance == nullptr) {
            instance = new Engine();
        }

        return instance;
    }


    void Engine::init(){

        printf("start init  engine! \n");
        createSoundPlayer();

        std::thread mainTh(&Engine::startPolling, this);
        mainTh.detach();

    }

    void Engine::startPolling(Engine* engine){
        engine->createGraphics();

        while (true) {

            engine->graphic->renderFrame();

            auto tmp = engine->scenes.begin();
            while (tmp != engine->scenes.end() ) {
                (*tmp) ->updateFrame();
                tmp++;
            }

            engine->graphic->renderFrame();
        }


        engine->graphic->release();
    }


    void  Engine::createGraphics(){
        graphic = std::make_shared<GraphicGL40>();
        graphic->create(800, 600);

    }


    Scene* Engine::createScene(){
        auto scene = new Scene(graphic);
        scenes.push_back(scene);
        return scene;
    }


    void  Engine::createSoundPlayer(){

    }
