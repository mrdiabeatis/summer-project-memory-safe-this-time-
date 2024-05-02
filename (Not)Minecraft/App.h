#pragma once

#include<iostream>
#include<Windows.h>

#include<vector>
#include<stdint.h>
#include<cstdint>

#include"Mesh.h"

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
		const char* name;
	} config;
	struct collections {
	} collections;
public:
	App(uint16_t WIDTH, uint16_t HEIGHT, const char* name);
	App(uint16_t WIDTH, uint16_t HEIGHT, bool resizable, const char* name);
	App(uint16_t WIDTH, uint16_t HEIGHT, bool resizable, uint16_t V_WIDTH, uint16_t V_HEIGHT, const char* name);
	void draw();
	void de_instance();

	bool app_ShouldClose();
	void process_Entity();
};