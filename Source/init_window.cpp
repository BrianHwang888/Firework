#include <stdio.h>
#include <GLFW/glfw3.h>

//initialize window with specified option
void init_window(int option){
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,  option);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, option);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
};

//return window* with specified width & height
GLFWwindow* create_window(char* name, int width, int height){
	GLFWwindow* window = glfwCreateWindow(width, height, name, NULL, NULL);
	if(window == NULL){
		printf("Failed to create window/n");
		return NULL;
	}	
	return window;
};

