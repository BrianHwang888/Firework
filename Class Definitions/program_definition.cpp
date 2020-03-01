#include "..\Headers\program_class.h"

Program::Program(GLuint vertex_shader_id, GLuint fragment_shader_id){
	ID = glCreateProgram();
	glAttachShader(ID, vertex_shader_id);
	glAttachShader(ID, fragment_shader_id);
};


void Program::link(){
	glLinkProgram(ID);
};

void Program::use(){
	glUseProgram(ID);
};

