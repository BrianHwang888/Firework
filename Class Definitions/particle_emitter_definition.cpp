#include "..\Headers\particle_emitter_class.h"

//Definitions for particle_emitter class
particle_emitter::particle_emitter() {
	num_particles = 300;
	particles = new particle[300];
	model = glm::mat4(1.0f);
	part_vertices = new glm::vec3[300];
	part_color = new glm::vec4[300];
	part_velocities = new glm::vec3[300];

	for (int i = 0; i < num_particles; i++) {
		particles[i] = particle();
		part_vertices[i] = particles[i].vertices;
		part_color[i] = particles[i].color;
		part_velocities[i] = particles[i].velocity;
	}

	
};

particle_emitter::particle_emitter(int num_part){
	num_particles = num_part;
	particles = new particle[num_particles];
	part_vertices = new glm::vec3[num_particles];
	part_color = new glm::vec4[num_particles];
	part_velocities = new glm::vec3[num_particles];

	for (int i = 0; i < num_particles; i++) {
		particles[i] = particle();
		part_vertices[i] = particles[i].vertices;
		part_color[i] = particles[i].color;
		part_velocities[i] = particles[i].velocity;
	}

};

//Creates buffer holding firework data (vertices & color)
void particle_emitter::generate_buffer(GLuint program){

	glGenVertexArrays(1, &particle_vao);
	glGenBuffers(1, &particle_buffer);

	glBindVertexArray(particle_vao);
	glBindBuffer(GL_ARRAY_BUFFER, particle_buffer);
	glBufferData(GL_ARRAY_BUFFER, num_particles * (sizeof(glm::vec3) + sizeof(glm::vec4) + sizeof(glm::vec3)), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, num_particles * sizeof(glm::vec3), part_vertices);
	glBufferSubData(GL_ARRAY_BUFFER, num_particles * sizeof(glm::vec3), num_particles * sizeof(glm::vec4), part_color);
	glBufferSubData(GL_ARRAY_BUFFER, num_particles * (sizeof(glm::vec3) + sizeof(glm::vec4)), num_particles * sizeof(glm::vec3), part_velocities);

	GLuint vertex_position = glGetAttribLocation(program, "vPosition");
	enable_vao(vertex_position);
	glVertexAttribPointer(vertex_position, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);

	GLuint vertex_color = glGetAttribLocation(program, "vColor");
	enable_vao(vertex_color);
	glVertexAttribPointer(vertex_color, 4, GL_FLOAT, GL_FALSE, sizeof(glm::vec4), (void*)(num_particles * sizeof(glm::vec3)));
	
	GLuint vertex_velo = glGetAttribLocation(program, "vVelocity");
	enable_vao(vertex_velo);
	glVertexAttribPointer(vertex_velo, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)(num_particles * (sizeof(glm::vec3) + sizeof(glm::vec4))));
	glPointSize(5.0f);

};

void particle_emitter::enable_vao(int attrib_loc) {
	glEnableVertexAttribArray(attrib_loc);
};

void particle_emitter::disable_vao(int attrib_loc) {
	glDisableVertexAttribArray(attrib_loc);
}

void particle_emitter::Draw(GLuint program){
	glUseProgram(program);
	glBindVertexArray(particle_vao);
	glDrawArrays(GL_POINTS, 0, num_particles);
};
