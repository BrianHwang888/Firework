#include "..\Headers\axis.h"

Axies::Axies() {
	vertex_count = 6;

	vertices = new glm::vec3[vertex_count];
	colors = new glm::vec4[vertex_count];

	for (int i = 0; i <= 4; i+=2) 
		vertices[i] = glm::vec3(0.0f, 1.0f, 0.0f);
	vertices[1] = glm::vec3(10.0f, 0.0f, 0.0f);
	vertices[3] = glm::vec3(0.0f, 10.0f, 0.0f);
	vertices[5] = glm::vec3(0.0f, 0.0f, 10.0f);

	colors[0] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	colors[1] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	colors[2] = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
	colors[3] = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
	colors[4] = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f);
	colors[5] = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f);

}

void Axies::gen_buffer(GLuint program) {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &axies_vertices_data);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, axies_vertices_data);
	glBufferData(GL_ARRAY_BUFFER, vertex_count * (sizeof(glm::vec3) + sizeof(glm::vec4)), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, vertex_count * sizeof(glm::vec3), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, vertex_count * sizeof(glm::vec3), vertex_count * sizeof(glm::vec4), colors);
	
	GLuint vertex_position = glGetAttribLocation(program, "vPosition");
	enable_vao(vertex_position);
	glVertexAttribPointer(vertex_position, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);

	GLuint vertex_color = glGetAttribLocation(program, "vColor");
	enable_vao(vertex_color);
	glVertexAttribPointer(vertex_color, 4, GL_FLOAT, GL_FALSE, sizeof(glm::vec4), (void*)(vertex_count * sizeof(glm::vec3)));

	glLineWidth(2.0f);
}

void Axies::enable_vao(GLuint attrib_loc) {
	glEnableVertexAttribArray(attrib_loc);
}

void Axies::disable_vao(GLuint attrib_loc) {
	glDisableVertexAttribArray(attrib_loc);
}

void Axies::draw(GLuint program) {
	glUseProgram(program);
	glBindVertexArray(VAO);
	glDrawArrays(GL_LINES, 0, vertex_count);
}