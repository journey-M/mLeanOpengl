
#include "../include/IOperator.h"
#include "../include/Camera_01.h"
#include "../include/Camera_mouse.h"
#include "../include/Camera_move.h"
#include "../include/Coordinate.h"
#include "../include/CoordinateCube.h"
#include "../include/CoordinateCubes_More.h"
#include "../include/L_Color1.h"
#include "../include/LeanShader.h"
#include "../include/Square.h"
#include "../include/TestFileShader.h"
#include "../include/Texture.h"
#include "../include/Texture2.h"
#include "../include/Transformations.h"
#include "../include/Trigle.h"

Single::Single() {
  creaters.push_back([]() -> IOperator * { return new Trigle(); });
  creaters.push_back([]() -> IOperator * { return new Square();});
  creaters.push_back([]() -> IOperator * { return new LeanShader(); });
  creaters.push_back([]() -> IOperator * { return new TestFileShader(); });
  creaters.push_back([]() -> IOperator * { return new Texture(); });
  creaters.push_back([]() -> IOperator * { return new Texture2(); });
  creaters.push_back([]() -> IOperator * { return new Transformation(); });
  creaters.push_back([]() -> IOperator * { return new Coordinate(); });
  creaters.push_back([]() -> IOperator * { return new CoordinateCube(); });
  creaters.push_back([]() -> IOperator * { return new CoordinateCubeMore(); });
  creaters.push_back([]() -> IOperator * { return new Camera01(); });
  creaters.push_back([]() -> IOperator * { return new CameraMove(); });
  creaters.push_back([]() -> IOperator * { return new CameraMouse(); });
  creaters.push_back([]() -> IOperator * { return new LColor1(); });

  currentOperator = creaters[0]();
  currentIndex = 0;
}
void Single::gotoPre() {
  currentIndex--;
  createOperator(currentIndex);
}
void Single::gotoNext() {
  currentIndex++;
  createOperator(currentIndex);
}
IOperator *Single::createOperator(int index) {
  if (currentOperator != NULL) {
 //   currentOperator->destroy();
    delete (currentOperator);
    currentOperator = NULL;
  }
  if(index<0){
    index = 0;
  }else if(index >= creaters.size()){
    index = creaters.size() -1;
  }
  std::function<IOperator*()> toCallfunc = creaters[index];
  currentOperator = toCallfunc();

  return currentOperator;
}

IOperator *Single::getOperator() {
  if (!currentOperator->inited) {
    currentOperator->init();
  }
  return currentOperator;
}
