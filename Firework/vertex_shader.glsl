/*---- Vertex Shader Position & Color ----*/
#version 330 core

in vec3 vPosition;
in vec4 vColor;
 
out vec4 color;

void main() 
{

	gl_Position = vec4(vPosition, 1.0f);
	color = vColor;

}