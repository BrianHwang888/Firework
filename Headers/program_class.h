#ifndef PROGRAM_H
#define PROGRAM_H

#include "shader_class.h"

class Program {
	public:
		GLuint ID;
		Program();
		Program (GLuint vertex_shader_id, GLuint fragment_shader_id);
		void link();
		void use();

};

#endif