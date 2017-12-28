#include "Interaction.h"



Interaction::Interaction()
{
}


Interaction::~Interaction()
{
}

void Interaction::processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}

	float cameraSpeed = 5.0f * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		cameraPos += cameraFront * cameraSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		cameraPos -= cameraFront * cameraSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		cameraPos += glm::normalize(glm::cross(cameraFront, referenceVector)) * cameraSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		cameraPos -= glm::normalize(glm::cross(cameraFront, referenceVector)) * cameraSpeed;
	}
}

void Interaction::mouseCallback(GLFWwindow* window, double xpos, double ypos) {

	if (firstMouse) {
		lastMouseY = ypos;
		lastMouseX = xpos;
		firstMouse = false;
	}

	float xOffset = xpos - lastMouseX;
	float yOffset = lastMouseY - ypos;

	lastMouseX = xpos;
	lastMouseY = ypos;

	float sensitivity = 0.2f;
	xOffset *= sensitivity;
	yOffset *= sensitivity;

	pitchAngle += yOffset;
	yawAngle += xOffset;


	if (pitchAngle > 89.0f) {
		pitchAngle = 89.0f;
	}
		
	if (pitchAngle < -89.0f) {
		pitchAngle = -89.0f;
	}

	glm::vec3 front;
	front.x = cos(glm::radians(yawAngle)) * cos(glm::radians(pitchAngle));
	front.y = sin(glm::radians(pitchAngle));
	front.z = sin(glm::radians(yawAngle)) * cos(glm::radians(pitchAngle));
	cameraFront = glm::normalize(front);
}

void Interaction::timeCycle(double currentTime) {
	currentFrame = currentTime;
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}

glm::mat4 Interaction::getLookAtMatrix() {
	return glm::lookAt(cameraPos, cameraPos + cameraFront, referenceVector);
}

