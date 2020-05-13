#include "..\Headers\camera.h"

camera::camera()
{
	camera_position = glm::vec3(-1.0f, 6.0f, -4.0f);
	//camera_position = glm::vec3(0.0f, 0.0f, -3.0f);
	//camera_target = glm::vec3(camera_position.x + 1.0f, camera_position.y, 0.0f);
	camera_target = glm::vec3(0.0f, 0.0f, 0.0f);
	
	camera_target_direction = glm::normalize(camera_position - camera_target);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	camera_right = glm::normalize(glm::cross(up, camera_target_direction));
	camera_up = glm::normalize(glm::cross(camera_target, camera_right));

	view_matrix = glm::lookAt(camera_position, camera_target, up);
}

glm::mat4 camera::get_view_matrix() {
	return view_matrix;
}

void camera::update() {
	view_matrix = glm::lookAt(camera_position, camera_target, up);
}

void camera::process_input(GLFWwindow* window, int key, int action) {

	
	if (key == GLFW_KEY_W && action == GLFW_PRESS) {
		camera_position += 1.0f;
		printf("CAMERA POSITION: %f, %f, %f\n", camera_position.x, camera_position.y, camera_position.z);
	}
	
	if (key == GLFW_KEY_A && action == GLFW_PRESS) {
		camera_position -= 1.0f;
		printf("CAMERA POSITION: %f, %f, %f\n", camera_position.x, camera_position.y, camera_position.z);
	}
	
	if (key == GLFW_KEY_S && action == GLFW_PRESS) {
		camera_position.y -= 1.0f;
		printf("CAMERA POSITION: %f, %f, %f\n", camera_position.x, camera_position.y, camera_position.z);
	}
	
	if (key == GLFW_KEY_D && action == GLFW_PRESS) {
		camera_position.x += 1.0f;
		printf("CAMERA POSITION: %f, %f, %f\n", camera_position.x, camera_position.y, camera_position.z);
	}
	
	if (key == GLFW_KEY_O && action == GLFW_PRESS)
		camera_target = glm::vec3(0.0f, 0.0f, 0.0f);
	
	if (key == GLFW_KEY_P && action == GLFW_PRESS)
		camera_position = glm::vec3(-1.0f, 6.0f, -4.0f);
	
	update();
}