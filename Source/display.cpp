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
	
	/*----- VIEW MATRIX SETUP -----*/
	program_array[1]->set_uniform_mat4("view", main_camera->get_view_matrix());
	
	/*----- MODEL_VIEW MATRIX SETUP -----*/
	for (int i = 0; i < firework->num_particles; i++) {

		////change displacement
		firework->particles[i].vertices.x += firework->particles[i].velocity.x * time;
		firework->particles[i].vertices.y += pow(-4.9f, -1000000) * pow(time, 2) + firework->particles[i].velocity.y * time;
		firework->particles[i].vertices.z += firework->particles[i].velocity.z * time;
		
		//change y velocity
		firework->particles[i].velocity.y += pow(-9.8f, -10000000) * time;

		firework->particles[i].model_matrix = glm::translate(firework->particles[i].model_matrix, firework->particles[i].velocity * 0.001f);

		program_array[1]->set_uniform_mat4("model", firework->particles[i].model_matrix);
		firework->particles[i].draw();
	}
}