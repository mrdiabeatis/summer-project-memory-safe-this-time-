#pragma once

#include<iostream>
#include<Windows.h>

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include<vector>
#include<stdint.h>
#include<cstdint>

#include"Mesh.h"

#include"ECS_Entity.h"

class App {
	void post_render();
	void pre_render();
	void render();
	struct config {
		uint16_t WIDTH;
		uint16_t HEIGHT;
		bool	 resizable;
		uint16_t V_WIDTH;
		uint16_t V_HEIGHT;
		GLFWwindow* window;
	} config;
	struct collections {
		std::vector<ECS_Entity> _entities;
	} collections;
public:
	App(uint16_t WIDTH, uint16_t HEIGHT);
	App(uint16_t WIDTH, uint16_t HEIGHT, bool resizable);
	App(uint16_t WIDTH, uint16_t HEIGHT, bool resizable, uint16_t V_WIDTH, uint16_t V_HEIGHT);
	void draw();
	void de_instance();

	bool app_ShouldClose();
	void process_Entity(ECS_Entity* e);
};