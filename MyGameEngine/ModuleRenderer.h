#pragma once
#include "Module.h"
#include "Globals.h"
#include "Camera.h"
#include <chrono>

class ModuleRenderer : public Module
{

public:

	ModuleRenderer(MyGameEngine* app);
	~ModuleRenderer();

	bool Init();
	update_status PreUpdate();
	update_status PostUpdate();
	bool CleanUp();

	void OnResize(int width, int height);

	void render();

public:

	static double angle = 0.0;
	Camera camera;
};