#include "..\Headers\Floor_class.h"

Floor::Floor(){
	num_polygons = 2;
	vertices = new glm::vec3[4];

	vertices[0] = glm::vec3(5.0f, 0.0f, 8.0f);
	vertices[1] = glm::vec3(5.0f, 0.0f, -4.0f);
	vertices[2] = glm::vec3(-5.0f, 0.0f, -4.0f);
	vertices[3] = glm::vec3(-5.0f, 0.0f, 8.0f);

	indices = new unsigned int[6];
	for (int i = 0; i < 3; i++) {
		indices[i] = i;
		indices[i + 3] = i + 1;
	}

	for(int i = 0; i < (size_t)sizeof(colors) / sizeof(glm::vec4); i++)
		colors[i] = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f);
};

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

	//reads in the number of polygons the floor has
	fscanf_s(fp, "%d", &num_polygons);
	vertices = new glm::vec3[num_polygons * 3];
	colors = new glm::vec4[num_polygons * 3];

	for (int poly = 0; poly < num_polygons; poly++) {

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
void Floor::gen_buffer(){
	glGenBuffers(1, &floor_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, floor_buffer);
	
	glBufferData(GL_ARRAY_BUFFER, 3 * num_polygons * (sizeof(glm::vec3) + sizeof(glm::vec4)), NULL, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), &vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(vertices) + sizeof(colors), &colors);		
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
	glBindBuffer(GL_ARRAY_BUFFER, floor_buffer);

	//Vertex position data
	enable_vao(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	
	//Color data
	enable_vao(1);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(glm::vec3) * num_polygons * 3));
	
	glDrawArrays(GL_TRIANGLES, 0, 3 * num_polygons);
	disable_vao(0);
	disable_vao(1);
}