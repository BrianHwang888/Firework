#include "..\Firework\display.h"

GLfloat fovy = 45.0f;
GLfloat aspect = 800.0f / 600.0f;
GLfloat zNear = 0.5f;
GLfloat zFar = 15.0f;
GLfloat angle = 0.0f;

glm::vec3 origin = glm::vec3(0.0f, 0.02f, 0.0f);
glm::vec3 x_axis = glm::vec3(10.0f, 0.02f, 0.0f);
glm::vec3 y_axis = glm::vec3(0.0f, 10.02f, 0.0f);
glm::vec3 z_axis = glm::vec3(0.0f, 0.02f, 10.0f);

//Setup projection and model_view matrix 
void display(Program** program_array, camera* main_camera) {
	/*----- PROJECTION MATRIX SETUP -----*/
	program_array[0]->set_uniform_mat4("projection", glm::perspective(fovy, aspect, zNear, zFar));

	/*----- MODEL_VIEW MATRIX SETUP -----*/
	glm::mat4 mv = main_camera->view_matrix;

	mv = glm::rotate(mv, (float)glfwGetTime(), glm::vec3(1.0f, 0.0f, 0.0f));
	mv = glm::scale(mv, glm::vec3(0.5f, 0.5f, 0.5f));

	program_array[0]->set_uniform_mat4("model_view", mv);

	//glUniformMatrix4fv(projection, 1, GL_FALSE, glm::value_ptr(p));
	//
	////model_view matrix setup
	//glm::vec4 at(0.0f, 0.0f, 0.0f, 1.0f);
	//glm::vec4 up(0.0f, 1.0f, 0.0f, 0.0f);
	//glm::mat4 mv = glm::lookAt((glm::vec3)eye, (glm::vec3)at, (glm::vec3)up);
	//glDepthMask(GL_FALSE);
	//glUniformMatrix4fv(model_view, 1, GL_TRUE, glm::value_ptr(mv));
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	
}