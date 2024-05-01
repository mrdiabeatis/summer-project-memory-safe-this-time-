#include"ECS_Entity.h"

ECS_Entity::ECS_Entity(const char* name) {
	config.name = name;
	id = (void*)name;
	collections.ComponentsList.reserve(config.max_C);
}

void ECS_Entity::add_ECS_COMPONENT(void* t, uint16_t id) {
	std::vector<void*>::iterator e = collections.ComponentsList.begin();
	if (collections.ComponentsList.size() < config.max_C) {
		bool added = false;
		for (uint16_t i = 0; i < collections.ComponentsList.size(); i++) {
			if (collections.ComponentsList[i] == t)
				added = true;
		}
		if (!added)
			collections.ComponentsList.insert(e + id, t);
		else
			std::cout << "ERR::TRIED_TO_ADD_INVALID_COMPONENT" << std::endl;
	}
}

void ECS_Entity::remove_ECS_COMPONENT(void* t) {
	std::vector<void*>::iterator e = collections.ComponentsList.begin();
	bool added = false;
	for (uint16_t i = 0; i < collections.ComponentsList.size(); i++) {
		if (collections.ComponentsList[i] == t)
			added = true;
	}
	if (added) {
		for (uint16_t i = 0; i < collections.ComponentsList.size(); i++) {
			if (collections.ComponentsList[i] == t)
				collections.ComponentsList.erase(e + i);
		}
	}
	else
		std::cout << "ERR::TRIED_TO_REMOVE_NULL_COMPONENT_VOID_POINTER" << std::endl;
}

void* ECS_Entity::get_ECS_COMPONENT_VOID(uint16_t id) {
	if (id < collections.ComponentsList.size())
		return collections.ComponentsList.at(id);
	else
		throw;
}

void ECS_Entity::de_instance() {
	
}