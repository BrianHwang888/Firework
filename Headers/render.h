#include "..\Firework\init.h"
#include "..\Firework\display.h"

#ifndef __RENDER_H__
#define __RENDER_H__


/* RENDERING FUNCTIONS */
void render(Program** program_array, particle_emitter* firework, Floor* test_floor, camera* main_camera);

#endif // !__RENDER_H__
