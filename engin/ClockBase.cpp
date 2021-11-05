
#include "include/ClockBase.h"
#include <iostream>
#include <memory>
#include <string>
#include <chrono>
#include <thread>

ClockBase::ClockBase(){
	startTime = std::chrono::system_clock::now();
}


bool ClockBase::waitForNextEvent(){
	std::this_thread::sleep_for(std::chrono::milliseconds(timeInterval));
	return true;
}


long ClockBase::getCurrentFrame(){
	return frameIndex;
}


void ClockBase::startRend(){
	frameIndex++;
	lastStartRendTime = std::chrono::system_clock::now();
}

void ClockBase::afterRend(){
	lastEndRendTime = std::chrono::system_clock::now();
	std::cout<< "渲染帧时间: " << (lastEndRendTime - lastStartRendTime ).count() /1000 <<std::endl;
}