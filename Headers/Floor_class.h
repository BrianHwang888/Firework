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
		GLuint floor_buffer;
		GLuint VAO;
		GLuint EBO;
		
		unsigned int* indices;
		int num_polygons;
		
		void gen_buffer();
		void gen_vao_buffer();
		void gen_ebo();

	public:
		Floor();
		Floor(const char* filename);
		void read_floor_file(const char* filename);

};

class floor
{
public:
	floor();
	~floor();
};

#endif