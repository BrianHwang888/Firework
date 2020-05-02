#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stddef.h>

#include "..\Firework\init.h"
#include "..\Headers\shader_class.h"
#include "..\Headers\program_class.h"
#include "..\Headers\particle_emitter_class.h"
#include "..\Headers\Floor_class.h"
#include "..\Headers\render.h"
#include "..\Headers\camera.h"

void init_window(int option);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void keyboard_input_callback(GLFWwindow* window, int key, int scancode, int action, int mod);

void display_error_message(int code, const char* description);

camera* main_camera;

int main(){
	
	const char* err_description;
	int code, err = glfwInit();
	if (GLFW_FALSE ^ err) 
		code = glfwGetError(&err_description);

	printf("OpenGL version supported %s\n", glfwGetVersionString());
	/*----- Window Initialization; Definition found in init_window  -----*/
	init_window(3);

	/*----- Window Creation Definition found in init_window -----*/
	GLFWwindow* window = glfwCreateWindow(800, 600, "Firework", NULL, NULL);

	if (window == NULL) {
		printf("Failed to create window/n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	/* Setting window resize function; Definition found in init_window */
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	/* Setting keyboard callback function; Definition in init_window */
	glfwSetKeyCallback(window, keyboard_input_callback);

	/* GLAD Initialization (manages function pointers for OpenGL) */
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		printf("Failed to initialize GLAD");
		return -1;
	}

	/*----- SHADER INITIALIZATION -----*/
	Shader vertex("vertex_shader.glsl", GL_VERTEX_SHADER);
	Shader fragment("fragment_shader.glsl", GL_FRAGMENT_SHADER);
	//Shader vertex_firework("vFirework.glsl", GL_VERTEX_SHADER);
	//Shader fragment_firework("fFirework.glsl", GL_FRAGMENT_SHADER);

	/*----- PROGRAM INITIALIZATION -----*/
	Program basic_program(vertex.ID, fragment.ID);
	//Program firework_program(vertex_firework.ID, fragment_firework.ID);
	//Program* program_array[2] = { &basic_program, &firework_program };
	Program* program_array[1] = { &basic_program };

	/*----- RENDERING INITIALIZATION -----*/
	basic_program.link();
	//firework_program.link();

	/* CAMERA INITIALIZATION */
	main_camera = init_camera();

	/* RENDERING OBJECTS INITIALIZATION */
	particle_emitter* firework = init_particle_emitter(300);
	Floor* test_floor = init_floor();
	
	/* BUFFER GENERATION FOR RENDERING OBJECTS */
	init(program_array, firework, test_floor);

	while(!glfwWindowShouldClose(window)){

		//Rendering
		render(program_array, firework, test_floor, main_camera);

		//check and call events; then swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
		int error = glfwGetError(NULL);
		if (error != GLFW_NO_ERROR) {
			printf("Error: %d\n", error);
		}
	}

	glfwTerminate();
	return 0;
}

void display_error_message(int code, const char * description)
{
	printf("ERROR CODE: %d; %s", code, description);
};

//initialize window with specified option
void init_window(int option) {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, option);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, option);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);

}

/*----- PROCESS KEYBOARD INPUT -----*/
void keyboard_input_callback(GLFWwindow *window, int key, int scancode, int action, int mod) {

	switch (key)
	{
	case GLFW_KEY_ESCAPE:
		glfwSetWindowShouldClose(window, true);
	}

	main_camera->process_input(window, key);
}