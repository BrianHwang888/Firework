#ifndef __CAMERA_H__
#define __CAMERA_H__

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include <stdio.h>

/*------ Camera class ------*/
//All directions are relative to the camera
class camera
{
public:
	camera();
	void process_input(GLFWwindow* window, int key, int action, int mods);
	void process_mouse(double x_pos, double y_pos);
	void update();
	glm::mat4 get_view_matrix();

private:
	glm::mat4 view_matrix;
	glm::vec3 camera_position;
	glm::vec3 camera_direction;
	glm::vec3 camera_front;
	glm::vec3 camera_right;
	glm::vec3 camera_up;
	glm::vec3 world_up;

	float yaw;
	float pitch;
	float sensitivity;
};

#endif