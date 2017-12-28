//
// Created by Nando on 12/25/17.
//

#include "Light.h"

void Light::setDinamicPosition(float angle) {
	if (type == 1) {
		dinamicLightPos = glm::vec3(sin(angle) * lightPos.x, lightPos.y, cos(angle) * lightPos.z);
	}
	else if (type == 2) {
		dinamicLightPos = glm::vec3(lightPos.x, sin(angle) * lightPos.y, cos(angle) * lightPos.z);
	}
	else if (type == 3) {
		dinamicLightPos = glm::vec3(lightPos.x * sin(angle), cos(angle) * lightPos.y, cos(angle) * lightPos.z);
	}
}

void Light::init() {
	Shader::instance().createProgram(programId);

	unsigned int vertexId = Shader::instance().attachShaderToProgram(GL_VERTEX_SHADER, vertex.c_str(), programId);
	unsigned int fragmentId = Shader::instance().attachShaderToProgram(GL_FRAGMENT_SHADER, fragment.c_str(), programId);
	unsigned int shaders[2] = { vertexId, fragmentId };

	Shader::instance().linkProgram(shaders, programId);

	unsigned int virtualVao = 1;
	unsigned int virtualVbo = 2;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);


	//glGenVertexArrays(1, &virtualVao);
	//glGenBuffers(1, &virtualVbo);

	//VAO = virtualVao;
	//VBO = virtualVbo;

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Light::init(glm::vec3 amb, glm::vec3 diff, glm::vec3 spec) {

	ambient = amb;
	diffuse = diff;
	specular = spec;

	Shader::instance().createProgram(programId);

	unsigned int vertexId = Shader::instance().attachShaderToProgram(GL_VERTEX_SHADER, vertex.c_str(), programId);
	unsigned int fragmentId = Shader::instance().attachShaderToProgram(GL_FRAGMENT_SHADER, fragment.c_str(), programId);
	unsigned int shaders[2] = { vertexId, fragmentId };

	Shader::instance().linkProgram(shaders, programId);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Light::render(Camera camera, unsigned int screenWidth, unsigned int screenHeight) {
	Shader::instance().use(programId);

	glBindVertexArray(VAO);

	projection = glm::perspective(glm::radians(camera.getFov()), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
	Shader::instance().setMat4("projection", glm::value_ptr(projection), programId);
	view = glm::lookAt(camera.getCameraPos(), camera.getCameraPos() + camera.getCameraFront(), camera.getReferenceVector());
	Shader::instance().setMat4("view", glm::value_ptr(view), programId);
	model = glm::mat4(1.0f);
	model = glm::translate(model, dinamicLightPos);
	model = glm::scale(model, glm::vec3(0.2f));
	Shader::instance().setMat4("model", glm::value_ptr(model), programId);

	glDrawArrays(GL_TRIANGLES, 0, 36);

}

const glm::vec3 &Light::getAmbient() const {
	return ambient;
}

const glm::vec3 &Light::getDiffuse() const {
	return diffuse;
}

const glm::vec3 &Light::getSpecular() const {
	return specular;
}
