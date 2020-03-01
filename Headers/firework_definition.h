/* Definitons for Firework animation */

#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>

//Projection tranformation parameters
GLfloat fovy = 45.0f; //Field of view in Y direction angle (in degrees)
GLfloat aspect; //Viewport aspect ration
GLfloat zNear = 0.5f, zFar = 15.0f;


GLfloat angle = 0.0f; //rotation angle (in degrees)
glm::vec4 init_eye(7.0f, 3.0f, -10.0f, 1.0f); //Init. camera position
//vec4 init_eye(-1.0f, 6.0f, -4.0f, 1.0f); alternative init position
glm::vec4 eye = init_eye;

glm::vec3 origin (0.0f, 0.02f, 0.0f); //origin point

//data for all particles
GLuint particle_buffer;