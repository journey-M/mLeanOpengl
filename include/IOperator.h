#ifndef __OPREATOR_H__
#define __OPREATOR_H__

#include <functional>
#include <vector>

class IOperator {
private:
public:
  bool inited = false;
  virtual void init() { inited = true; };
  virtual void render(){};
  virtual void destroy(){};
  virtual void proceessKeyEvent(int key){};
  virtual void mouse_callback(double xoffset, double yoffset){};
  virtual void scroll_callback(double xoffset, double yoffset){};
};

class Single {
private:
  int currentIndex;
  IOperator *currentOperator;
  Single();

public:
  static Single instance;

  std::vector<std::function<IOperator *()>> creaters;
  IOperator *getOperator();
  IOperator *createOperator(int index);
  void gotoPre();
  void gotoNext();
};
#endif
