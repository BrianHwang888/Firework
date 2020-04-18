#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "..\Headers\firework_definition.h"
#include "..\Headers\shader_class.h"
#include "..\Headers\program_class.h"
#include "..\Headers\particle_emitter_class.h"
#include "..\Headers\Floor_class.h"

//OpenGL Programs
Program* basic_program;
Program* firework_program;

//Functions related to window
void init_window(int option);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
GLFWwindow* create_window(const char* name, int width, int height);

//Utility functions for OpenGL
void init();
void render();

//Rendering Objects
particle_emitter* firework;
Floor* test_floor;

int main(){

	glfwInit();
	
	/* Window Initialization */
	init_window(3);

	/* Window Creation */
	GLFWwindow* window = glfwCreateWindow(800, 600, "Firework", NULL, NULL);
	if (window == NULL) {
		printf("Failed to create window/n");
		system("pause");
		return NULL;
	}
	glfwMakeContextCurrent(window);

	/* GLAD Initialization (manages function pointers for OpenGL) */
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		std::cout<< "Failed to initialize GLAD" << std::endl;
		system("pause");
		return -1;
	}

	/* Viewport Initialization */
	glViewport(0, 0, 800, 600);
	
	/* Setting window resize function */
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	Shader vertex("vertex_shader.glsl", GL_VERTEX_SHADER);
	Shader fragment("fragment_shader.glsl", GL_FRAGMENT_SHADER);
	Shader vertex_firework("vFirework.glsl", GL_VERTEX_SHADER);
	Shader fragment_firework("fFirework.glsl", GL_FRAGMENT_SHADER);

	basic_program = new Program (vertex.ID, fragment.ID);
	firework_program = new Program (vertex_firework.ID, fragment_firework.ID);

	basic_program->link();
	firework_program->link();
	

	//delete &vertex;
	//delete &fragment;
	
	firework = new particle_emitter(300);
	test_floor = new Floor();

	init();

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
