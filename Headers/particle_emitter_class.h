/*---------------PARTICLE EMITTER CLASS---------------*/

#ifndef PARTICLE_EMITTER_H
#define PARTICLE_EMITTER_H

#include "particle_class.h"

class particle_emitter {
public:
	int num_particles;
	particle* particles;

	//buffers to hold particles attributes
	GLuint particle_buffer;
	particle_emitter();
	particle_emitter(int num_part);

	//Vertex Attribute Objects (VAO||vao)
	GLuint particle_vao;

	//Buffer funcutions
	void generate_buffer();

	//Rendering related functions
	void Draw();
	void Update();

};

#endif // !PARTICLE_EMITTER_H




