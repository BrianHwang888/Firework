#include "..\Headers\render.h"

/* Rendering function; 
	program_array[0] = pointer to basic program 
	program_array[1] = pointer to firework program 
*/
	
void render(Program** program_array, particle_emitter* firework, Floor* test_floor, camera* main_camera, Axies* gird){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	test_floor->draw(program_array[0]->ID);
	glDisable(GL_DEPTH_TEST);
	gird->draw(program_array[0]->ID);
	display(program_array, main_camera);

	glUseProgram(program_array[1]->ID);
	display_particles(program_array, main_camera, firework);
};
