#include "..\Headers\particle_class.h"
#include<stdio.h>

//Definitions for particle class
particle::particle() {
	vertices = glm::vec3(0.0f, 0.1f, 0.0f);
	velocity = glm::vec3(2.0f * ((rand() % 256) / 256.0f - 0.5f), 1.2 * 2.0 * ((rand() % 256) / 256.0), 2.0 * ((rand() % 256) / 256.0f - 0.5f));
	color = glm::vec4((float) rand() / RAND_MAX, (float) rand() / RAND_MAX, (float) rand() / RAND_MAX, 1.0f);
	model_matrix = glm::mat4(1.0f);
};	

particle::particle(glm::vec3 pos, glm::vec3 velo, glm::vec4 part_color):vertices(pos),velocity(velo),color(part_color){ model_matrix = glm::mat4(1.0f);  };

void particle::generate_buffer(GLuint program) {

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &particle_buffer);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, particle_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) + sizeof(glm::vec4), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(glm::vec3), &vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(glm::vec3), sizeof(glm::vec4), &color);

	GLuint vertex_position = glGetAttribLocation(program, "vPosition");
	enable_vao(vertex_position);
	glVertexAttribPointer(vertex_position, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);

	GLuint vertex_color = glGetAttribLocation(program, "vColor");
	enable_vao(vertex_color);
	glVertexAttribPointer(vertex_color, 4, GL_FLOAT, GL_FALSE, sizeof(glm::vec4), (void*)(sizeof(glm::vec3)));
	
}

void particle::enable_vao(int attrib_loc) {
	glEnableVertexAttribArray(attrib_loc);
}

void particle::disable_vao(int attrib_loc) {
	glDisableVertexAttribArray(attrib_loc);
}

void particle::draw() {
	glBindVertexArray(VAO);
	glDrawArrays(GL_POINTS, 0, 1);
}