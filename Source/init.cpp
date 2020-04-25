#include "..\Firework\init.h"


//initialization of rendering objects
void init(Program** program_array, particle_emitter* firework, Floor* floor) {
	
	/*Generating buffer for firework*/
	firework->generate_buffer();
	firework->generate_vao_buffer(0, 0, GL_FLOAT, 3);
	firework->generate_vao_buffer(1, firework->num_particles * sizeof(glm::vec3), GL_FLOAT, GL_RGBA);

	floor->gen_buffer(program_array[0]->ID);
}

