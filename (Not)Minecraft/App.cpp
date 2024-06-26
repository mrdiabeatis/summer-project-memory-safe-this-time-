#include"App.h"

void initContext(uint16_t v, bool r);
GLFWwindow* initWindow(uint16_t x, uint16_t y, const char* name);

void App::pre_render() {

}

void App::post_render() {
	glfwSwapBuffers(config.window);
	glfwPollEvents();
}

void App::render() {
	// draw calls and such :)
}

App::App(uint16_t WIDTH, uint16_t HEIGHT, const char* name) {
	config.WIDTH = WIDTH;
	config.HEIGHT = HEIGHT;
	config.resizable = false;
	config.V_WIDTH = WIDTH;
	config.V_HEIGHT = HEIGHT;
	config.name = name;
	initContext(3, config.resizable);
	config.window = initWindow(config.WIDTH, config.HEIGHT, name);
}

App::App(uint16_t WIDTH, uint16_t HEIGHT, bool resizable, const char* name) {
	config.WIDTH = WIDTH;
	config.HEIGHT = HEIGHT;
	config.resizable = resizable;
	config.V_WIDTH = WIDTH;
	config.V_HEIGHT = HEIGHT;
	config.name = name;
	initContext(3, config.resizable);
	config.window = initWindow(config.WIDTH, config.HEIGHT, name);
}

App::App(uint16_t WIDTH, uint16_t HEIGHT, bool resizable, uint16_t V_WIDTH, uint16_t V_HEIGHT, const char* name) {
	config.WIDTH = WIDTH;
	config.HEIGHT = HEIGHT;
	config.resizable = resizable;
	config.V_WIDTH = V_WIDTH;
	config.V_HEIGHT = V_HEIGHT;
	config.name = name;
	initContext(3, config.resizable);
	config.window = initWindow(config.WIDTH, config.HEIGHT, name);
}

void App::draw() {
	pre_render();
	render();
	post_render();
}

void App::de_instance() {
	glfwDestroyWindow(config.window);
	glfwTerminate();
}

bool App::app_ShouldClose() {
	return glfwWindowShouldClose(config.window);
}

void App::process_Entity() {
	// add entitiy to entity vector
}

void initContext(uint16_t v, bool r) {
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, v);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, v);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, false);
	std::cout << "MSG::OPENGL_CONTEXT_CREATED\n";
}

GLFWwindow* initWindow(uint16_t x, uint16_t y, const char* name) {
	GLFWwindow* window = glfwCreateWindow(1200, 800, name, NULL, NULL);
	if (window == NULL || !glfwInit())
		throw std::invalid_argument("ERR::WINDOW_CREATION_FAILED::(WINDOW*_RETURNS_NULLPTR)\n");
	glfwMakeContextCurrent(window);
	std::cout << "MSG::MAIN_WINDOW_CREATED\n";
	gladLoadGL();
	glViewport(0, 0, 1200, 800);
	glEnable(GL_DEPTH_TEST);
	std::cout << "MSG::MAIN_VIEWPORT_CREATED\n";
	return window;
}