#ifndef PROGRAM_H
#define PROGRAM_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include<stdio.h>
#include<stdlib.h>


class Program {
	public:
		GLuint ID;
		Program (GLuint vertex_shader_id, GLuint fragment_shader_id);
		void link();
		void use();

};

#endif