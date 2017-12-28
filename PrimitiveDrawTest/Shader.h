//
// Created by Nando on 11/9/17.
//

#ifndef COMPUTERGRAPH_1_SHADER_H
#define COMPUTERGRAPH_1_SHADER_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>

class Shader {

public:

	static Shader& instance()
	{
		static Shader *instance = new Shader();
		return *instance;
	}


	Shader() {};

	// Create program, load shaders and program utils
	void createProgram(unsigned int  &programID);
	unsigned int attachShaderToProgram(GLenum shaderId, const GLchar *shaderPath, unsigned int  programID);
	void linkProgram(unsigned int shaders[], unsigned int  programID);
	void linkProgram(unsigned int vertex, unsigned int fragment, unsigned int  programID);
	void use(unsigned int programID);

	// Uniform loading
	void setBool(const std::string &name, bool value, unsigned int  programID) const;
	void setInt(const std::string &name, int value, unsigned int  programID) const;
	void setFloat(const std::string &name, float value, unsigned int  programID) const;
	void setVec4(const std::string &name, float value_x, float value_y, float value_z, float value_w, unsigned int  programID);
	void setVec3(const std::string &name, float value_x, float value_y, float value_z, unsigned int  programID);
	void setVec3(const std::string &name, glm::vec3 vec, unsigned int  programID);
	void setMat4(const std::string &name, float *value, unsigned int  programID);
};


#endif //COMPUTERGRAPH_1_SHADER_H
