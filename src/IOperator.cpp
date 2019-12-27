#include "../include/IOperator.h"
#include "../include/Trigle.h"
#include "../include/Square.h"
#include "../include/LeanShader.h"
#include "../include/TestFileShader.h"


Single::Single(){
}

IOperator* Single::getOperator(){
		//currentOperator = new Trigle();
		// currentOperator = new Square();
		//  currentOperator = new LeanShader();
		 currentOperator = new TestFileShader();

		return currentOperator; 
}
