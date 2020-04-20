#ifndef FLOOR_H
#define FLOOR_H

#include <stdio.h>
#include <stddef.h>

#include <glm/common.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Floor {
	protected:
		glm::vec3* vertices;
		glm::vec4* colors;

		GLuint VBO;
		GLuint VAO;

		int vertex_count;
	public:
		Floor();
		Floor(const char* filename);
		void read_floor_file(const char* filename);
		void gen_buffer();
		void enable_vao(GLuint attrib_loc);
		void disable_vao(GLuint attrib_loc);
		void draw(GLuint program);
};

#endif