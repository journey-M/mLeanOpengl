#ifndef __GLObject_H__
#define __GLObject_H__

#include "glad/glad.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "glm/glm.hpp"
#include "../../include/ObjectBase.h"


class GLObject : public ObjectBase{

	private:
		bool inited = false;
		 
	public:

		GLObject();

        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;
        unsigned int texture;


		void drawObject() override  ;

		bool checkInit() override;


		void initVertex();

		void initTexture();




};


#endif
