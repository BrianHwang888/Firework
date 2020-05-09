/*---------------PARTICLE EMITTER CLASS---------------*/

#ifndef PARTICLE_EMITTER_H
#define PARTICLE_EMITTER_H

#include "particle_class.h"

class particle_emitter {
public:
	int num_particles;
	particle* particles;

	glm::vec3* part_vertices;
	glm::vec4* part_color;

	//buffers to hold particles attributes
	GLuint particle_buffer;
	particle_emitter();
	particle_emitter(int num_part);

	//Buffer funcutions
	void generate_buffer(GLuint program);

	//Rendering related functions
	void Draw(GLuint program);

};

#endif // !PARTICLE_EMITTER_H




