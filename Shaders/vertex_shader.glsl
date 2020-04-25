/*---- Vertex Shader Position & Color ----*/

layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec4 vColor;
 
out vec4 color;

//uniform mat4 model_view;
//uniform mat4 projection;
void main() {

	//gl_Position = projection * model_view * vec4(vPosition.x, vPosition.y, vPosition.z, 1.0f);
	gl_Position = vec4(vPosition, 1.0f);
	color = vColor;

}