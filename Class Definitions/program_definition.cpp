#include "..\Headers\program_class.h"

Program::Program(GLuint vertex_shader_id, GLuint fragment_shader_id){
	ID = glCreateProgram();
	if (!(ID ^ 0)) {
		perror("Failed to create program");
		exit(EXIT_FAILURE);
	}
	glAttachShader(ID, vertex_shader_id);
	glAttachShader(ID, fragment_shader_id);
};


void Program::link(){
	GLint linked;
	glLinkProgram(ID);
	glGetProgramiv(ID, GL_LINK_STATUS, &linked);
	if (!linked) {
		perror("Shader program failed to link\n");
		GLint log_size;
		glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &log_size);
		char* log_msg = new char[log_size];
		glGetProgramInfoLog(ID, log_size, NULL, log_msg);
		perror(log_msg);
		free(log_msg);
		system("pause");
		exit(EXIT_FAILURE);
	}
	printf("Successfully linked program object\n\n");
};

void Program::use(){
	glUseProgram(ID);
};

