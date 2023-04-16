#include "Entity.hpp"

GLfloat vertices[] =
{//  COORDINATES            COLORS              TexCoord
	-0.01f, -0.01f, 0.0f,	1.0f, 1.0f, 1.0f,	0.0f, 0.0f,
	-0.01f,  0.01f, 0.0f,   1.0f, 1.0f, 1.0f,	0.0f, 1.0f,
	 0.01f,  0.01f, 0.0f,   1.0f, 1.0f, 1.0f,	1.0f, 1.0f,
	 0.01f, -0.01f, 0.0f,   1.0f, 1.0f, 1.0f,	1.0f, 0.0f
};

GLuint indices[] =
{
	0, 2, 1,
	0, 3, 2
};

Entity::Entity()
{

}

void Entity::initialize(std::string vert, std::string frag, std::string texturepath)
{
	shader.init(vert.c_str(), frag.c_str());
	vao.init();
	vao.bind();
	vbo.init(vertices, sizeof(vertices));
	ebo.init(indices, sizeof(indices));
	vao.linkAttribute(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	vao.linkAttribute(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	vao.linkAttribute(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	vao.unbind();
	vbo.unbind();
	ebo.unbind();
	texture.init(texturepath.c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	texture.setTextureUnit(shader, "tex0", 0);
}

void Entity::render()
{
	shader.bind();
	texture.bind();
	vao.bind();

	transform = glm::mat4(1.0f);
	transform = glm::scale(transform, glm::vec3(50.0f,50.0f,0.0f));
	transformLoc = glGetUniformLocation(shader.ID, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBlendFunc(GL_ONE, GL_ZERO);
}

void Entity::destroy()
{
	vao.destroy();
	vbo.destroy();
	ebo.destroy();
	texture.destroy();
	shader.destroy();
}
