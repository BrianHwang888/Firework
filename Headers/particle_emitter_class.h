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
	void generate_vao_buffer(GLuint attrib_loc, GLint begin, GLenum type, GLint size);
	void enable_vao(int attrib_loc);
	void disable_vao(int attrib_loc);

	//Rendering related functions
	void Draw();
	void Update();

};

#endif // !PARTICLE_EMITTER_H




