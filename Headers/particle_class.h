/* -------------------- PARTICLE CLASS --------------------*/
//

#ifndef PARTICLE_H
#define PARTICLE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/common.hpp>

class particle{

	public:
		
		//Attributes
		glm::vec3 vertices;
		glm::vec3 velocity;
		glm::vec4 color;
		
		//Constructors
		particle();
		particle(glm::vec3 pos, glm::vec3 velo, glm::vec4 part_color);
			
};

#endif

