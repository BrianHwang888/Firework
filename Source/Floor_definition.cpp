#include "..\Headers\Floor_class.h"

Floor::Floor(){
	num_polygons = 2;
	vertices = new glm::vec3[4];

	vertices[0] = glm::vec3(1.0f, 0.0f, 1.0f);
	vertices[1] = glm::vec3(1.0f, 0.0f, -1.0f);
	vertices[2] = glm::vec3(-1.0f, 0.0f, -1.0f);
	vertices[3] = glm::vec3(-1.0f, 0.0f, 1.0f);

	indices = new unsigned int[6];
	for (int i = 0; i < 3; i++) {
		indices[i] = i;
		indices[i + 3] = i + 1;
	}
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
	fscanf(fp, "%d", &num_polygons);
	vertices = new glm::vec3[num_polygons * 3];
	colors = new glm::vec4[num_polygons * 3];

	for (int poly = 0; poly < num_polygons; poly++) {

		//checking if vertex consist 3 elements (x/y/z values)
		if (fscanf(fp, "%d", &vert_points) && vert_points == 3) {
			//reading vertices from file
			for (int i = 0; i < 3; i++) {

				fscanf(fp, "%f", &x);
				fscanf(fp, "%f", &y);
				fscanf(fp, "%f", &z);

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

void Floor::gen_buffer(){
	glGenBuffers(1, &floor_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, floor_buffer);
	
	glBufferData(GL_ARRAY_BUFFER, 3 * num_polygons * (sizeof(glm::vec3) + sizeof(glm::vec4)), NULL, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), &vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(vertices) + sizeof(colors), &colors);		
};

void Floor::gen_vao_buffer(){
	glGenBuffers(1, &VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VAO);
};



floor::floor()
{
}


floor::~floor()
{
}
