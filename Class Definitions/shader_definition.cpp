
#include "..\Headers\shader_class.h"

//Read source file
 char* Shader::read_shader_source(const char* filename){
	FILE* fp = fopen(filename, "r");
	long length;

	if(fp == NULL){ 
		fprintf(stderr, "Failed to read file %s\n", filename);
		exit(EXIT_FAILURE); 
	}
	
	fseek(fp, 0L, SEEK_END);
	length = ftell(fp);
	
	fseek(fp, 0L, SEEK_SET);
	char* buffer = new char[length + 1];
	buffer[length] = '\0';
	fclose(fp);

	return buffer;
};

//Shader constructor
Shader::Shader(const char* shader_file, GLenum shader_type) : filename(shader_file), type(shader_type){

	printf("Attempting to read: %s\n", filename);
	source_file = read_shader_source(filename);
	printf("Success\n");

	ID = glCreateShader(type);
	glShaderSource(ID, 1, (const GLchar**) &source_file, NULL);
	glCompileShader(ID);

	GLint compiled;
	glGetShaderiv( ID, GL_COMPILE_STATUS, &compiled);
	
	if(!compiled){
		fprintf(stderr, "%s failed to compile\n", filename);
		GLint log_size;
		glGetShaderiv(ID, GL_INFO_LOG_LENGTH, &log_size);
		char* log_msg = new char[log_size];
		glGetShaderInfoLog( ID, log_size, NULL, log_msg);
		fprintf(stderr, "Reason: %s\n", log_msg);
		delete [] log_msg;
		
		exit(EXIT_FAILURE);
	}
};

//destructor
Shader::~Shader(){
	glDeleteShader(ID);
	delete filename;
	delete [] source_file;

};

