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
	program_array[1]->set_uniform_mat4("projection", glm::perspective(fovy, aspect, zNear, zFar));

	/*----- VIEW MATRIX SETUP -----*/
	glm::mat4 view = main_camera->get_view_matrix();

	/*----- MODEL_VIEW MATRIX SETUP -----*/
	glm::mat4 mv = main_camera->get_view_matrix();

	program_array[0]->set_uniform_mat4("model_view", mv);
	program_array[1]->set_uniform_mat4("model_view", mv);
	
}