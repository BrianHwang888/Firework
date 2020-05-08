#include "..\Firework\display.h"

//Setup projection and model_view matrix 
void display(Program** program_array, camera* main_camera) {

	GLfloat fovy = 45.0f;
	GLfloat aspect = 800.0f / 600.0f;
	GLfloat zNear = 0.5f;
	GLfloat zFar = 15.0f;
	GLfloat angle = 0.0f;

	/*----- PROJECTION MATRIX SETUP -----*/
	program_array[0]->set_uniform_mat4("projection", glm::perspective(fovy, aspect, zNear, zFar));
	

	/*----- VIEW MATRIX SETUP -----*/
	glm::mat4 view = main_camera->get_view_matrix();

	/*----- MODEL_VIEW MATRIX SETUP -----*/
	glm::mat4 mv = main_camera->get_view_matrix();

	/*----- UNIFORM VARIABLE SETUP -----*/
	program_array[0]->set_uniform_mat4("model_view", mv);
	
}

void display_particles(Program** program_array, camera* main_camera, particle_emitter* firework) {
	GLfloat fovy = 45.0f;
	GLfloat aspect = 800.0f / 600.0f;
	GLfloat zNear = 0.5f;
	GLfloat zFar = 15.0f;
	GLfloat angle = 0.0f;
	GLfloat time = (GLfloat)glfwGetTime();

	/*----- PROJECTION MATRIX SETUP -----*/
	program_array[1]->set_uniform_mat4("projection", glm::perspective(fovy, aspect, zNear, zFar));
	
	/*----- MODEL_VIEW MATRIX SETUP -----*/
	glm::mat4 mv = main_camera->get_view_matrix();

	/*for (int i = 0; i < firework->num_particles; i++) {
		firework->particles[i].velocity;

	}*/

	program_array[1]->set_uniform_mat4("model_view", mv);
	program_array[1]->set_uniform_float("time_elapsed", time);
}