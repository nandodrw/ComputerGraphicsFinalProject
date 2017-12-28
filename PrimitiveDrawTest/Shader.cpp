//
// Created by Nando on 11/9/17.
//

#include "Shader.h"

void Shader::createProgram(unsigned int  &programID) {
	programID = glCreateProgram();
}

unsigned int Shader::attachShaderToProgram(GLenum shaderOpenGLId, const GLchar *shaderPath, unsigned int  programID) {
	std::string shaderCode;
	std::ifstream shaderFile;

	// ensure ifstreams can throw exceptions
	shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	std::stringstream shaderStream;

	try {
		// open files
		shaderFile.open(shaderPath);
		// read files buffers
		shaderStream << shaderFile.rdbuf();
		// close files
		shaderFile.close();
		// convert streams into strings
		shaderCode = shaderStream.str();
	}
	catch (std::ifstream::failure e) {
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
	}

	const char* charShaderCode = shaderCode.c_str();

	unsigned int shaderId;

	// helper variables
	int success;
	char infoLog[512];
	int InfoLogLength;

	// shaderId shader
	shaderId = glCreateShader(shaderOpenGLId);
	glShaderSource(shaderId, 1, &charShaderCode, NULL);
	glCompileShader(shaderId);
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(shaderId, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}

	// Return shader id for later deletion
	return shaderId;
}

void Shader::linkProgram(unsigned int shaders[], unsigned int  programID) {
	for (int i = 0; i < (sizeof(shaders) / sizeof(*shaders)); ++i) {
		glAttachShader(programID, shaders[i]);
	}

	int success;
	char infoLog[512];

	// Link program
	glLinkProgram(programID);

	// Print linking errors
	glGetProgramiv(programID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(programID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
}

void Shader::linkProgram(unsigned int vertex, unsigned int fragment, unsigned int  programID) {
	glAttachShader(programID, vertex);
	glAttachShader(programID, fragment);

	int success;
	char infoLog[512];

	// Link program
	glLinkProgram(programID);

	// Print linking errors
	glGetProgramiv(programID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(programID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}




void Shader::use(unsigned int programID) {
	glUseProgram(programID);
}

void Shader::setBool(const std::string &name, bool value, unsigned int  programID) const {
	glUniform1i(glGetUniformLocation(programID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value, unsigned int  programID) const {
	glUniform1i(glGetUniformLocation(programID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value, unsigned int  programID) const {
	glUniform1f(glGetUniformLocation(programID, name.c_str()), value);
}

void Shader::setVec4(const std::string &name, float value_x, float value_y, float value_z, float value_w, unsigned int  programID) {
	glUniform4f(glGetUniformLocation(programID, name.c_str()), value_x, value_y, value_z, value_w);
}

void Shader::setVec3(const std::string &name, float value_x, float value_y, float value_z, unsigned int  programID) {
	glUniform3f(glGetUniformLocation(programID, name.c_str()), value_x, value_y, value_z);
}

void Shader::setVec3(const std::string &name, glm::vec3 vec, unsigned int  programID) {
	glUniform3f(glGetUniformLocation(programID, name.c_str()), vec.x, vec.y, vec.z);
}

void Shader::setMat4(const std::string &name, float *value, unsigned int programID) {
	auto location = glGetUniformLocation(programID, name.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, value);
}
