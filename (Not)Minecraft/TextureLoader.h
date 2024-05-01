#pragma once

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>

GLuint loadTextureFromFile(const char* fname, GLenum filterMode, bool mipmap, GLenum BANK);
void destroyTexture(GLuint ID);
