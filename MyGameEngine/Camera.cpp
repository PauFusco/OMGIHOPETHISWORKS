#include "Camera.h"
#include "Engine_Globals.h"

#include <glm/ext/matrix_transform.hpp>

Camera::Camera(MyGameEngine* engine, bool start_enabled) : Module(engine, start_enabled)
{}
bool Camera::Init() {
	fov = 60;
	aspect = 4.0 / 3.0;
	zNear = 0.1;
	zFar = 100;
	eye = vec3(10, 2, 10);
	center = vec3(0, 1, 0);
	up = vec3(0, 1, 0);
}

glm::dmat4 Camera::computeLookAt() const {
	return glm::lookAt(eye, center, up);
}