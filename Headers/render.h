#include "..\Firework\init.h"
#include "..\Firework\display.h"

#ifndef __RENDER_H__
#define __RENDER_H__


/* RENDERING FUNCTIONS */
extern particle_emitter* firework;
extern Floor* test_floor;

void render(Program* basic_program, Program* firework_program);

#endif // !__RENDER_H__
