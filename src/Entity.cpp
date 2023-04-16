#include "Entity.hpp"

// Vertices coordinates
GLfloat entityVertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	-0.01f, -0.01f, 0.0f,     1.0f, 1.0f, 1.0f,	0.0f, 0.0f, // Lower left corner
	-0.01f,  0.01f, 0.0f,     1.0f, 1.0f, 1.0f,	0.0f, 1.0f, // Upper left corner
	 0.01f,  0.01f, 0.0f,     1.0f, 1.0f, 1.0f,	1.0f, 1.0f, // Upper right corner
	 0.01f, -0.01f, 0.0f,     1.0f, 1.0f, 1.0f,	1.0f, 0.0f  // Lower right corner
};

// Indices for vertices order
GLuint entityIndices[] =
{
	0, 2, 1, // Upper triangle
	0, 3, 2 // Lower triangle
};

Entity::Entity()
{
	this->position = glm::vec2(0.0f, 0.0f);
}

void Entity::initialize(string vert, string frag, string texturepath, float scale)
{
	shader = Shader(vert.c_str(), frag.c_str());
	vao.init();
	vao.Bind();
	vbo = VBO(entityVertices, sizeof(entityVertices));
	ebo = EBO(entityIndices, sizeof(entityIndices));
	vao.LinkAttribute(vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	vao.LinkAttribute(vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	vao.LinkAttribute(vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	vao.Unbind();
	vbo.Unbind();
	ebo.Unbind();
	scaleLoc = glGetUniformLocation(shader.ID, "scale");
	positionLoc = glGetUniformLocation(shader.ID, "position");
	this->scale = scale;
	texture = Texture(texturepath.c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	texture.texUnit(shader, "tex0", 0);
}

void Entity::render()
{
	shader.Activate();
	glUniform1f(scaleLoc, scale);
	glUniform2fv(positionLoc, 1, glm::value_ptr(position));
	texture.Bind();
	vao.Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Entity::destroy()
{
	vao.Delete();
	vbo.Delete();
	ebo.Delete();
	texture.Delete();
	shader.Delete();
}

void Entity::setPosition(glm::vec2 position)
{
	this->position = position;
}
glm::vec2 Entity::getPosition()
{
	return this->position;
}
