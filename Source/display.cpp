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
	glm::mat4 model;

	for (int i = 0; i < firework->num_particles; i++) {
		glm::vec3 part_velo = firework->particles[i].velocity;
		glm::vec3 part_pos = firework->particles[i].vertices;
		glm::vec3 final_position = part_pos;
		model = firework->particles[i].model_matrix;
		float final_velocity_y = (float)(pow(-4.9, -10000000) * time + part_velo.y);

		final_position.y = (float)(pow(-4.9, -10000000) * time * time + part_velo.y * time * 0.001f + part_pos.y);
		final_position.x = part_velo.x * time * 0.001f + part_pos.x;
		final_position.z = part_velo.z * time * 0.001f + part_pos.z;

		
		
		firework->particles[i].vertices = final_position;
		model = glm::translate(model, part_velo);
		firework->particles[i].velocity.y = final_velocity_y;
		if (final_velocity_y <= 0)
			printf("REACHED HIGHEST POINT\n");
	}

	program_array[1]->set_uniform_mat4("model", model);
}