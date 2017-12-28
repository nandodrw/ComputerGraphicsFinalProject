//
// Created by Nando on 12/26/17.
//

#ifndef COMPUTERGRAPHICSBASEPROJECT_CAMERA_H
#define COMPUTERGRAPHICSBASEPROJECT_CAMERA_H

#include <glm/glm.hpp>

class Camera {

	int ref = 1;

public:
	Camera(glm::vec3 cameraFront, glm::vec3 cameraPos) : cameraFront(cameraFront), cameraPos(cameraPos) {}

	glm::vec3 getCameraFront() {
		return cameraFront;
	}

	const glm::vec3 getCameraPos() const {
		return cameraPos;
	}

	void setCameraFront(glm::vec3 cameraFront) {
		this->cameraFront = cameraFront;
	}

	void setCameraPos(glm::vec3 cameraPos) {
		this->cameraPos = cameraPos;
	}

	const glm::vec3 &getReferenceVector() const {
		return referenceVector;
	}

	float getFov() {
		return fov;
	}

	void setFov(float fov) {
		fov = fov;
	}

	void setRef(int ref) {
		Camera::ref = ref;
	}

private:
	glm::vec3 cameraFront, cameraPos;
	glm::vec3 referenceVector = glm::vec3(0.0f, 1.0f, 0.0f);
	float fov = 45.0f;

};


#endif //COMPUTERGRAPHICSBASEPROJECT_CAMERA_H
