#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/common.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "init.h"

void display(Program** program_array, camera* main_camera);
void display_particles(Program** program_array, camera* main_camera, particle_emitter* firework);

#endif // !__DISPLAY_H__

