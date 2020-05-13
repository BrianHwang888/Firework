#include "..\Firework\init.h"

//initialization of rendering objects
void init(Program** program_array, particle_emitter* firework, Floor* floor, Axies* grid) {

	floor->gen_buffer(program_array[0]->ID);
	grid->gen_buffer(program_array[0]->ID);
	firework->generate_buffer(program_array[1]->ID);
	glClearColor(0.529f, 0.807f, 0.92f, 1.0f);
	glEnable(GL_DEPTH_TEST);
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