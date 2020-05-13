/*---------------PARTICLE EMITTER CLASS---------------*/

#ifndef PARTICLE_EMITTER_H
#define PARTICLE_EMITTER_H

#include "particle_class.h"

class particle_emitter {
public:
	int num_particles;
	particle* particles;

	glm::vec3* part_velocity;

	//buffers to hold particles attributes
	particle_emitter();
	particle_emitter(int num_part);

	//Buffer funcutions
	void generate_buffer(GLuint program);

};

#endif // !PARTICLE_EMITTER_H




