// Include GLEW
#include <GL/glew.h>
#include <vector>
#include "Drawer.h"

using std::vector;

void Drawer::DrawLineMap(vector<GLfloat>& pointBuffer, vector<GLfloat>& colorBuffer) {
	// float initialTop = 1.0f;
	// float initialLow = -1.0f;

	float initialTop = 3.0f;
	float initialLow = -3.0f;

	for (size_t i = 0; i < 41; i++)
	{
		// staring point
		pointBuffer.push_back(-3.0f);
		pointBuffer.push_back(initialTop);
		// pointBuffer.push_back(0.0f);
		pointBuffer.push_back(((float)i/10.0f));

		colorBuffer.push_back(1.0f);
		colorBuffer.push_back(1.0f);
		colorBuffer.push_back(1.0f);
		colorBuffer.push_back(1.0f);

		// end point
		pointBuffer.push_back(initialLow);
		pointBuffer.push_back(-3.0f);
		// pointBuffer.push_back(0.0f);
		pointBuffer.push_back(((float)(41 - i)/10.0f));

		colorBuffer.push_back(1.0f);
		colorBuffer.push_back(1.0f);
		colorBuffer.push_back(1.0f);
		colorBuffer.push_back(1.0f);

		initialTop -= 0.15f;
		initialLow += 0.15f;
		// initialTop -= 0.5f;
		// initialLow += 0.5f;
	}

	initialTop = 3.0f;
	initialLow = -3.0f;

	for (size_t i = 0; i < 41; i++)
	{
		// staring point
		pointBuffer.push_back(initialLow);
		pointBuffer.push_back(3.0f);
		// pointBuffer.push_back(0.0f);
		pointBuffer.push_back(((float)i / 10.0f));

		colorBuffer.push_back(1.0f);
		colorBuffer.push_back(1.0f);
		colorBuffer.push_back(1.0f);
		colorBuffer.push_back(1.0f);

		// end point
		pointBuffer.push_back(3.0f);
		pointBuffer.push_back(initialTop);
		// pointBuffer.push_back(0.0f);
		pointBuffer.push_back(((float)(41 - i) / 10.0f));

		colorBuffer.push_back(1.0f);
		colorBuffer.push_back(1.0f);
		colorBuffer.push_back(1.0f);
		colorBuffer.push_back(1.0f);

		initialTop -= 0.15f;
		initialLow += 0.15f;
	}
}

void Drawer::IgnitionFire(vector<GLfloat>& pointBuffer, vector<GLfloat>& colorBuffer, GLfloat xInit, GLfloat yInit, GLfloat zOffset) {
	// 1st- TRIANGLE 

	// 1t-0
	pointBuffer.push_back(xInit);
	pointBuffer.push_back(yInit);
	pointBuffer.push_back(-1.1f + zOffset);
	
	// 1t-1
	pointBuffer.push_back(xInit + 0.1f);
	pointBuffer.push_back(yInit + 0.25f);
	pointBuffer.push_back(-1.3f + zOffset);

	// 1t-2
	pointBuffer.push_back(xInit - 0.05f);
	pointBuffer.push_back(yInit + 0.2f);
	pointBuffer.push_back(-1.2f + zOffset);


	// 2st- TRIANGLE 

	// 2t-0
	pointBuffer.push_back(xInit);
	pointBuffer.push_back(yInit);
	pointBuffer.push_back(-1.3f + zOffset);

	// 2t-1
	pointBuffer.push_back(xInit + 0.05f);
	pointBuffer.push_back(yInit + 0.3f);
	pointBuffer.push_back(-1.2f + zOffset);

	// 2t-2
	pointBuffer.push_back(xInit + 0.2f);
	pointBuffer.push_back(yInit + 0.15f);
	pointBuffer.push_back(-1.1f + zOffset);


	// 3st- TRIANGLE 

	// 3t-0
	pointBuffer.push_back(xInit);
	pointBuffer.push_back(yInit);
	pointBuffer.push_back(-1.1f + zOffset);

	// 3t-1
	pointBuffer.push_back(xInit + 0.1f);
	pointBuffer.push_back(yInit + 0.3f);
	pointBuffer.push_back(-1.2f + zOffset);

	// 3t-2
	pointBuffer.push_back(xInit - 0.15f);
	pointBuffer.push_back(yInit + 0.15f);
	pointBuffer.push_back(-1.3f + zOffset);

	// 4st- TRIANGLE 

	// 4t-0
	pointBuffer.push_back(xInit);
	pointBuffer.push_back(yInit);
	pointBuffer.push_back(-1.2f + zOffset);

	// 4t-1
	pointBuffer.push_back(xInit + 0.2f);
	pointBuffer.push_back(yInit + 0.2f);
	pointBuffer.push_back(-1.1f + zOffset);

	// 4t-2
	pointBuffer.push_back(xInit + 0.2f);
	pointBuffer.push_back(yInit - 0.15f);
	pointBuffer.push_back(-1.3f + zOffset);

	// 5st- TRIANGLE 

	// 5t-0
	pointBuffer.push_back(xInit);
	pointBuffer.push_back(yInit);
	pointBuffer.push_back(-1.4f + zOffset);

	// 5t-1
	pointBuffer.push_back(xInit + 0.15f);
	pointBuffer.push_back(yInit - 0.15f);
	pointBuffer.push_back(-1.1f + zOffset);

	// 5t-2
	pointBuffer.push_back(xInit - 0.15f);
	pointBuffer.push_back(yInit - 0.15f);
	pointBuffer.push_back(-1.2f + zOffset);

	// 6st- TRIANGLE 

	// 6t-0
	pointBuffer.push_back(xInit);
	pointBuffer.push_back(yInit);
	pointBuffer.push_back(-1.1f + zOffset);

	// 6t-1
	pointBuffer.push_back(xInit - 0.05f);
	pointBuffer.push_back(yInit - 0.2f);
	pointBuffer.push_back(-1.3f + zOffset);

	// 6t-2
	pointBuffer.push_back(xInit - 0.15f);
	pointBuffer.push_back(yInit + 0.25f);
	pointBuffer.push_back(-1.2f + zOffset);


	for (size_t i = 0; i < 6; i++)
	{
		colorBuffer.push_back(1.0f);
		colorBuffer.push_back(0.38f);
		colorBuffer.push_back(0.0f);
		colorBuffer.push_back(0.7f);

		for (size_t j = 0; j < 2; j++)
		{
			colorBuffer.push_back(1.0f);
			colorBuffer.push_back(0.38f);
			colorBuffer.push_back(0.0f);
			colorBuffer.push_back(0.0f);
		}
	}
	
}

void Drawer::DrawSpaceShip(vector<GLfloat>& pointBuffer, vector<GLfloat>& colorBuffer, GLfloat xOffset, GLfloat yOffset, GLfloat zOffset) {

	
	// Drawing engine 1
	
	// E1
	pointBuffer.push_back(0.5f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// E2
	pointBuffer.push_back(0.6f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// E3
	pointBuffer.push_back(0.6f + xOffset);
	pointBuffer.push_back(0.45f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// E4
	pointBuffer.push_back(0.55f + xOffset);
	pointBuffer.push_back(0.5f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// E5
	pointBuffer.push_back(0.45f + xOffset);
	pointBuffer.push_back(0.5f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// E6
	pointBuffer.push_back(0.4f + xOffset);
	pointBuffer.push_back(0.45f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// E7
	pointBuffer.push_back(0.4f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// Deep of engine 1
	// E1
	pointBuffer.push_back(0.5f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.5f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// E2
	pointBuffer.push_back(0.6f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.6f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// E3
	pointBuffer.push_back(0.6f + xOffset);
	pointBuffer.push_back(0.45f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.6f + xOffset);
	pointBuffer.push_back(0.45f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// E4
	pointBuffer.push_back(0.55f + xOffset);
	pointBuffer.push_back(0.5f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.55f + xOffset);
	pointBuffer.push_back(0.5f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// E5
	pointBuffer.push_back(0.45f + xOffset);
	pointBuffer.push_back(0.5f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.45f + xOffset);
	pointBuffer.push_back(0.5f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// E6
	pointBuffer.push_back(0.4f + xOffset);
	pointBuffer.push_back(0.45f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.4f + xOffset);
	pointBuffer.push_back(0.45f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// E7
	pointBuffer.push_back(0.4f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.4f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// E8 
	pointBuffer.push_back(0.5f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.5f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	for (size_t i = 0; i < 23; i++)
	{
		colorBuffer.push_back(0.47f);
		colorBuffer.push_back(0.47f);
		colorBuffer.push_back(0.47f);
		colorBuffer.push_back(1.0f);
	}

	// Drawing engine cover 1

	// EC1
	pointBuffer.push_back(0.45f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// EC2
	pointBuffer.push_back(0.45f + xOffset);
	pointBuffer.push_back(0.45f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// EC3
	pointBuffer.push_back(0.55f + xOffset);
	pointBuffer.push_back(0.45f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// EC4
	pointBuffer.push_back(0.55f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	for (size_t i = 0; i < 4; i++)
	{
		colorBuffer.push_back(0.0f);
		colorBuffer.push_back(0.3f);
		colorBuffer.push_back(0.0f);
		colorBuffer.push_back(1.0f);
	}



	// Drawing engine 2

	// E8
	pointBuffer.push_back(0.8f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// E9
	pointBuffer.push_back(0.9f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// E10
	pointBuffer.push_back(0.9f + xOffset);
	pointBuffer.push_back(0.45f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// E11
	pointBuffer.push_back(0.85f + xOffset);
	pointBuffer.push_back(0.5f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// E12
	pointBuffer.push_back(0.75f + xOffset);
	pointBuffer.push_back(0.5f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// E13
	pointBuffer.push_back(0.7f + xOffset);
	pointBuffer.push_back(0.45f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// E14
	pointBuffer.push_back(0.7f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// Deep of the engine 2
	// E8
	pointBuffer.push_back(0.8f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.8f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// E9
	pointBuffer.push_back(0.9f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.9f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// E10
	pointBuffer.push_back(0.9f + xOffset);
	pointBuffer.push_back(0.45f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.9f + xOffset);
	pointBuffer.push_back(0.45f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// E11
	pointBuffer.push_back(0.85f + xOffset);
	pointBuffer.push_back(0.5f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.85f + xOffset);
	pointBuffer.push_back(0.5f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// E12
	pointBuffer.push_back(0.75f + xOffset);
	pointBuffer.push_back(0.5f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.75f + xOffset);
	pointBuffer.push_back(0.5f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// E13
	pointBuffer.push_back(0.7f + xOffset);
	pointBuffer.push_back(0.45f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.7f + xOffset);
	pointBuffer.push_back(0.45f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// E14
	pointBuffer.push_back(0.7f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.7f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// E8
	pointBuffer.push_back(0.8f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.8f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	for (size_t i = 0; i < 23; i++)
	{
		colorBuffer.push_back(0.47f);
		colorBuffer.push_back(0.47f);
		colorBuffer.push_back(0.47f);
		colorBuffer.push_back(1.0f);
	}


	// Drawing engine cover 2

	// EC5
	pointBuffer.push_back(0.75f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// EC6
	pointBuffer.push_back(0.75f + xOffset);
	pointBuffer.push_back(0.45f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// EC7
	pointBuffer.push_back(0.85f + xOffset);
	pointBuffer.push_back(0.45f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// EC8
	pointBuffer.push_back(0.85f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	for (size_t i = 0; i < 4; i++)
	{
		colorBuffer.push_back(0.0f);
		colorBuffer.push_back(0.3f);
		colorBuffer.push_back(0.0f);
		colorBuffer.push_back(1.0f);
	}


	// Drawing cargo 1

	// C1
	pointBuffer.push_back(0.4f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// C2
	pointBuffer.push_back(0.15f + xOffset);
	pointBuffer.push_back(0.25f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// C3
	pointBuffer.push_back(0.45f + xOffset);
	pointBuffer.push_back(0.15f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// Drawing cargo 3d
	// C1
	pointBuffer.push_back(0.4f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.4f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// C2
	pointBuffer.push_back(0.15f + xOffset);
	pointBuffer.push_back(0.25f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.15f + xOffset);
	pointBuffer.push_back(0.25f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// C3
	pointBuffer.push_back(0.45f + xOffset);
	pointBuffer.push_back(0.15f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.45f + xOffset);
	pointBuffer.push_back(0.15f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// C1
	pointBuffer.push_back(0.4f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.4f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	for (size_t i = 0; i < 3; i++)
	{
		colorBuffer.push_back(0.5f);
		colorBuffer.push_back(0.4f);
		colorBuffer.push_back(0.7f);
		colorBuffer.push_back(1.0f);
	}

	for (size_t i = 0; i < 9; i++)
	{
		colorBuffer.push_back(0.4f);
		colorBuffer.push_back(0.3f);
		colorBuffer.push_back(0.7f);
		colorBuffer.push_back(1.0f);
	}


	// Drawing cargo 2

	// C4
	pointBuffer.push_back(0.9f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// C5
	pointBuffer.push_back(1.15f + xOffset);
	pointBuffer.push_back(0.25f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// C6
	pointBuffer.push_back(0.85f + xOffset);
	pointBuffer.push_back(0.15f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// Cargo 2 3d
	// C4
	pointBuffer.push_back(0.9f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.9f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// C5
	pointBuffer.push_back(1.15f + xOffset);
	pointBuffer.push_back(0.25f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(1.15f + xOffset);
	pointBuffer.push_back(0.25f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// C6
	pointBuffer.push_back(0.85f + xOffset);
	pointBuffer.push_back(0.15f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.85f + xOffset);
	pointBuffer.push_back(0.15f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// C4
	pointBuffer.push_back(0.9f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.9f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	for (size_t i = 0; i < 3; i++)
	{
		colorBuffer.push_back(0.5f);
		colorBuffer.push_back(0.4f);
		colorBuffer.push_back(0.7f);
		colorBuffer.push_back(1.0f);
	}

	for (size_t i = 0; i < 9; i++)
	{
		colorBuffer.push_back(0.4f);
		colorBuffer.push_back(0.3f);
		colorBuffer.push_back(0.7f);
		colorBuffer.push_back(1.0f);
	}



	// Drawing the main boddy

	// m1
	pointBuffer.push_back(0.45f + xOffset);
	pointBuffer.push_back(0.15f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// m2
	pointBuffer.push_back(0.4f + xOffset);
	pointBuffer.push_back(0.2f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// m3
	pointBuffer.push_back(0.4f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// m4
	pointBuffer.push_back(0.5f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// m5
	pointBuffer.push_back(0.65f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// m6
	pointBuffer.push_back(0.8f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// m7
	pointBuffer.push_back(0.9f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// m8
	pointBuffer.push_back(0.9f + xOffset);
	pointBuffer.push_back(0.2f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	// m9
	pointBuffer.push_back(0.85f + xOffset);
	pointBuffer.push_back(0.15f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);


	//Drawing Main body 3d

	// m1
	pointBuffer.push_back(0.45f + xOffset);
	pointBuffer.push_back(0.15f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.45f + xOffset);
	pointBuffer.push_back(0.15f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);


	// m2
	pointBuffer.push_back(0.4f + xOffset);
	pointBuffer.push_back(0.2f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.4f + xOffset);
	pointBuffer.push_back(0.2f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// m3
	pointBuffer.push_back(0.4f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.4f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// m4
	pointBuffer.push_back(0.5f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.5f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// m5
	pointBuffer.push_back(0.65f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.65f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// m6
	pointBuffer.push_back(0.8f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.8f + xOffset);
	pointBuffer.push_back(0.4f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// m7
	pointBuffer.push_back(0.9f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.9f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// m8
	pointBuffer.push_back(0.9f + xOffset);
	pointBuffer.push_back(0.2f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.9f + xOffset);
	pointBuffer.push_back(0.2f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// m9
	pointBuffer.push_back(0.85f + xOffset);
	pointBuffer.push_back(0.15f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.85f + xOffset);
	pointBuffer.push_back(0.15f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	// m1
	pointBuffer.push_back(0.45f + xOffset);
	pointBuffer.push_back(0.15f + yOffset);
	pointBuffer.push_back(0.0f + zOffset);

	pointBuffer.push_back(0.45f + xOffset);
	pointBuffer.push_back(0.15f + yOffset);
	pointBuffer.push_back(-1.0f + zOffset);

	for (size_t i = 0; i < 29; i++)
	{
		colorBuffer.push_back(0.14f);
		colorBuffer.push_back(0.18f);
		colorBuffer.push_back(0.29f);
		colorBuffer.push_back(1.0f);
	}


	// Drawing the ship window

	// First part - TRIANGLE FAN

	// w1
	pointBuffer.push_back(0.45f + xOffset);
	pointBuffer.push_back(0.25f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);
	
	// W5
	pointBuffer.push_back(0.7f + xOffset);
	pointBuffer.push_back(0.25f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// w4
	pointBuffer.push_back(0.6f + xOffset);
	pointBuffer.push_back(0.3f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// w3
	pointBuffer.push_back(0.55f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// w2
	pointBuffer.push_back(0.45f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	for (size_t i = 0; i < 5; i++)
	{
		if (i % 2 == 0) {
			colorBuffer.push_back(0.09f);
			colorBuffer.push_back(0.53f);
			colorBuffer.push_back(0.74f);
			colorBuffer.push_back(1.0f);
		}
		else {
			colorBuffer.push_back(0.85f);
			colorBuffer.push_back(0.93f);
			colorBuffer.push_back(0.98f);
			colorBuffer.push_back(1.0f);
		}
	}


	// Second part - TRIANGLE STRIP

	// W11
	pointBuffer.push_back(0.85f + xOffset);
	pointBuffer.push_back(0.25f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// W10
	pointBuffer.push_back(0.85f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// W9
	pointBuffer.push_back(0.8f + xOffset);
	pointBuffer.push_back(0.25f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// W8
	pointBuffer.push_back(0.8f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// W5
	pointBuffer.push_back(0.7f + xOffset);
	pointBuffer.push_back(0.25f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// W7
	pointBuffer.push_back(0.75f + xOffset);
	pointBuffer.push_back(0.35f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// W6
	pointBuffer.push_back(0.7f + xOffset);
	pointBuffer.push_back(0.3f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	for (size_t i = 0; i < 7; i++)
	{
		
		if (i % 2 == 0) {
			colorBuffer.push_back(0.09f);
			colorBuffer.push_back(0.53f);
			colorBuffer.push_back(0.74f);
			colorBuffer.push_back(1.0f);
		}
		else {
			colorBuffer.push_back(0.85f);
			colorBuffer.push_back(0.93f);
			colorBuffer.push_back(0.98f);
			colorBuffer.push_back(1.0f);
		}
	}
	
	// 3th part - TRIANGLE 

	// W5
	pointBuffer.push_back(0.7f + xOffset);
	pointBuffer.push_back(0.25f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// W6
	pointBuffer.push_back(0.7f + xOffset);
	pointBuffer.push_back(0.3f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	// w4
	pointBuffer.push_back(0.6f + xOffset);
	pointBuffer.push_back(0.3f + yOffset);
	pointBuffer.push_back(0.01f + zOffset);

	for (size_t i = 0; i < 3; i++)
	{
		if (i % 2 == 0) {
			colorBuffer.push_back(0.09f);
			colorBuffer.push_back(0.53f);
			colorBuffer.push_back(0.74f);
			colorBuffer.push_back(1.0f);
		}
		else {
			colorBuffer.push_back(0.85f);
			colorBuffer.push_back(0.93f);
			colorBuffer.push_back(0.98f);
			colorBuffer.push_back(1.0f);
		}
	}

}

void Drawer::Start(vector<GLfloat>& pointBuffer, vector<GLfloat>& colorBuffer, GLfloat xInit, GLfloat yInit, GLfloat zInit) {
	

	// Line
	pointBuffer.push_back(xInit);
	pointBuffer.push_back(yInit);
	pointBuffer.push_back(0.0f + zInit);

	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(0.4f);


	pointBuffer.push_back(xInit);
	pointBuffer.push_back(yInit + 0.1f);
	pointBuffer.push_back(0.0f + zInit);

	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(0.2f);



	pointBuffer.push_back(xInit + 0.05f);
	pointBuffer.push_back(yInit);
	pointBuffer.push_back(0.0f + zInit);

	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(0.3f);

	pointBuffer.push_back(xInit - 0.05f);
	pointBuffer.push_back(yInit);
	pointBuffer.push_back(0.0f + zInit);

	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(0.1f);

	pointBuffer.push_back(xInit);
	pointBuffer.push_back(yInit - 0.1f);
	pointBuffer.push_back(0.0f + zInit);

	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(0.2f);

	pointBuffer.push_back(xInit);
	pointBuffer.push_back(yInit);
	pointBuffer.push_back(0.0f + zInit);

	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(0.4f);





	// Center
	pointBuffer.push_back(xInit);
	pointBuffer.push_back(yInit);
	pointBuffer.push_back(0.0f + zInit);

	colorBuffer.push_back(1.0f);
	colorBuffer.push_back(0.9f);
	colorBuffer.push_back(0.89f);
	colorBuffer.push_back(0.5f);

}
