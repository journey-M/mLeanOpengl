#ifndef __OPREATOR_H__
#define __OPREATOR_H__

class IOperator{
	private:
	
	public:
		virtual void init(){
		};
		virtual void render(){
		};
		virtual void proceessKeyEvent(int key ){
		};
		virtual void proceessMouseEvent(){

		};
};

class Single{
	private :
		IOperator* currentOperator;
		Single();
	public:
		static Single instance;	
		IOperator* getOperator();
};
#endif
