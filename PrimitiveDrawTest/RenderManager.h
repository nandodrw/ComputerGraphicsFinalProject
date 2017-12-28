//
// Created by Nando on 12/25/17.
//

#ifndef COMPUTERGRAPHICSBASEPROJECT_RENDERMANAGER_H
#define COMPUTERGRAPHICSBASEPROJECT_RENDERMANAGER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Logger.h"
#include "EventHandlers.h"
#include "Scene.h"
#include "Camera.h"

class Scene;

class RenderManager {

public:
	RenderManager();

	//    RenderManager(const Camera &camera);

	static RenderManager& instance()
	{
		static RenderManager *instance = new RenderManager();
		return *instance;
	}

	void init();
	void runRenderLoop();

	unsigned int getScreenWidth() { return screenWidth; }
	unsigned int getScreenHeight() { return screenHeight; }

	Scene getScene();

	Camera &getCamera();

	float getDeltaTime() const;

private:
	GLFWwindow * window;
	unsigned int screenWidth = 800;
	unsigned int screenHeight = 600;
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;
	float currentFrame = 0.0f;
	Scene scene;
	Camera camera;

};


#endif //COMPUTERGRAPHICSBASEPROJECT_RENDERMANAGER_H
