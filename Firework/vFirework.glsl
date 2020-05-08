/*----Firework Vertex Shader ----*/
#version 330 core

in vec3 vPosition;
in vec4 vColor;
in vec3 vVelocity;

out vec4 color;
out float y_pos;

uniform mat4 projection;
uniform mat4 model_view;
uniform float elapsed_time;

void main(){

	vec4 final_position = vec4(vPosition, 1.0f);
	
	final_position.y = pow(-4.9,-10000000) * elapsed_time * elapsed_time + vVelocity.y * elapsed_time * 0.001f + vPosition.y;
	final_position.x = vVelocity.x * elapsed_time * 0.001f + vPosition.x;
	final_position.z = vVelocity.z * elapsed_time * 0.001f + vPosition.z;

	gl_Position = projection * model_view * final_position;
	//gl_Position = projection * model_view * vec4(vPosition, 1.0f);
	color = vColor;
	y_pos = final_position.y;
}