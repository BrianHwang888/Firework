#ifndef __CAMERA_H__
#define __CAMERA_H__

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

/*------ Camera class ------*/
//All directions are relative to the camera
class camera
{
public:
	glm::mat4 view_matrix;
	camera();

private:
	glm::vec3 camera_position;
	glm::vec3 camera_target;
	glm::vec3 camera_target_direction;
	glm::vec3 camera_right;
	glm::vec3 camera_up;

	glm::vec3 up;
};

#endif