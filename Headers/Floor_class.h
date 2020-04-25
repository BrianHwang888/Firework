#ifndef FLOOR_H
#define FLOOR_H

#include <stdio.h>
#include <stddef.h>


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/common.hpp>

class Floor {
	protected:
		glm::vec3* vertices;
		glm::vec4* colors;

		GLuint floor_vertices_data;
		GLuint floor_fragment_data;
		GLuint VAO;
		GLuint VAO2;

		int vertex_count;
	public:
		Floor();
		Floor(const char* filename);

		void read_floor_file(const char* filename);
		void gen_buffer(GLuint program);
		void enable_vao(GLuint attrib_loc);
		void disable_vao(GLuint attrib_loc);
		void draw(GLuint program);
};

#endif