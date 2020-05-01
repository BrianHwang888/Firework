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
