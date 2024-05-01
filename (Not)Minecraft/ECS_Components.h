#pragma once

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include<vector>
#include<stdint.h>
#include<cstdint>

#include"Mesh.h"

class ECS_Shader {
public:
	ECS_Shader(const char* vertex, const char* fragment);

	Shader shader = *(Shader*)calloc(1, sizeof(Shader));

	void activate();
	void terminate();
	void de_instance();
};
ECS_Shader* create_ECS_Shader(const char* vertex, const char* fragment);
unsigned const int ECS_Shader_ID = 0;

class ECS_Transform {
public:
	ECS_Transform(glm::vec3 positon, glm::vec3 rotation, glm::vec3 scale);

	glm::vec3 position = glm::vec3(0.0, 0.0, 0.0);
	glm::vec3 rotation = glm::vec3(0.0, 0.0, 0.0);
	glm::vec3 scale = glm::vec3(0.0, 0.0, 0.0);

	void Move(glm::vec3 dir, float mag);
	void Rotate(glm::vec3 dir, float mag);
};
ECS_Transform* create_ECS_Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);
unsigned const int ECS_Transform_ID = 1;

class ECS_Model {
public:
	ECS_Model(Mesh mesh, GLuint texture0);

	GLuint texture0 = NULL;
	Mesh mesh = *(Mesh*)calloc(1, sizeof(Mesh));
};
ECS_Model* create_ECS_Model(Mesh mesh, GLuint texture0);
unsigned const int ECS_Model_ID = 2;