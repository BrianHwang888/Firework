#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void init_window(int option);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void keyboard_input_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

#endif // !__WINDOW_H__
