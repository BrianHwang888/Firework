/*---------------PARTICLE EMITTER CLASS---------------*/

#ifndef PARTICLE_EMITTER_H
#define PARTICLE_EMITTER_H

#include "particle_class.h"

class particle_emitter {
public:
	int num_particles;
	particle* particles;
	glm::mat4 model;

	glm::vec3* part_vertices;
	glm::vec4* part_color;

	//buffers to hold particles attributes
	GLuint particle_buffer;
	particle_emitter();
	particle_emitter(int num_part);

	//Vertex Attribute Objects (VAO||vao)
	GLuint particle_vao;

	//Buffer funcutions
	void generate_buffer(GLuint program);
	void enable_vao(int attrib_loc);
	void disable_vao(int attrib_loc);

	//Rendering related functions
	void Draw(GLuint program);

};

#endif // !PARTICLE_EMITTER_H




