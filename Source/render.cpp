#include "..\Headers\render.h"

/* Rendering function; 
	program_array[0] = pointer to basic program 
	program_array[1] = pointer to firework program 
*/
	
void render(Program** program_array, particle_emitter* firework, Floor* test_floor, camera* main_camera, Axies* gird){
	
	glClearColor(0.529f, 0.807f, 0.92f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	test_floor->draw(program_array[0]->ID);
	gird->draw(program_array[0]->ID);
	display(program_array, main_camera);

	firework->Draw(program_array[1]->ID);
	display_particles(program_array, main_camera, firework);
};
