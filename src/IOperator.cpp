#include "../include/IOperator.h"
#include "../include/Trigle.h"
#include "../include/Square.h"
#include "../include/LeanShader.h"
#include "../include/TestFileShader.h"
#include "../include/Texture.h"
#include "../include/Texture2.h"
#include "../include/Transformations.h"
#include "../include/Coordinate.h"
#include "../include/CoordinateCube.h"
#include "../include/CoordinateCubes_More.h"
#include "../include/Camera_01.h"
#include "../include/Camera_move.h"
#include "../include/Camera_mouse.h"
#include "../include/L_Color1.h"


Single::Single(){
}

IOperator* Single::getOperator(){

		if (!currentOperator)
		{
			// currentOperator = new Trigle();
			// currentOperator = new Square();
			// currentOperator = new LeanShader();
			// currentOperator = new TestFileShader();
			// currentOperator = new Texture();
			// currentOperator = new Texture2();
			// currentOperator = new Transformation();
			// currentOperator = new Coordinate();
			// currentOperator = new CoordinateCube();
			// currentOperator = new CoordinateCubeMore();
			// currentOperator = new Camera01();
			currentOperator= new CameraMove();
			//currentOperator= new LColor1();
		}
		return currentOperator; 
}
