#pragma once

#include <chrono>
#include <list>

#include "types.h"
#include "Engine_Globals.h"
#include "Camera.h"

class MyGameEngine
{
public:
	MyGameEngine();
	~MyGameEngine();

	bool Init();
	update_status Update();
	bool CleanUp();

	void step(std::chrono::duration<double> dt);
	void render();

private:
	void AddModule(Module* mod);
	//void PrepareUpdate();
	//void FinishUpdate();

public:
	// Module Variables
	Camera* camera;

private:
	std::list<Module*> list_modules;

};