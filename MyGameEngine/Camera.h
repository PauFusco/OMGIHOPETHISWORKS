#pragma once

#include "Module.h"
#include "Engine_Globals.h"
#include "types.h"

class Camera : public Module
{
public:
	Camera(MyGameEngine* app, bool start_enabled = true);
	~Camera(){}

	bool Init();
	bool Start();
	update_status Update();
	bool CleanUp;

	mat4 computeLookAt() const;
public:
	double fov;
	double aspect;
	double zNear;
	double zFar;

	vec3 eye;
	vec3 center;
	vec3 up;
};

