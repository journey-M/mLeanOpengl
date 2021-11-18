#include <chrono>
#include <stdio.h>
#include <thread>

#include "../engin/include/Engine.h"

int main(int argc, char** argv){


    Engine *engine = Engine::getInstance();

    engine->init();


    std::this_thread::sleep_for(std::chrono::milliseconds(100));


    auto scene = engine->createSceneFromAssest("/home/gwj/workspaces/TowerDefends/logic/Assests/cube.gltf");

    // auto sprite = scene->addSprite("test");


    std::this_thread::sleep_for(std::chrono::seconds(50));

    return 0;
}