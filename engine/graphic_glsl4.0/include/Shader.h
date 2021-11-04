#ifndef __SHADER_H__
#define __SHADER_H__

#include "glad/glad.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "glm/glm.hpp"
#include "../../include/ShaderBase.h"


class Shader : public ShaderBase{

	private:
	 	void checkCompileErrors(unsigned int shader, std::string type);
		bool inited = false;
		const char* vertexPath; 
		const char* fragmentPaht;
		 
	public:
		unsigned int ID;

		Shader(const char* vertexPath,const char* fragmentPath);


		bool checkInit() override;
		void use() override;

		void setBool(const std::string &name , bool value) const;
		void setInt(const std::string &name, int value) const;
		void setFloat(const std::string &name ,float value) const;
		void setVec2(const std::string &name, const glm::vec2 &value) const;
		void setVec2(const std::string &name, float x, float y) const;
		void setVec3(const std::string &name, const glm::vec3 &value) const;
		void setVec3(const std::string &name, float x, float y, float z) const;
		void setVec4(const std::string &name, const glm::vec4 &value) const;
		void setVec4(const std::string &name, float x, float y, float z, float w) const;
		void setMat2(const std::string &name, const glm::mat2 &mat) const;
		void setMat3(const std::string &name, const glm::mat3 &mat) const;
		void setMat4(const std::string &name, const glm::mat4 &mat) const;

};


#endif