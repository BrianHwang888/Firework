#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "..\Firework\init.h"
#include "..\Headers\init_window.h"
#include "..\Headers\shader_class.h"
#include "..\Headers\program_class.h"
#include "..\Headers\particle_emitter_class.h"
#include "..\Headers\Floor_class.h"
#include "..\Headers\render.h"

int main(){

	/* Window Initialization; Definition found in init_window */
	init_window(3);

	/* Window Creation Definition found in init_window*/
	//GLFWwindow* window = glfwCreateWindow(800, 600, "Firework", NULL, NULL);
	GLFWwindow* window = create_window("Firework", 800, 600);
	if (window == NULL) {
		printf("Failed to create window/n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	/* Setting window resize function; Definition found in init_window */
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	/* GLAD Initialization (manages function pointers for OpenGL) */
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		printf("Failed to initialize GLAD");
		return -1;
	}

	/* SHADER INITIALIZATION */
	//Shader vertex("vertex_shader.glsl", GL_VERTEX_SHADER);
	//Shader fragment("fragment_shader.glsl", GL_FRAGMENT_SHADER);
	//Shader vertex_firework("vFirework.glsl", GL_VERTEX_SHADER);
	//Shader fragment_firework("fFirework.glsl", GL_FRAGMENT_SHADER);

	///* PROGRAM INITIALIZATION */
	//Program basic_program(vertex.ID, fragment.ID);
	//Program firework_program(vertex_firework.ID, fragment_firework.ID);

	///* RENDERING INITIALIZATION */
	//basic_program.link();
	//firework_program.link();

	/* Objects to be rendered*/
	//particle_emitter firework(300);
	//Floor test_floor;

	while(!glfwWindowShouldClose(window)){

		//Process inputs
		processInput(window);

		//Rendering
		//render(&basic_program, &firework_program);

		//check and call events; then swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
