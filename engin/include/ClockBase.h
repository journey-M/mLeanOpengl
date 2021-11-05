#ifndef __ClockBase__

#define __ClockBase__

#include <cstdlib>
#include <memory>
#include <string>
#include <chrono>

/**

 时钟设计 ，记录当前的时钟， 和未来的时钟，阻塞方法
*/

class ClockBase{

    public:

        ClockBase();

        bool waitForNextEvent();

        long getCurrentFrame();

        void startRend();
        void afterRend();


    private:

        std::chrono::system_clock::time_point startTime ;
        std::chrono::system_clock::time_point lastStartRendTime ;
        std::chrono::system_clock::time_point lastEndRendTime ;
        long frameIndex = 0;
        //两帧之间的间隔
        const int timeInterval = 100;

        




};


#endif