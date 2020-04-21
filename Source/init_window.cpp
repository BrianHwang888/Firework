#include "..\Headers\init_window.h"

//initialize window with specified option
void init_window(int option){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,  option);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, option);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
};


//return window* with specified width & height
GLFWwindow* create_window(const char* name, int width, int height) {
	GLFWwindow* window = glfwCreateWindow(width, height, name, NULL, NULL);
	
	return window;
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);

}

//Closes window when "ESC" key pressed
void processInput(GLFWwindow *window){
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}