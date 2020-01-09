#include "../include/IOperator.h"
#include "../include/Trigle.h"
#include "../include/Square.h"
#include "../include/LeanShader.h"
#include "../include/TestFileShader.h"
#include "../include/Texture.h"
#include "../include/Texture2.h"
#include "../include/Transformations.h"
#include "../include/Coordinate.h"


Single::Single(){
}

IOperator* Single::getOperator(){
		//currentOperator = new Trigle();
		// currentOperator = new Square();
		//  currentOperator = new LeanShader();
		//  currentOperator = new TestFileShader();
		//  currentOperator = new Texture();
		// currentOperator = new Texture2();
		// currentOperator = new Transformation();
		 currentOperator = new Coordinate();

		return currentOperator; 
}
