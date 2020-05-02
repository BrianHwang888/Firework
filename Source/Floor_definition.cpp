#include "..\Headers\Floor_class.h"

Floor::Floor() {
	vertex_count = 6;
	vertices = new glm::vec3[vertex_count];
	colors = new glm::vec4[vertex_count];

	vertices[0] = glm::vec3(5.0f, 0.0f, 8.0f);
	vertices[1] = glm::vec3(-5.0f, 0.0f, 8.0f);
	vertices[2] = glm::vec3(-5.0f, 0.0f, -4.0f);

	vertices[3] = glm::vec3(-5.0f, 0.0f, -4.0f);
	vertices[4] = glm::vec3(5.0f, 0.0f, -4.0f);
	vertices[5] = glm::vec3(5.0f, 0.0f, 8.0f);
	
	for (int i = 0; i < vertex_count; i++) 
		colors[i] = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);

	/*for (int i = 0; i < vertex_count; i++) {
		printf("Vertex %d: %f, %f, %f\nColor %d: %f, %f, %f, %f\n", i, vertices[i].x, vertices[i].y, vertices[i].z, i, colors[i].r, colors[i].g, colors[i].b, colors[i].a);
	}*/
}

Floor::Floor(const char* filename){
		read_floor_file(filename);
};

/*Reads floor vertices file; 1st # is num_polygons && each line 1st int indecating # of elements vertex consist of; must be 3*/ 
void Floor::read_floor_file(const char* filename){
	FILE* fp;
	errno_t errno;
	float x, y, z;
	int vert_points, index = 0;
	
	errno = fopen_s(&fp, filename, "r");
	if (errno ^ 0) {
		printf("Failed to read file: %s\n", filename);
		exit(EXIT_FAILURE);
	}

	//reads in the number of vertices the floor has
	fscanf_s(fp, "%d", &vertex_count);
	vertices = new glm::vec3[vertex_count];
	colors = new glm::vec4[vertex_count];

	for (int poly = 0; poly < vertex_count; poly++) {

		//checking if vertex consist 3 elements (x/y/z values)
		if (fscanf_s(fp, "%d", &vert_points) && vert_points == 3) {
			//reading vertices from file
			for (int i = 0; i < 3; i++) {

				fscanf_s(fp, "%f", &x);
				fscanf_s(fp, "%f", &y);
				fscanf_s(fp, "%f", &z);

				vertices[index] = glm::vec3(x, y, z);
				colors[index] = glm::vec4(0.25f, 0.25f, 0.25f, 0.65f);
				index++;

			}
		}
		else {
			printf("Invalid format for data in file\n");
			system("pause");
			exit(0);
		}
	}
};

//Generates floor buffer with vertex position data followed by color data
void Floor::gen_buffer(GLuint program){
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &floor_vertices_data);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, floor_vertices_data);
	glBufferData(GL_ARRAY_BUFFER, vertex_count * (sizeof(glm::vec3) +  sizeof(glm::vec4)), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, vertex_count * sizeof(glm::vec3), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, vertex_count * sizeof(glm::vec3), sizeof(glm::vec4) * vertex_count, colors);
	
	GLuint vertex_position = glGetAttribLocation(program, "vPosition");
	enable_vao(vertex_position);
	glVertexAttribPointer(vertex_position, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);

	GLuint vertex_color = glGetAttribLocation(program, "vColor");
	enable_vao(vertex_color);
	glVertexAttribPointer(vertex_color, 4, GL_FLOAT, GL_FALSE, sizeof(glm::vec4), (void*)(vertex_count * sizeof(glm::vec3)));

	printf("%d , %d\n", vertex_position, vertex_color);
};

void Floor::enable_vao(GLuint attrib_loc) {
	glEnableVertexAttribArray(attrib_loc);
}

void Floor::disable_vao(GLuint attrib_loc) {
	glDisableVertexAttribArray(attrib_loc);
}

//draws floor; Assumes location 0 is vertex position and 1 is color data
void Floor::draw(GLuint program) {
	glUseProgram(program);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, vertex_count);
}