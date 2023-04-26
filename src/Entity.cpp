#include "Entity.hpp"

GLfloat vertices[] =
{//  COORDINATES            COLORS              TEXTURES
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

void Entity::init(int vertexPath, int fragmentPath, int texturePath)
{
	m_Shader.init(vertexPath, fragmentPath);
	m_Vao.init();
	m_Vao.bind();
	m_Vbo.init(vertices, sizeof(vertices));
	m_Ebo.init(indices, sizeof(indices));
	m_Vao.linkAttribute(m_Vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	m_Vao.linkAttribute(m_Vbo, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	m_Vao.linkAttribute(m_Vbo, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	m_Vao.unbind();
	m_Vbo.unbind();
	m_Ebo.unbind();
	m_Texture.init(texturePath, GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	m_Shader.setSampler2D("textureUnit", 0);

	m_Position = glm::vec3(0.0f, 0.0f, 0.0f);
	m_Scale = glm::vec3(10.0f, 10.0f, 0.0f);
	m_Rotation = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Entity::render(glm::mat4 projection, glm::mat4 view)
{
	m_Shader.bind();
	m_Texture.bind();
	m_Vao.bind();



	m_Transform = glm::mat4(1.0f);
	m_Transform = glm::translate(m_Transform, m_Position);
	m_Rotation.z += 0.5f;
	m_Transform = glm::rotate(m_Transform, glm::radians(m_Rotation.x), glm::vec3(1.0, 0.0, 0.0));
	m_Transform = glm::rotate(m_Transform, glm::radians(m_Rotation.y), glm::vec3(0.0, 1.0, 0.0));
	m_Transform = glm::rotate(m_Transform, glm::radians(m_Rotation.z), glm::vec3(0.0, 0.0, 1.0));
	m_Transform = glm::scale(m_Transform, m_Scale);
	
	m_Shader.setMat4("projection", projection);
	m_Shader.setMat4("view", view);
	m_Shader.setMat4("transform", m_Transform);

	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBlendFunc(GL_ONE, GL_ZERO);
}

void Entity::update(float deltaTime)
{

}

void Entity::destroy()
{
	m_Vao.destroy();
	m_Vbo.destroy();
	m_Ebo.destroy();
	m_Texture.destroy();
	m_Shader.destroy();
}

void Entity::translate(glm::vec3 translation)
{
	m_Position += translation;
}
