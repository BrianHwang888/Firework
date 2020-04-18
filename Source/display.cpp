#include "..\Firework\display.h"

GLuint model_view;
GLuint projection;

GLfloat fovy = 45.0f;
GLfloat aspect;
GLfloat zNear = 0.5f;
GLfloat zFar = 15.0f;
GLfloat angle = 0.0f;

glm::vec4 init_eye = glm::vec4(7.0f, 3.0f, -10.0f, 1.0f);
glm::vec4 eye = init_eye;

glm::vec3 origin = glm::vec3(0.0f, 0.02f, 0.0f);
glm::vec3 x_axis = glm::vec3(10.0f, 0.02f, 0.0f);
glm::vec3 y_axis = glm::vec3(0.0f, 10.02f, 0.0f);
glm::vec3 z_axis = glm::vec3(0.0f, 0.02f, 10.0f);

void display(void) {

	model_view = glGetUniformLocation(basic_program->ID, "model_view");
	projection = glGetUniformLocation(basic_program->ID, "projection");
	
	glm::mat4 p = glm::perspective(fovy, aspect, zNear, zFar);
	glUniformMatrix4fv(projection, 1, GL_FALSE, glm::value_ptr(p));
}