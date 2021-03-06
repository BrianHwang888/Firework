#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stddef.h>

#include "..\Firework\init.h"
#include "..\Headers\shader_class.h"
#include "..\Headers\program_class.h"
#include "..\Headers\particle_emitter_class.h"
#include "..\Headers\Floor_class.h"
#include "..\Headers\axis.h"
#include "..\Headers\render.h"
#include "..\Headers\camera.h"

void init_window(int option);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void keyboard_input_callback(GLFWwindow* window, int key, int scancode, int action, int mod);
void mouse_input_callback(GLFWwindow* window, double x_pos, double y_pos);

void display_error_message(int code, const char* description);

camera* main_camera;
Axies* grid;

bool first_mouse = true;
float last_x = 400.0f, last_y = 300.0f;
float yaw = -90.0f;
float pitch = 0.0f;

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
	glfwSetCursorPosCallback(window, mouse_input_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	/* GLAD Initialization (manages function pointers for OpenGL) */
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		printf("Failed to initialize GLAD");
		return -1;
	}

	/*----- SHADER INITIALIZATION -----*/
	Shader vertex("vertex_shader.glsl", GL_VERTEX_SHADER);
	Shader fragment("fragment_shader.glsl", GL_FRAGMENT_SHADER);
	Shader vertex_firework("vFirework.glsl", GL_VERTEX_SHADER);
	Shader fragment_firework("fFirework.glsl", GL_FRAGMENT_SHADER);

	/*----- PROGRAM INITIALIZATION -----*/
	Program basic_program(vertex.ID, fragment.ID);
	Program firework_program(vertex_firework.ID, fragment_firework.ID);
	Program* program_array[2] = { &basic_program, &firework_program };

	/*----- RENDERING INITIALIZATION -----*/
	basic_program.link();
	firework_program.link();

	/* CAMERA INITIALIZATION */
	main_camera = init_camera();

	/* RENDERING OBJECTS INITIALIZATION */
	particle_emitter* firework = init_particle_emitter(300);
	Floor* test_floor = init_floor();
	grid = init_axies();

	/* BUFFER GENERATION FOR RENDERING OBJECTS */
	init(program_array, firework, test_floor, grid);

	while(!glfwWindowShouldClose(window)){

		//Rendering
		render(program_array, firework, test_floor, main_camera, grid);

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
	printf("ERROR CODE: %d;\n%s", code, description);
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
	static GLfloat init_time = 0;
	GLfloat delta_time = 0;
	GLfloat current_time = glfwGetTime();
	switch (key)
	{
	case GLFW_KEY_ESCAPE:
		glfwSetWindowShouldClose(window, true);
	}

	delta_time = current_time - init_time;
	init_time = current_time;
	main_camera->process_input(window, key, action, mod, delta_time);
}

void mouse_input_callback(GLFWwindow* window, double x_pos, double y_pos) {
	if (first_mouse) {
		last_x = x_pos;
		last_y = y_pos;
		first_mouse = false;
	}

	float x_offset = x_pos - last_x;
	float y_offset = last_y - y_pos;

	last_x = x_pos;
	last_y = y_pos;

	main_camera->process_mouse(x_offset, y_offset);

}