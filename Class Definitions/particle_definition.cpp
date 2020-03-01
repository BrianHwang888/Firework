#include "..\Headers\particle_class.h"

//Definitions for particle class
particle::particle() {
	vertices = glm::vec3(0.0f, 0.1f, 0.0f);
	velocity = glm::vec3(2.0f * ((rand() % 256) / 256.0f - 0.5f), 1.2 * 2.0 * ((rand() % 256) / 256.0), 2.0 * ((rand() % 256) / 256.0f - 0.5f));
	color = glm::vec4((float) rand() / RAND_MAX, (float) rand() / RAND_MAX, (float) rand() / RAND_MAX, 1.0f);
};	

particle::particle(glm::vec3 pos, glm::vec3 velo, glm::vec4 part_color):vertices(pos),velocity(velo),color(part_color){};


