// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <vector>


using std::vector;

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
using namespace glm;

#include <common/shader.hpp>

//void addLineVertex(GLfloat[]points);

int init();
void loadShaders();
void drawTriangles();

GLuint programID;
GLuint vertexPosition_modelspaceID;
GLuint vertexbuffer;

void addScenarioLines(vector<GLfloat>& pointBuffer) {
	
	float initialTop = 1.0f;
	float initialLow = -1.0f;

	for (size_t i = 0; i < 82; i++)
	{
		// staring point
		pointBuffer.push_back(-1.0f);
		pointBuffer.push_back(initialTop);
		pointBuffer.push_back(0.0f);

		// end point
		pointBuffer.push_back(initialLow);
		pointBuffer.push_back(-1.0f);
		pointBuffer.push_back(0.0f);

		initialTop -= 0.05f;
		initialLow += 0.05f;
	}

	initialTop = 1.0f;
	initialLow = -1.0f;

	for (size_t i = 0; i < 82; i++)
	{
		// staring point
		pointBuffer.push_back(initialLow);
		pointBuffer.push_back(1.0f);
		pointBuffer.push_back(0.0f);

		// end point
		pointBuffer.push_back(1.0f);
		pointBuffer.push_back(initialTop);
		pointBuffer.push_back(0.0f);

		initialTop -= 0.05f;
		initialLow += 0.05f;
	}
}

int main(void)
{
	// Initializing a window and glew 
	init();

	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");

	// Get a handle for our buffers
	GLuint vertexPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");


	vector<GLfloat> g_vertex_buffer_dataVect;

	// Sart the drawing points!!
	addScenarioLines(g_vertex_buffer_dataVect);

	static GLfloat* g_vertex_buffer_data = &g_vertex_buffer_dataVect[0];

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, (sizeof(GLfloat) * g_vertex_buffer_dataVect.size()), g_vertex_buffer_data, GL_STATIC_DRAW);

	do{

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT);

		// Use our shader
		glUseProgram(programID);

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(vertexPosition_modelspaceID);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			vertexPosition_modelspaceID, // The attribute we want to configure
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
			);

		// Draw the triangle !
		glDrawArrays(GL_LINES, 0, 82);

		glDrawArrays(GL_LINES, 84, 164);

		// glPointSize(10);
		// glDrawArrays(GL_POINTS, 6, 4);

		//glDrawArrays(GL_LINES, 6, 2); 

		//glDrawArrays(GL_QUADS, 6, 4);  

		//glDrawArrays(GL_TRIANGLES, 0, sizeof(g_vertex_buffer_data) / sizeof(g_vertex_buffer_data[0]));  // 3 indices starting at 0 -> 1 triangle

		glDisableVertexAttribArray(vertexPosition_modelspaceID);

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
	glfwWindowShouldClose(window) == 0);


	// Cleanup VBO
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteProgram(programID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}

int init(){
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);


	// Open a window and create its OpenGL context
	window = glfwCreateWindow(1024, 768, "A sample scene", NULL, NULL);
	if (window == NULL){
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

}
