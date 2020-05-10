/*----Firework Fragment Shader ----*/
#version 330 core

in float y_pos;
in vec4 color;

out vec4 fcolor;

void main(){
	fcolor = color;
}