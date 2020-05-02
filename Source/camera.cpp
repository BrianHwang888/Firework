#include "..\Headers\camera.h"

camera::camera()
{
	camera_position = glm::vec3(0.0f, 0.0f, 3.0f);
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

void camera::process_input(GLFWwindow* window, int key) {

	switch (key)
	{
	case GLFW_KEY_W:
		camera_position.y += 1.0F;

	case GLFW_KEY_A:
		camera_position.x -= 1.0F;

	case GLFW_KEY_S:
		camera_position.y -= 1.0f;

	case GLFW_KEY_D:
		camera_position.x += 1.0f;
	}
	update();
}