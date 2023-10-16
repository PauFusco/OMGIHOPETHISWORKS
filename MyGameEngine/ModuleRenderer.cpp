#include "ModuleRenderer.h"
#include "MyGameEngine.h"
#include <GL\glew.h>
#include <glm/ext/matrix_transform.hpp>
#include <vector>
#include <IL/il.h>
#include "types.h"

#include "CubeImmediateMode.h"
#include "CubeVertexArray.h"
#include "CubeVertexBuffer.h"
#include "CubeInterleavedVBO.h"
#include "CubeWireframeIVBO.h"

#include "GraphicObject.h"

using namespace std;

ModuleRenderer::ModuleRenderer(MyGameEngine* Engine, bool start_enabled) : Module(Engine, start_enabled)
{}
bool ModuleRenderer::Init() {

	return true;
}

bool ModuleRenderer::PreUpdate()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(Engine->camera->fov, Engine->camera->aspect, Engine->camera->zNear, Engine->camera->zFar);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(Engine->camera->eye.x, Engine->camera->eye.y, Engine->camera->eye.z,
		Engine->camera->center.x, Engine->camera->center.y, Engine->camera->center.z,
		Engine->camera->up.x, Engine->camera->up.y, Engine->camera->up.z);

	drawGrid(100, 1);
	drawAxis();

	return true;
}

bool ModuleRenderer::PostUpdate()
{
#pragma region Draw Sandbox
	auto cubeDraw = make_shared<CubeImmediateMode>();
	GraphicObject cubeA(cubeDraw);
	GraphicObject cubeB(cubeDraw);
	GraphicObject cubeC(cubeDraw);

	cubeA.addChild(&cubeB);
	cubeB.addChild(&cubeC);
	cubeB.pos().y = 2.5;
	cubeC.pos().x = 2.5;

	cubeA.rotate(glm::radians(angle), vec3(0, 1, 0));
	cubeB.rotate(glm::radians(angle), vec3(1, 0, 0));
	cubeC.rotate(glm::radians(angle), vec3(0, 0, 1));

	cubeA.paint();

#pragma endregion
	assert(glGetError() == GL_NONE);

	return true;
}

bool ModuleRenderer::CleanUp()
{
	return true;
}

void ModuleRenderer::drawAxis() {
	glLineWidth(4.0);
	glBegin(GL_LINES);
	glColor3ub(255, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0.8, 0, 0);
	glColor3ub(0, 255, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0.8, 0);
	glColor3ub(0, 0, 1);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 0.8);
	glEnd();
}

void ModuleRenderer::drawGrid(int grid_size, int grid_step) {
	glLineWidth(1.0);
	glColor3ub(128, 128, 128);

	glBegin(GL_LINES);
	for (int i = -grid_size; i <= grid_size; i += grid_step) {
		//XY plane
		glVertex2i(i, -grid_size);
		glVertex2i(i, grid_size);
		glVertex2i(-grid_size, i);
		glVertex2i(grid_size, i);

		//XZ plane
		glVertex3i(i, 0, -grid_size);
		glVertex3i(i, 0, grid_size);
		glVertex3i(-grid_size, 0, i);
		glVertex3i(grid_size, 0, i);
	}
	glEnd();
}