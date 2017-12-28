//
// Created by Nando on 12/25/17.
//

#include "RenderManager.h"

void RenderManager::init() {

	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
//		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	


	// Open a window and create its OpenGL context
	window = glfwCreateWindow(screenWidth, screenHeight, "A sample scene", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
//		return -1;
	}
	glfwMakeContextCurrent(window);

	glfwSetCursorPosCallback(window, EventHandlers::mouse_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glewExperimental = GL_TRUE;

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
	//	return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Enabling transparency
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_BLEND);

	// Dark blue background
	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
}

void RenderManager::runRenderLoop() {

	scene = Scene();
	scene.init();

	Light light1 = Light(1, glm::vec3(3.0f, 1.0f, 3.0f));
	Light light2 = Light(2, glm::vec3(0.0f, -3.0f, 3.0f));
	Light light3 = Light(3, glm::vec3(3.0f, 3.0f, -3.0f));

	light1.init();
	//    light2.init();
	  //  light3.init();

	light2.init(glm::vec3(0.1), glm::vec3(0.5), glm::vec3(1.0));
	light3.init(glm::vec3(0.2), glm::vec3(0.7), glm::vec3(0.2));

	while (!glfwWindowShouldClose(window)) {

		GLenum error = glGetError();

		if (error != GL_NO_ERROR)
		{
			std::cout << "OpenGL Error: " << error << std::endl;
		}

		EventHandlers::process_input(window);

		// Calculate deltaTime
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// Render
		// -------
		glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//        Logger::log("mew");

		light1.setDinamicPosition((float)glfwGetTime());
		light1.render(camera, screenWidth, screenHeight);

		light2.setDinamicPosition((float)glfwGetTime());
		light2.render(camera, screenWidth, screenHeight);

		light3.setDinamicPosition((float)glfwGetTime());
		light3.render(camera, screenWidth, screenHeight);

		Light lights[3] = { light1, light2, light3 };

		scene.render(lights, 3, camera, screenWidth, screenHeight);

		// Swap buffers
		// ------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}



	glfwTerminate();
}

Scene RenderManager::getScene() {
	return scene;
}

float RenderManager::getDeltaTime() const {
	return deltaTime;
}

RenderManager::RenderManager() : camera(Camera(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 7.0f))) {}

Camera &RenderManager::getCamera() {
	return camera;
}

//RenderManager::RenderManager(const Camera &camera) : camera(camera) {}
