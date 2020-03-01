#include "..\Headers\particle_emitter_class.h"
#include "..\Headers\program_class.h"

extern particle_emitter firework;
extern Program firework_program;

//initialization of firework program
void init(){	
		
	/*Generating buffer for firework*/
	glGenBuffers(1, &(firework.particle_buffer));
	glBindBuffer(GL_ARRAY_BUFFER, firework.particle_buffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(firework.particle_vertices) + sizeof(firework.particle_colors), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(firework.particle_vertices), firework.particle_vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(firework.particle_vertices), sizeof(firework.particle_colors), firework.particle_colors);
	
	glGenBuffers(1, &(firework.particle_vao));
	glBindVertexArray(firework.particle_vao);
	glVertexAttribPointer(0, 3, GL_FLOAT, FALSE, 0, (void*)0);
	glVertexAttribPointer(sizeof(firework.particle_vertices), GL_BGRA, GL_FLOAT, FALSE, 0, (void*)1);
 
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);	
};