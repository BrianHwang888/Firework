#include "..\Firework\init.h"
#include "..\Firework\display.h"

//Rendering function
void render(){
	
	glClearColor(0.529f, 0.807f, 0.92f, 1.0f);
	basic_program->use();
	display();

	test_floor->draw();
	glClear(GL_COLOR_BUFFER_BIT);
};
