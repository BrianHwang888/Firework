#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/common.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "..\Headers\program_class.h"

//program used 
extern Program* basic_program;
extern Program* firework_program;

extern GLuint model_view; //model-view matrix uniform shader variable location
extern GLuint projection; //projection matrix uniform shader variable location

//Projection transformation parameters
extern GLfloat fovy;
extern GLfloat aspect;
extern GLfloat zNear, zFar;
extern GLfloat angle;

//initial camera position
extern glm::vec4 init_eye;
extern glm::vec4 eye;

//axis constants; for utiliy perposes 
extern glm::vec3 origin;
extern glm::vec3 x_axis;
extern glm::vec3 y_axis;
extern glm::vec3 z_axis;

void display(void);

#endif // !__DISPLAY_H__

