#include"ECS_Components.h"

// Shader
ECS_Shader::ECS_Shader(const char* vertex, const char* fragment) {
	if (vertex != nullptr && fragment != nullptr) 
		this->shader = Shader(vertex, fragment);
	this->shader.terminate();
}

void ECS_Shader::activate() {
	this->shader.activate();
}

void ECS_Shader::terminate() {
	this->shader.terminate();
}

void ECS_Shader::de_instance() {
	this->shader.destroy();
}

ECS_Shader* create_ECS_Shader(const char* vertex, const char* fragment) {
	ECS_Shader sO = ECS_Shader(vertex, fragment);
	ECS_Shader* s = &sO;
	return s;
}

// Transform...
ECS_Transform::ECS_Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) {
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;	
}

void ECS_Transform::Move(glm::vec3 dir, float mag) {
	this->position += dir * mag;
}

void ECS_Transform::Rotate(glm::vec3 dir, float mag) {
	this->rotation += dir * mag;
}

ECS_Transform* create_ECS_Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) {
	ECS_Transform tO = ECS_Transform(position, rotation, scale);
	ECS_Transform* t = &tO;
	return t;
}

// Model...
ECS_Model::ECS_Model(Mesh mesh, GLuint texture0) {
	this->mesh = mesh;
	this->texture0 = texture0;
}

ECS_Model* create_ECS_Model(Mesh mesh, GLuint texture0) {
	ECS_Model mO = ECS_Model(mesh, texture0);
	ECS_Model* m = &mO;
	return m;
}