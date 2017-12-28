#pragma once
#include <GL/glew.h>
#include <vector>

using std::vector;

class Drawer
{
public:
	static void DrawLineMap(vector<GLfloat>& pointBuffer, vector<GLfloat>& colorBuffer);
	static void DrawSpaceShip(vector<GLfloat>& pointBuffer, vector<GLfloat>& colorBuffer, GLfloat xOffset, GLfloat yOffset, GLfloat zOffset);
	static void IgnitionFire(vector<GLfloat>& pointBuffer, vector<GLfloat>& colorBuffer, GLfloat xInit, GLfloat yInit, GLfloat zOffset);
	static void Start(vector<GLfloat>& pointBuffer, vector<GLfloat>& colorBuffer, GLfloat xInit, GLfloat yInit, GLfloat zInit);
};
