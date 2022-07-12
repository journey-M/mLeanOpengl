
#include "../include/IOperator.h"
#include "../include/Camera_01.h"
#include "../include/Camera_mouse.h"
#include "../include/Camera_move.h"
#include "../include/Coordinate.h"
#include "../include/CoordinateCube.h"
#include "../include/CoordinateCubes_More.h"
#include "../include/LeanShader.h"
#include "../include/Square.h"
#include "../include/TestFileShader.h"
#include "../include/Texture.h"
#include "../include/Texture2.h"
#include "../include/Transformations.h"
#include "../include/Trigle.h"
#include "../include/lights/L_Color1.h"
#include "../include/lights/BasicLightingSpecular.h"
#include "../include/lights/Materials.h"
#include "../include/lights/LightingMapsSpecular.h"
#include "../include/lights/LightCastersDirectional.h"
#include "../include/lights/LightCastersPoint.h"
#include "../include/lights/LightCastersSpot.h"
#include "../include/lights/LightCastersSpotSoft.h"
#include "../include/lights/MultipleLights.h"
#include "../include/model/ModelLoading.h"
#include "../include/advancegl/DepthTest.h"
#include "../include/advancegl/StencilTest.h"
#include "../include/advancegl/BlendingDiscard.h"
#include "../include/advancegl/BlendingSorted.h"
#include "../include/advancegl/FrameBufferTest.h"






#include <cstdio>

Single::Single():currentIndex(0) {
  creaters.push_back([]() -> IOperator * { return new Trigle(); });
  creaters.push_back([]() -> IOperator * { return new Square();});
  creaters.push_back([]() -> IOperator * { return new LeanShader(); });
  creaters.push_back([]() -> IOperator * { return new TestFileShader(); });
  creaters.push_back([]() -> IOperator * { return new TextureScene(); });
  creaters.push_back([]() -> IOperator * { return new Texture2(); });
  creaters.push_back([]() -> IOperator * { return new Transformation(); });
  creaters.push_back([]() -> IOperator * { return new Coordinate(); });
  creaters.push_back([]() -> IOperator * { return new CoordinateCube(); });
  creaters.push_back([]() -> IOperator * { return new CoordinateCubeMore(); });
  creaters.push_back([]() -> IOperator * { return new Camera01(); });
  creaters.push_back([]() -> IOperator * { return new CameraMove(); });
  creaters.push_back([]() -> IOperator * { return new CameraMouse(); });

  //light
  creaters.push_back([]() -> IOperator * { return new LColor1(); });
  creaters.push_back([]() -> IOperator * { return new BasicLightingSpecular(); });
  creaters.push_back([]() -> IOperator * { return new Material(); });
  creaters.push_back([]() -> IOperator * { return new LightingMapsSpecular(); });
  creaters.push_back([]() -> IOperator * { return new LightCastersDirectional(); });
  creaters.push_back([]() -> IOperator * { return new LightCastersPoint(); });
  creaters.push_back([]() -> IOperator * { return new LightCastersSpot(); });
  creaters.push_back([]() -> IOperator * { return new LightCastersSpotSoft(); });
  creaters.push_back([]() -> IOperator * { return new MultipleLights(); });
  creaters.push_back([]() -> IOperator * { return new ModelLoading(); });
  creaters.push_back([]() -> IOperator * { return new DepthTest(); });
  creaters.push_back([]() -> IOperator * { return new StencilTest(); });
  creaters.push_back([]() -> IOperator * { return new BlendingDiscard(); });
  creaters.push_back([]() -> IOperator * { return new BlendingSorted(); });
  creaters.push_back([]() -> IOperator * { return new FrameBufferTest(); });





  //设置为最后一个
  currentIndex = creaters.size() -1;
  currentOperator = creaters[currentIndex]();
  lastIndex = currentIndex;
}
void Single::gotoPre() {
  currentIndex--;
  if( currentIndex<0){
    currentIndex = 0;
  }else if(currentIndex >= creaters.size()){
    currentIndex = creaters.size() -1;
  }
  currentOperator = createOperator(currentIndex);
}
void Single::gotoNext() {
  currentIndex++;
  if( currentIndex<0){
    currentIndex = 0;
  }else if(currentIndex >= creaters.size()){
    currentIndex = creaters.size() -1;
  }
  currentOperator = createOperator(currentIndex);
}
IOperator *Single::createOperator(int index) {
  if(index == lastIndex){
    return currentOperator;
  }
  if (currentOperator != NULL) {
    currentOperator->destroy();
    delete currentOperator;
    currentOperator = NULL;
  }
  printf("CURRENT INDEX CREATE: %d \n", index);
  std::function<IOperator*()> toCallfunc = creaters[index];
  lastIndex = index;
  return toCallfunc();
}

IOperator *Single::getOperator() {
  if (!currentOperator->inited) {
    currentOperator->init();
  }
  return currentOperator;
}
