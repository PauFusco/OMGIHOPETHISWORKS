#pragma once
#include "Module.h"
#include "Globals.h"
#include "Camera.h"
#include <chrono>

class ModuleRenderer : public Module
{

public:

	ModuleRenderer(MyGameEngine* app, bool start_enabled);
	~ModuleRenderer();

	bool Init();
	bool PreUpdate();
	bool PostUpdate();
	bool CleanUp();

	void OnResize(int width, int height);

	void render();
	void drawGrid(int grid_size, int grid_step);
	void drawAxis();

public:

	const double angle = 0.0f;
	Camera camera;
};