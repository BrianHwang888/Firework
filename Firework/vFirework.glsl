/*----Firework Vertex Shader ----*/
#version 330 

in vec3 vPosition;
in vec4 vColor;
 
uniform mat4 ModelView;
uniform mat4 Projection;

out vec4 color;
out float y_pos;
void main()
{
	gl_Position = Projection * ModelView * vPosition;	
	color = vColor;
	y_pos = gl_Position.y;
}