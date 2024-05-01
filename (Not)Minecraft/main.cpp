#include"App.h"

// mostly temp

GLfloat v[] = {
	-0.5f,-0.5f,0,
	-0.5f,0.5f,0,
	0.5f,0.5f,0,
	0.5f,-0.5f,0,
};

GLfloat u[] = {
	0.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	1.0f, 0.0f
};

GLuint i[] = {
	0, 2, 1,
	0, 3, 2
};

GLfloat n[] = {
	0,1,0,
	0,1,0,
	0,1,0,
	0,1,0
};

int main() {
	std::vector<GLfloat> verts(v, v + sizeof(v) / sizeof(GLfloat));
	std::vector<GLuint> ind(i, i + sizeof(i) / sizeof(GLuint));
	std::vector<GLfloat> uvs(u, u + sizeof(u) / sizeof(GLfloat));
	std::vector<GLfloat> normals(n, n + sizeof(n) / sizeof(GLfloat));

	App app = App(1200, 800); // singleton for engine states
	
	ECS_Entity ecs_Entity = ECS_Entity("test entity");

	ecs_Entity.add_ECS_COMPONENT(create_ECS_Shader("DefaultVert.vert", "DefaultFrag.frag"), ECS_Shader_ID);
	ecs_Entity.add_ECS_COMPONENT(create_ECS_Model(Mesh(verts, ind, uvs, normals), loadTextureFromFile("TEST_UV.png", GL_NEAREST, false, 0)), ECS_Model_ID);
	ecs_Entity.add_ECS_COMPONENT(create_ECS_Transform(glm::vec3(0,0,0), glm::vec3(0,0,0), glm::vec3(0,0,0)), ECS_Transform_ID);
	
	while (!app.app_ShouldClose()) {
		// ECS system test
		// note::in order to refrence individual entity components a type cast from a void* is required for now
		glClearColor(0.122f, 0.140f, 0.221f, 1.000f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		static_cast<ECS_Shader*>(ecs_Entity.get_ECS_COMPONENT_VOID(ECS_Shader_ID))->activate();
		static_cast<ECS_Model*>(ecs_Entity.get_ECS_COMPONENT_VOID(ECS_Model_ID))->mesh.data.vao.activate();
		glDrawElements(GL_TRIANGLES, sizeof(i) / sizeof(i[0]), GL_UNSIGNED_INT, 0);
		static_cast<ECS_Model*>(ecs_Entity.get_ECS_COMPONENT_VOID(ECS_Model_ID))->mesh.data.vao.terminate();
		static_cast<ECS_Shader*>(ecs_Entity.get_ECS_COMPONENT_VOID(ECS_Shader_ID))->terminate();

		app.process_Entity(&ecs_Entity); 
		app.draw();
	}


	ecs_Entity.de_instance();
	app.de_instance();
	return 0;
}

// Put in mesh class

/*
Shader shader("DefaultVert.vert", "DefaultFrag.frag");
shader.terminate();

VAO vao;
vao.activate();

VBO V_vbo(verts);
V_vbo.activate();
EBO ebo(ind);
ebo.activate();

vao.LinkAttrib(V_vbo, 0, 3, GL_FLOAT, 3 * sizeof(GL_FLOAT), (void*)0);
vao.LinkAttrib(V_vbo, 1, 2, GL_FLOAT, 2 * sizeof(GL_FLOAT), (void*)0);

vao.terminate();
V_vbo.terminate();
ebo.terminate();
*/

/*
// draw calls and such
shader.activate();
vao.activate();
glDrawElements(GL_TRIANGLES, sizeof(i) / sizeof(i[0]), GL_UNSIGNED_INT, 0);
vao.terminate();
shader.terminate();
*/

/*
vao.destroy();
V_vbo.destroy();
ebo.destroy();
*/