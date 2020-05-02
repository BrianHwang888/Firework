#ifndef __AXIES_H__
#define __AXIES_H__

#include<glad/glad.h>
#include<glfw/glfw3.h>
#include<glm/common.hpp>

class Axies {
public:
	Axies();

	void gen_buffer(GLuint program);
	void draw(GLuint program);
	void enable_vao(GLuint attrib_loc);
	void disable_vao(GLuint attrib_loc);

private:
	GLuint VAO;
	GLuint axies_vertices_data;
	GLuint axies_fragment_data;
	
	glm::vec3* vertices;
	glm::vec4* colors;
	
	int vertex_count;
};


#endif