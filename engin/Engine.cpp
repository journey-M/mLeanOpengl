#include <iostream>
#include <iterator>
#include <memory>
#include <stdio.h>
#include <thread>

#include "graphic_glsl4.0/include/GraphicGL40.h"
#include "include/GraphicBase.h"
#include "include/Engine.h"
#include "include/ResourceParser.h"
#include "include/Scene.h"


namespace engin {

    Engine* Engine::instance = nullptr;

    Engine*  Engine::getInstance(){
        
        if (instance == nullptr) {
            instance = new Engine();
        }

        return instance;
    }


    void Engine::init(){

        std::cout<<"start init  engine! \n"<< std::endl;
        std::thread mainTh(&Engine::startPolling, this);
        mainTh.detach();

    }

    void Engine::startPolling(Engine* engine){
        engine->clock = std::make_shared<ClockBase>();
        engine->createSoundPlayer();
        engine->createGraphics();
        engine->resParser = std::make_shared<ResourceParser>(engine->graphic);

        while (engine->clock->waitForNextEvent()) {
            engine->clock->startRend();
            engine->graphic->clearPreFrame();
            auto tmp = engine->scenes.begin();
            while (tmp != engine->scenes.end() ) {
                (*tmp) ->drawTraversal();
                tmp++;
            }
            engine->graphic->renderFrame();
            engine->clock->afterRend();
        }
        engine->graphic->release();
    }


    void  Engine::createGraphics(){
        graphic = std::make_shared<GraphicGL40>();
        graphic->create(800, 600);
        graphic->setEventCallback((EventBase*)this);

    }

    void Engine::proceessKeyEvent(char key){
        std::cout<<"event key  " << key <<std::endl;
    }

    void Engine::mouse_callback(double xoffset, double yoffset) {
        // std::cout<<"event mouse_callback  "<<std::endl;
    }

    void Engine::scroll_callback(double xoffset, double yoffset) {
        std::cout<<"event scroll_callback  "<<std::endl;
    }


    Scene* Engine::createScene(){
        auto scene = new Scene(graphic, resParser);
        scenes.push_back(scene);
        return scene;
    }

    Scene* Engine::createSceneFromAssest(std::string assestPath){
        auto scene = createScene();
        scene->loadAssest(assestPath);
        return scene;
    }



    void  Engine::createSoundPlayer(){

    }

}