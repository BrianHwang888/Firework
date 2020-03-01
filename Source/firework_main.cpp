#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "..\Headers\firework_definition.h"
#include "..\Headers\shader_class.h"
#include "..\Headers\program_class.h"
#include "..\Headers\particle_emitter_class.h"

//Functions related to window
void init_window(int option);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInout(GLFWwindow* window);
GLFWwindow* create_window(const char* name, int width, int height);

//Utility functions for OpenGL
void init();
void render();

int main(){

	glfwInit();
	
	/* Window Initialization */
	init_window(3);

	/* Window Creation */
	GLFWwindow* window = create_window("Firework", 800, 600);
	glfwMakeContextCurrent(window);

	/* GLAD Initialization (manages function pointers for OpenGL) */
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		std::cout<< "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	/* Viewport Initialization */
	glViewport(0, 0, 800, 600);
	
	/* Setting window resize function */
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	Shader vertex("vertex shader path", GL_VERTEX_SHADER);
	Shader fragment("fragment shader path", GL_FRAGMENT_SHADER);
	
	Program firework_program(vertex.ID, fragment.ID);
	firework_program.link();
	

	delete &vertex;
	delete &fragment;
	
	particle_emitter firework(300);

	init();
	firework_program.use();

	while(!glfwWindowShouldClose(window)){

		//Process inputs
		processInput(window);

		//Rendering
		render();

		//check and call events; then swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, height);

}

//Closes window when "ESC" key pressed
void processInput(GLFWwindow* window){
	if(glfwGetKey(window, GLFW_KEY_ESCAPE == GLFW_PRESS)){
		glfwSetWindowShouldClose(window, true);
	}
}
