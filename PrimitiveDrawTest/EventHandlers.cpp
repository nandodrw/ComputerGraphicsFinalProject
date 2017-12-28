//
// Created by Nando on 12/26/17.
//

#include "EventHandlers.h"



namespace EventHandlers {

	float lastMouseX = 400, lastMouseY = 300;
	float pitch = 0.0f, yaw = 0.0f;
	bool firstMouse = true;

	void framebufer_size_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	void mouse_callback(GLFWwindow* window, double xpos, double ypos) {

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

		pitch += yOffset;
		yaw += xOffset;


		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		glm::vec3 front;
		front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		front.y = sin(glm::radians(pitch));
		front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		RenderManager::instance().getCamera().setCameraFront(glm::normalize(front));
	}

	void scroll_callback(GLFWwindow* window, double xOffset, double yOffset) {
		auto currentFov = RenderManager::instance().getCamera().getFov();

		if (currentFov >= 1.0f && RenderManager::instance().getCamera().getFov() <= 45.0f) {
			RenderManager::instance().getCamera().setFov(currentFov - yOffset);
		}

		if (RenderManager::instance().getCamera().getFov() <= 1.0f) {
			RenderManager::instance().getCamera().setFov(1.0f);
		}

		if (RenderManager::instance().getCamera().getFov() >= 45.0f) {
			RenderManager::instance().getCamera().setFov(45.0f);
		}
	}

	void process_input(GLFWwindow* window) {

		auto currentCameraPos = glm::vec3(RenderManager::instance().getCamera().getCameraPos());
		auto currentCameraFront = glm::vec3(RenderManager::instance().getCamera().getCameraFront());

		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}

		float cameraSpeed = 5.0f * RenderManager::instance().getDeltaTime();
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
			currentCameraPos += currentCameraFront * cameraSpeed;
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
			currentCameraPos -= currentCameraFront * cameraSpeed;
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
			currentCameraPos += glm::normalize(glm::cross(currentCameraFront, RenderManager::instance().getCamera().getReferenceVector())) * cameraSpeed;
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
			currentCameraPos -= glm::normalize(glm::cross(currentCameraFront, RenderManager::instance().getCamera().getReferenceVector())) * cameraSpeed;
		}

		RenderManager::instance().getCamera().setCameraFront(currentCameraFront);
		RenderManager::instance().getCamera().setCameraPos(currentCameraPos);
	}

}

