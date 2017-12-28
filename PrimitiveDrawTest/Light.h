//
// Created by Nando on 12/25/17.
//

#ifndef COMPUTERGRAPHICSBASEPROJECT_LIGHT_H
#define COMPUTERGRAPHICSBASEPROJECT_LIGHT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include "Shader.h"
#include "Camera.h"

class Light {

public:

	Light(unsigned int type, glm::vec3 initPos) :type(type), lightPos(initPos) {}

	void setDinamicPosition(float angle);
	glm::vec3 getDinamicPos() { return dinamicLightPos; }
	void render(Camera, unsigned int, unsigned int);
	void init();
	void init(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);

	const glm::vec3 &getAmbient() const;

	const glm::vec3 &getDiffuse() const;

	const glm::vec3 &getSpecular() const;

private:

	const unsigned int type; // 1, 2 3
	
	/*std::string vertex = "/Users/apple/code/ComputerGraphicsBaseProject/shaders/vertexLightSource.glsl";
	std::string fragment = "/Users/apple/code/ComputerGraphicsBaseProject/shaders/fragmentLightSource.glsl";*/

	std::string vertex = "vertexLightSource.glsl";
	std::string fragment = "fragmentLightSource.glsl";
	
	glm::vec3 lightPos = glm::vec3(3.0f, 1.0f, 3.0f);
	glm::vec3 dinamicLightPos;
	unsigned int programId;
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);
	unsigned int VAO, VBO;

	glm::vec3 ambient = glm::vec3(0.4f);
	glm::vec3 diffuse = glm::vec3(0.3f);
	glm::vec3 specular = glm::vec3(1.0f);

	float vertices[108] = {
		// RECTANGLE
		// positions        // texture coords  // normal vectors
		-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f,  0.5f, -0.5f,
		0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f, -0.5f,  0.5f,
		0.5f, -0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,

		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,

		0.5f,  0.5f,  0.5f,
		0.5f,  0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,

		-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f,  0.5f,
		0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f,  0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f,  0.5f, -0.5f,
		0.5f,  0.5f, -0.5f,
		0.5f,  0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f, -0.5f
	};
};


#endif //COMPUTERGRAPHICSBASEPROJECT_LIGHT_H
