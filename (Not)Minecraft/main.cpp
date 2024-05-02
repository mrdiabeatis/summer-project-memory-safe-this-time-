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

	App app = App(1200, 800, "Minecrap"); // singleton for engine states

	Shader shader = Shader("DefaultVert.vert", "DefaultFrag.frag");
	Mesh mesh = Mesh(verts, ind, uvs, normals);
	
	while (!app.app_ShouldClose()) {
		glClearColor(0.122f, 0.140f, 0.221f, 1.000f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.activate();
		mesh.data.vao.activate();
		glDrawElements(GL_TRIANGLES, sizeof(i) / sizeof(i[0]), GL_UNSIGNED_INT, 0);
		mesh.data.vao.terminate();
		shader.terminate();

		app.draw();
	}
	
	mesh.de_instance();
	shader.de_instance();
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