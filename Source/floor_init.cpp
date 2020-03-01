GLuint floor_buffer;
GLuint floor_vao;

float floor_vertices [18] = 
	{-0.5f, 0.0f, 0.5f, 
	 0.5f , 0.0f, 0.5f,
	-0.5f, 0.0f, -0.5f,
	-0.5f, 0.0f, -0.5f,
	0.5f, 0.0f, -0.5f,
	0.5f, 0.0f, 0.5f};

void floor_init(){
	glGenBuffer(1, &floor_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, &floor_buffer);

	glBufferData(GL_ARRAY_BUFFER,
}
