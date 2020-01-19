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
		virtual void mouse_callback(double xoffset, double yoffset){

		};

		virtual void scroll_callback(double xoffset, double yoffset){

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
