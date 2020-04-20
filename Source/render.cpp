#include "..\Firework\init.h"
#include "..\Firework\display.h"

//Rendering function
void render(){
	
	glClearColor(0.529f, 0.807f, 0.92f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	display();
	test_floor->draw(basic_program->ID);

};
