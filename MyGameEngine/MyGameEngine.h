#pragma once

#include <chrono>
#include <list>

#include "types.h"
#include "Engine_Globals.h"
#include "Camera.h"
#include "ModuleRenderer.h"

class MyGameEngine
{
public:
	MyGameEngine();
	~MyGameEngine();

	bool Init();
	bool Update();
	bool CleanUp();

	void step(std::chrono::duration<double> dt);
	//void render();

private:
	void AddModule(Module* mod);
	//void PrepareUpdate();
	//void FinishUpdate();

public:
	// Module Variables
	Camera* camera;
	ModuleRenderer* renderer;
	

private:
	std::list<Module*> list_modules;

};