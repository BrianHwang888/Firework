#include "..\Headers\particle_emitter_class.h"

//Definitions for particle_emitter class
particle_emitter::particle_emitter() {
	num_particles = 300;
	particles = new particle[300];

	for(int i = 0; i < num_particles; i++)
		particles[i] = particle();
	
		
};

particle_emitter::particle_emitter(int num_part){
	num_particles = num_part;
	particles = new particle[num_particles];
	
	for(int i = 0; i < num_particles;i++)
		particles[i] = particle();

};

//Creates buffer holding firework data (vertices & color)
void particle_emitter::generate_buffer(){
	glm::vec3 part_vertices[300];
	glm::vec4 part_color[300];

	glGenBuffers(1, &(particle_buffer));
	glBindBuffer(GL_ARRAY_BUFFER, particle_buffer);

	glBufferData(GL_ARRAY_BUFFER, num_particles * (sizeof(glm::vec3) + sizeof(glm::vec4)), NULL, GL_STATIC_DRAW);
	
	for(int i = 0; i < num_particles; i++){
		part_vertices[i] = particles[i].vertices;					part_color[i] = particles[i].color;
	}
	glBufferSubData(GL_ARRAY_BUFFER, 0,sizeof(part_vertices), &part_vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(part_vertices), sizeof(&part_vertices) + sizeof(part_color), part_color);
};

void particle_emitter::Draw(){};

void particle_emitter::Update(){};
