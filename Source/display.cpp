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
	static GLfloat time = (GLfloat)glfwGetTime() - time;
	static int num_particles_discarded = 0;

	/*----- PROJECTION MATRIX SETUP -----*/
	program_array[1]->set_uniform_mat4("projection", glm::perspective(fovy, aspect, zNear, zFar));
	
	/*----- VIEW MATRIX SETUP -----*/
	program_array[1]->set_uniform_mat4("view", main_camera->get_view_matrix());
	
	/*----- MODEL_VIEW MATRIX SETUP -----*/
	for (int i = 0; i < firework->num_particles; i++) {
		
		//change displacement
		firework->particles[i].vertices.x += firework->particles[i].velocity.x * time;
		firework->particles[i].vertices.y += -0.00000049f * pow(time, 2) + firework->particles[i].velocity.y * time;
		firework->particles[i].vertices.z += firework->particles[i].velocity.z * time;
		
		//change y velocity
		firework->particles[i].velocity.y += -0.0098f * time;

		firework->particles[i].model_matrix = glm::translate(firework->particles[i].model_matrix, firework->particles[i].velocity * 0.01f);

		program_array[1]->set_uniform_mat4("model", firework->particles[i].model_matrix);
		firework->particles[i].draw();

		if (!(firework->particles[i].discarded) && firework->particles[i].vertices.y <= 0.0f) {
			num_particles_discarded++;
			firework->particles[i].discarded = true;
		}

		if (num_particles_discarded >= (firework->num_particles - 50)) {
			num_particles_discarded = 0;
			for (int i = 0; i < firework->num_particles; i++) {
				firework->particles[i].vertices = glm::vec3(0.0f, 0.1f, 0.0f);
				firework->particles[i].model_matrix = glm::mat4(1.0f);
				firework->particles[i].velocity = firework->part_velocity[i];
				firework->particles[i].discarded = false;
			}
			break;
		}
	}

}