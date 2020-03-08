#include "..\Headers\particle_emitter_class.h"
#include "..\Headers\program_class.h"

particle_emitter firework;
extern Program firework_program;

//initialization of firework program
void init(){	
		
	/*Generating buffer for firework*/
	firework.generate_buffer();
	firework.generate_vao_buffer(0, 0, GL_FLOAT, 3);
	firework.generate_vao_buffer(1, firework.num_particles * sizeof(glm::vec3), GL_FLOAT, GL_RGBA);

	firework.enable_vao(0);
	firework.enable_vao(1);
};