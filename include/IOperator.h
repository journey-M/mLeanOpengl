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
		static Single * instance;	
		IOperator* currentOperator;
		Single();
		
	public:
		IOperator* getOperator();
		static Single* getInstance(){
			if(instance == nullptr){
				instance = new Single();
			}
			return instance;
		}
};


#endif
