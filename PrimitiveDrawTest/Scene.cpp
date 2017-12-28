//
// Created by Nando on 12/25/17.
//

#include "Scene.h"


void Scene::render(Light light[], int numLights, Camera camera, unsigned int screenWidth, unsigned int screenHeight) {
	bindBuffers();
	bindModel(light, numLights, camera, screenWidth, screenHeight);
}

void Scene::init() {
	Shader::instance().createProgram(programId);

	unsigned int vertexId = Shader::instance().attachShaderToProgram(GL_VERTEX_SHADER, vertex.c_str(), programId);
	unsigned int fragmentId = Shader::instance().attachShaderToProgram(GL_FRAGMENT_SHADER, fragment.c_str(), programId);
	unsigned int shaders[2] = { vertexId, fragmentId };

	Shader::instance().linkProgram(shaders, programId);

	FillBuffers();
	loadTextures();
}

void Scene::FillBuffers() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// unbind vertex array
	glBindVertexArray(0);
}

void Scene::loadTextures() {
	// load image1 for texture1
	int width, height, nrChannels;
	unsigned char *data = stbi_load("bricks.jpg", &width, &height, &nrChannels, 0);

	if (!data) {
		std::cout << "Failed to load texture 1" << std::endl;
	}
	// Handle texture

	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	// load image 2 for texture2
	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("steel.jpg", &width, &height, &nrChannels, 0);
	if (!data) {
		std::cout << "Failed to load texture 2" << std::endl;
	}

	// Handle texture

	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	// unload images data
	stbi_image_free(data);

	// Bind texture on shader
	Shader::instance().use(programId);
	Shader::instance().setInt("texture1", 0, programId);
	Shader::instance().setInt("texture2", 1, programId);
}

void Scene::bindBuffers() {
	Shader::instance().use(programId);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);

	glBindVertexArray(VAO);
}

void Scene::bindModel(Light light[], int numLights, Camera camera, unsigned int screenWidth, unsigned int screenHeight) {
	projection = glm::perspective(glm::radians(camera.getFov()), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
	Shader::instance().setMat4("projection", glm::value_ptr(projection), programId);
	view = glm::lookAt(camera.getCameraPos(), camera.getCameraPos() + camera.getCameraFront(), camera.getReferenceVector());
	Shader::instance().setMat4("view", glm::value_ptr(view), programId);
	Shader::instance().setVec3("viewPos", camera.getCameraPos().x, camera.getCameraPos().y, camera.getCameraPos().z, programId);

	for (int j = 0; j < numLights; ++j) {
		Shader::instance().setVec3("lights[" + std::to_string(j) + "].position", light[j].getDinamicPos().x, light[j].getDinamicPos().y, light[j].getDinamicPos().z, programId);
		Shader::instance().setVec3("lights[" + std::to_string(j) + "].ambient", light[j].getDiffuse(), programId);
		Shader::instance().setVec3("lights[" + std::to_string(j) + "].diffuse", light[j].getDiffuse(), programId);
		Shader::instance().setVec3("lights[" + std::to_string(j) + "].specular", glm::vec3(1.0), programId);
	}

	Shader::instance().setFloat("texMixFactor", glm::abs(glm::sin((float)glfwGetTime())), programId);

	for (unsigned int i = 0; i < 10; ++i) {
		int materialIndex;

		if (i < 5) {
			materialIndex = i;
		}
		else {
			materialIndex = i - 5;
		}

		Shader::instance().setVec3("material.ambient", Materials::materials[materialIndex].ambient, programId);
		Shader::instance().setVec3("material.diffuse", Materials::materials[materialIndex].diffuse, programId);
		Shader::instance().setVec3("material.specular", Materials::materials[materialIndex].specular, programId);
		Shader::instance().setFloat("material.shininess", Materials::materials[materialIndex].shininess, programId);

		Shader::instance().setVec3("material.color", Materials::materials[materialIndex].color, programId);

		Shader::instance().setVec3("ObjectColor", 1.0f, 0.5f, 0.31f, programId);
		model = glm::mat4(1.0f);
		model = glm::translate(model, cubePositions[i]);
		float rotationAngle = glm::radians(50.0f * (float)(i + 1)) * (float)glfwGetTime();
		glm::vec3 rotationReference = glm::vec3(glm::sin((float)glfwGetTime() * (float)i), 0.5f, -0.5f);
		glm::mat4 modelOnlyRotation = glm::rotate(glm::mat4(1.0f), rotationAngle, rotationReference);
		model = glm::rotate(model, rotationAngle, rotationReference);
		Shader::instance().setMat4("model", glm::value_ptr(model), programId);
		Shader::instance().setMat4("modelOnlyRotation", glm::value_ptr(modelOnlyRotation), programId);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}
