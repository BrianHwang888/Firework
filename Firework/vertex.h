#ifndef __VERTEX_H__
#define __VERTEX_H__

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/common.hpp>

struct vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec4 color;

};

#endif // !__VERTEX_H__
