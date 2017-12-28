//
// Created by Nando on 12/25/17.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "RenderManager.h"



namespace EventHandlers {

	void framebufer_size_callback(GLFWwindow* window, int width, int height);

	void mouse_callback(GLFWwindow* window, double xpos, double ypos);

	void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);

	void process_input(GLFWwindow* window);

}

