#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include<stdio.h>
#include<stdlib.h>

class Shader {
	public:
		GLuint ID;
		Shader(const char* shader_file, GLenum shader_type);

	private:
		const char* filename;
		GLenum type;
		GLchar* source_file;
		
		char* read_shader_source(const char* filename);
	
};

#endif