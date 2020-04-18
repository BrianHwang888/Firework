#ifndef __init__
#define __init__

#include "..\Headers\particle_emitter_class.h"
#include "..\Headers\program_class.h"
#include "..\Headers\Floor_class.h"

extern Program* basic_program;
extern Program* firework_program;

extern particle_emitter* firework;
extern Floor* test_floor;

void init();

#endif

