#ifndef PROGRAM_H
#define PROGRAM_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>

#include<stdio.h>
#include<stdlib.h>


class Program {
	public:
		GLuint ID;
		Program (GLuint vertex_shader_id, GLuint fragment_shader_id);

		/*----- Program functions ------*/
		void link();
		void use();

		/*----- Set uniform variables -----*/
		void set_uniform_bool(const char* name, GLboolean &value) const;
		void set_uniform_int(const char* name, GLint &value) const;
		void set_uniform_float(const char* name, GLfloat &value) const;
		void set_uniform_double(const char* name, GLdouble &value) const;

		/*----- set uniform vectors -----*/
		void set_uniform_vec2(const char* name, const glm::vec2 &value) const;
		void set_uniform_vec3(const char* name, const glm::vec3 &value) const;
		void set_uniform_vec4(const char* name, const glm::vec4 &value) const;
		
		/*----- set uniform matrices ----*/
		void set_uniform_mat2(const char* name, const glm::mat2 &value) const;
		void set_uniform_mat3(const char* name, const glm::mat3 &value) const;
		void set_uniform_mat4(const char* name, const glm::mat4 &value) const;
};

#endif