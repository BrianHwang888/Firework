#include "..\Firework\init.h"


//initialization of rendering objects
void init(Program** program_array, particle_emitter* firework, Floor* floor, Axies* grid) {
	
	/*Generating buffer for firework*/
	firework->generate_buffer();
	firework->generate_vao_buffer(0, 0, GL_FLOAT, 3);
	firework->generate_vao_buffer(1, firework->num_particles * sizeof(glm::vec3), GL_FLOAT, GL_RGBA);

	floor->gen_buffer(program_array[0]->ID);
	grid->gen_buffer(program_array[0]->ID);
}

particle_emitter* init_particle_emitter(int num_particles) {
	return new particle_emitter(num_particles);
}

Floor* init_floor() {
	return new Floor();
}

camera* init_camera() {
	return new camera();
}

Axies* init_axies() {
	return new Axies();
}