#ifndef __init__
#define __init__

#include "..\Headers\shader_class.h"
#include "..\Headers\particle_emitter_class.h"
#include "..\Headers\program_class.h"
#include "..\Headers\Floor_class.h"
#include "..\Headers\camera.h"
#include "..\Headers\axis.h"

/* Rendering objects initialization */
void init(Program** program_array, particle_emitter* firework, Floor* floor, Axies* grid);

camera* init_camera();
particle_emitter* init_particle_emitter(int num_particles);
Floor* init_floor();
Axies* init_axies();

#endif

