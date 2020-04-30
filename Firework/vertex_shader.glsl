/*---- Vertex Shader Position & Color ----*/
#version 330 core

in vec3 vPosition;
in vec4 vColor;
 
out vec4 color;

//uniform mat4 model_view;
//uniform mat4 projection;
uniform mat4 transform;

void main() 
{

	//gl_Position = projection * model_view * vec4(vPosition, 1.0f);
	gl_Position = transform * vec4(vPosition, 1.0f);
	color = vColor;

}