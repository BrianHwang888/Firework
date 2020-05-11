/*----Firework Fragment Shader ----*/
#version 330 core

in float y_pos;
in vec4 color;

out vec4 fcolor;

void main(){
	if(y_pos <= 0)
		discard;
	fcolor = color;
}