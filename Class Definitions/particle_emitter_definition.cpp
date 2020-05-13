#include "..\Headers\particle_emitter_class.h"
#include<stdio.h>
//Definitions for particle_emitter class
particle_emitter::particle_emitter() {
	num_particles = 300;
	particles = new particle[300];
	part_velocity = new glm::vec3[300];

	for (int i = 0; i < num_particles; i++) 
		part_velocity[i] = particles[i].velocity;
	
};

particle_emitter::particle_emitter(int num_part){
	num_particles = num_part;
	particles = new particle[num_particles];
	part_velocity = new glm::vec3[num_particles];

	for (int i = 0; i < num_particles; i++) 
		part_velocity[i] = particles[i].velocity;

};

//Creates buffer holding firework data (vertices & color)
void particle_emitter::generate_buffer(GLuint program){
	for (int i = 0; i < num_particles; i++) 
		particles[i].generate_buffer(program);
	glPointSize(5.0f);
};
