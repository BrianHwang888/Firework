#include "..\Headers\camera.h"

camera::camera()
{
	yaw = -90.0f;
	pitch = 0.0f;
	sensitivity = 0.05f;
	world_up = glm::vec3(0.0f, 1.0f, 0.0f);

	camera_position = glm::vec3(-1.0f, 6.0f, -4.0f);
	camera_front = glm::vec3(0.0f, 0.0f, -1.0f);
	camera_up = glm::vec3(0.0f, 1.0f, 0.0f);
	camera_direction = glm::vec3(0.0f, 0.1f, 0.0f);
	view_matrix = glm::lookAt(camera_position, camera_direction, camera_up);
}

glm::mat4 camera::get_view_matrix() {
	return view_matrix;
}

void camera::update() {
	//camera_direction = camera_position + camera_front;
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	camera_front = glm::normalize(front);
	
	camera_right = glm::normalize(glm::cross(camera_front, world_up));
	camera_up = glm::normalize(glm::cross(camera_right, camera_front));
	camera_direction = camera_position + camera_front;

	view_matrix = glm::lookAt(camera_position, camera_direction, camera_up);
}

void camera::process_input(GLFWwindow* window, int key, int action, int mods) {
	
	if (key == GLFW_KEY_W && action == GLFW_PRESS) 
		camera_position += camera_front;
	
	if (key == GLFW_KEY_A && action == GLFW_PRESS) 
		camera_position -= glm::normalize(glm::cross(camera_front, camera_up));
	
	if (key == GLFW_KEY_S && action == GLFW_PRESS) 
		camera_position -= camera_front;
	
	if (key == GLFW_KEY_D && action == GLFW_PRESS) 
		camera_position += glm::normalize(glm::cross(camera_front, camera_up));
	
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) 
		camera_position += camera_up;

	if (key == GLFW_KEY_O && action == GLFW_PRESS) {
		camera_direction = glm::vec3(0.0f, 0.1f, 0.0f);
		camera_position = glm::vec3(-1.0f, 6.0f, -4.0f);
	}

	if (key == GLFW_KEY_O && action == GLFW_PRESS && mods == GLFW_MOD_SHIFT) {
		camera_direction = camera_front + camera_position;
	}
	
	if (key == GLFW_KEY_P && action == GLFW_PRESS)
		camera_position = glm::vec3(-1.0f, 6.0f, -4.0f);

	printf("CAMERA POSITION: %f, %f, %f\n", camera_position.x, camera_position.y, camera_position.z);
	update();
}

void camera::process_mouse(double x_offest, double y_offset) {
	x_offest *= sensitivity;
	y_offset *= sensitivity;

	yaw += x_offest;
	pitch += y_offset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	update();
}