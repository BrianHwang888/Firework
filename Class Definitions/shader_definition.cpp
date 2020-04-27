#include "..\Headers\shader_class.h"

//Read source file
char* Shader::read_shader_source(const char* filename){
	FILE* fp;
	errno_t err = fopen_s(&fp, filename, "r");
	long length;

	if(fp == NULL){ 
		fprintf(stderr, "Failed to read file %s\n", filename);
		system("pause");
		exit(EXIT_FAILURE); 
	}
	printf("Successfully read %s\n", filename);
	fseek(fp, 0L, SEEK_END);
	length = ftell(fp);
	
	fseek(fp, 0L, SEEK_SET);
	char* buffer = new char[length + 1];
	fread(buffer, 1, length, fp);
	buffer[length] = '\0';
	fclose(fp);

	for (int i = 0; i < length + 1; i++)
	{
		if (!(buffer[i] >= 0 && buffer[i] < 128))
			buffer[i] = ' ';
	}

	return buffer;
};

//Shader constructor
Shader::Shader(const char* shader_file, GLenum shader_type) : filename(shader_file), type(shader_type){

	printf("Attempting to read: %s\n", filename);
	source_file = read_shader_source(filename);

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
		system("pause");
		exit(EXIT_FAILURE);
	}
	
	printf("Successfully compiled %s\n\n", filename);

	delete[] source_file;
};
