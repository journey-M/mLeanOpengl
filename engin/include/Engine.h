#ifndef __ENGINE__

#define __ENGINE__

#include "GraphicBase.h"
#include "EventBase.h"
#include "ClockBase.h"
#include "Scene.h"
#include "ResourceParser.h"
#include <string>
#include <vector>
#include <memory>

namespace engin {


class Engine : public EventBase{

    public:
        static Engine* getInstance();

        void init();

        void release();

        Scene* createScene();

        Scene* createSceneFromAssest(std::string);

        void proceessKeyEvent(char key) override;

        void mouse_callback(double xoffset, double yoffset) override;

        void scroll_callback(double xoffset, double yoffset) override;


    private:
        static Engine *instance ;

        std::shared_ptr<GraphicBase> graphic;

        std::vector<Scene*> scenes;

        std::shared_ptr<ClockBase> clock;

        std::shared_ptr<ResourceParser> resParser;


        void createGraphics();

        void createSoundPlayer();

        static void startPolling(Engine* engine);

        Engine(){}

};


}
#endif