/*----Firework Fragment Shader ----*/
#version 330 

in float y_pos;
in vec4 color;

out vec4 fcolor;

void main(){
	if(y_pos < 0.1)
		discard;
	fcolor = color;
}