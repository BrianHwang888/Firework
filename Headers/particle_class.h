/* -------------------- PARTICLE CLASS --------------------*/
//

#ifndef PARTICLE_H
#define PARTICLE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/common.hpp>
#include<glm/gtc/type_ptr.hpp>

class particle{

	public:
		GLuint VAO;
		GLuint particle_buffer;

		//Attributes
		glm::vec3 vertices;
		glm::vec3 velocity;
		glm::vec4 color;
		glm::mat4 model_matrix;

		//Constructors
		particle();
		particle(glm::vec3 pos, glm::vec3 velo, glm::vec4 part_color);
		
		void generate_buffer(GLuint program);
		void enable_vao(int attrib_loc);
		void disable_vao(int attrib_loc);

		void draw(GLuint program);
};

#endif

