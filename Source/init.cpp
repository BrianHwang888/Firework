#include "..\Firework\init.h"

//initialization of firework program
void init() {

	/*Generating buffer for firework*/
	firework->generate_buffer();
	firework->generate_vao_buffer(0, 0, GL_FLOAT, 3);
	firework->generate_vao_buffer(1, firework->num_particles * sizeof(glm::vec3), GL_FLOAT, GL_RGBA);

	firework->enable_vao(0);
	firework->enable_vao(1);

	test_floor->gen_buffer();
	test_floor->gen_vao_buffer(0, 0, GL_FLOAT, 3);
	test_floor->gen_vao_buffer(1, 4 * sizeof(glm::vec3), GL_FLOAT, GL_RGBA);
	
	test_floor->enable_vao(0);
	test_floor->enable_vao(1);

}
