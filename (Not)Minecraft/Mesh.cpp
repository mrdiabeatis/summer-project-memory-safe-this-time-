#include"Mesh.h"

Mesh::Mesh(std::vector<GLfloat>& positions, std::vector<GLuint>& indices, std::vector<GLfloat>& uvs, std::vector<GLfloat>& normals) {
	data.vao = VAO();
	data.vao.activate();

	VBO V_vbo(positions);
	V_vbo.activate();
	EBO ebo(indices);
	ebo.activate();

	data.vao.LinkAttrib(V_vbo, 0, 3, GL_FLOAT, 3 * sizeof(GL_FLOAT), (void*)0);
	//data.vao.LinkAttrib(UV_vbo, 1, 2, GL_FLOAT, 2 * sizeof(GL_FLOAT), (void*)0);
	//data.vao.LinkAttrib(N_vbo, 2, 3, GL_FLOAT, 3 * sizeof(GL_FLOAT), (void*)0);

	data.vao.terminate();
	V_vbo.terminate();
	ebo.terminate();

	std::cout << "MSG::MESH_CREATED\n";
}

void Mesh::de_instance(){ 
	if (data.vao.ID != NULL)
		glDeleteProgram(data.vao.ID);
	else
		throw;
	std::cout << "MSG::MESH_DESTROYED\n";
}