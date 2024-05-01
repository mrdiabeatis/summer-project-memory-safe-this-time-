#include"Shader.h"

void throwErrors(unsigned int shader, const char* type);

Shader::Shader(const char* vertex, const char* fragment) {
	std::string vs = parseDataFromFile(vertex).c_str();
	vertexShaderSource = vs.c_str();
	std::string fs = parseDataFromFile(fragment).c_str();
	fragmentShaderSource = fs.c_str();

	if (vs != "")
		std::cout << "MSG::SHADER_FILES_LOADED\n";

	// create and compile vertexShader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	throwErrors(vertexShader, "VERTEX");

	// create and compile fragmentShader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	throwErrors(fragmentShader, "FRAGMENT");

	// create shaderProgram from shaders
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);

	glLinkProgram(ID);
	throwErrors(ID, "PROGRAM");

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	std::cout << "MSG::SHADER_CREATED\n";
}

void Shader::activate() {
	glUseProgram(ID);
}

void Shader::terminate() {
	glUseProgram(0);
}

void Shader::destroy() {
	std::cout << "MSG::SHADER_DESTROYED\n";
	glDeleteProgram(ID);
}

void throwErrors(unsigned int shader, const char* type) {
	GLint hasCompiled;
	char infoLog[1024];
	if (type != "PROGRAM") {
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE) {
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERR::SHADER_COMPILATION_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	} else {
		glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE) {
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERR::SHADER_LINKING_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
}