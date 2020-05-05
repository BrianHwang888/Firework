/*----Firework Vertex Shader ----*/
#version 330 core

in vec3 vPosition;
in vec4 vColor;
 
uniform mat4 model_view;
uniform mat4 projection;

out vec4 color;
out float y_pos;
void main()
{
		gl_Position = projection * model_view * vec4(vPosition, 1.0f);
		color = vColor;
		y_pos = gl_Position.y;
}