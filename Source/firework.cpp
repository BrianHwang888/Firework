#include "Firework_definitions.h"

GLuint Angel::InitShader(const char* vShaderFile, const char* fShaderFile);

GLuint firework_program;


void particle(){
	for(int i = 0; i < 300; i++){
		particle_vertices[i] = vec3(0.0f, 0.1f, 0.0f);
		particle_velocities[i] = vec3(2.0 * ((rand() % 256) / 256.0 - 0.5), 1.2 * 2.0 * ((rand() % 256) / 256.0), 2.0 * ((rand() % 256) / 256.0 - 0.5));
		particle_colors[i] = color4((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, 1.0);
	}	
}


/*--------------------OPENGL INITALIZATION--------------------*/
void init(){}

void display(){}
