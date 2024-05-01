#pragma once

#include"ECS_Components.h"

class ECS_Entity {
private:
	struct config {
		const char* name;
		const unsigned int max_C = 64;
	} config;
	struct collections {
		std::vector<void*> ComponentsList;
	} collections;
public:
	void* id;
	ECS_Entity(const char* name);

	void add_ECS_COMPONENT(void* t, uint16_t id);
	void remove_ECS_COMPONENT(void* t);
	void* get_ECS_COMPONENT_VOID(uint16_t id);

	void de_instance();
};