#include"..\Headers\program_class.h"

Program::Program(GLuint vertex_shader_id, GLuint fragment_shader_id){
	ID = glCreateProgram();
	if (!(ID ^ 0)) {
		printf("Failed to create program using IDs: %d, %d\n", vertex_shader_id, fragment_shader_id);
		exit(EXIT_FAILURE);
	}
	glAttachShader(ID, vertex_shader_id);
	glAttachShader(ID, fragment_shader_id);
};

/*----- Program functions -----*/
//Link shader program
void Program::link(){
	GLint linked;
	glLinkProgram(ID);
	glGetProgramiv(ID, GL_LINK_STATUS, &linked);
	if (!linked) {
		printf("Shader program failed to link; ID: %d\n", ID);
		GLint log_size;
		glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &log_size);
		char* log_msg = new char[log_size];
		glGetProgramInfoLog(ID, log_size, NULL, log_msg);
		perror(log_msg);
		free(log_msg);
		system("pause");
		exit(EXIT_FAILURE);
	}
	printf("Successfully linked program ID: %d\n\n", ID);
};
//Use shader program
void Program::use(){
	glUseProgram(ID);
};

/*----- Set uniform variables -----*/
void Program::set_uniform_bool(const char* name, GLboolean &value) const {
	glUniform1i(glGetUniformLocation(ID, name), value);
};
void Program::set_uniform_int(const char* name, GLint &value) const {
	glUniform1i(glGetUniformLocation(ID, name), value);
}
void Program::set_uniform_float(const char* name, GLfloat &value) const {
	glUniform1f(glGetUniformLocation(ID, name), value);
}
void Program::set_uniform_double(const char* name, GLdouble &value) const {
	glUniform1d(glGetUniformLocation(ID, name), value);
}

/*----- Set unifrom vectors  -----*/
void Program::set_uniform_vec2(const char* name, const glm::vec2 &value) const {
	glUniform2fv(glGetUniformLocation(ID, name), 1, &value[0]);

}
void Program::set_uniform_vec3(const char* name, const glm::vec3 &value) const {
	glUniform3fv(glGetUniformLocation(ID, name), 1, &value[0]);

}
void Program::set_uniform_vec4(const char* name, const glm::vec4 &value) const {
	glUniform4fv(glGetUniformLocation(ID, name), 1, &value[0]);
}

/*----- Set uniform matrices -----*/
void Program::set_uniform_mat2(const char*name, const glm::mat2 &value) const {
	glUniformMatrix2fv(glGetUniformLocation(ID, name), 1, GL_FALSE, &value[0][0]);
}
void Program::set_uniform_mat3(const char* name, const glm::mat3 &value) const {
	glUniformMatrix3fv(glGetUniformLocation(ID, name), 1, GL_FALSE, &value[0][0]);
};
void Program::set_uniform_mat4(const char* name, const glm::mat4 &value) const {
	glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, &value[0][0]);
};