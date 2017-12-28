#pragma once
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

class Interaction
{
public:
	Interaction();
	~Interaction();
	void processInput(GLFWwindow* window);
	void Interaction::mouseCallback(GLFWwindow* window, double xpos, double ypos);	
	void timeCycle(double currentTime);
	glm::mat4 getLookAtMatrix();

private:
	float deltaTime = 0.0f;
	glm::vec3 cameraPos = glm::vec3(-3.8f, 4.27f, 8.23f);
	glm::vec3 cameraFront = glm::vec3(0.398f, -0.5299f, -0.7487f);
	glm::vec3 referenceVector = glm::vec3(0.0f, 1.0f, 0.0f);
	bool firstMouse = true;
	float lastMouseX = -55, lastMouseY = -71;
	float pitchAngle = 0.0f, yawAngle = 0.0f;
	float lastFrame = 0.0f;
	float currentFrame = 0.0f;
};

