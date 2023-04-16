#version 460 core

layout (location = 0) in vec3 a_Position;
layout (location = 1) in vec3 a_Color;
layout (location = 2) in vec2 a_Texture;

uniform mat4 transform;

out vec3 position;
out vec3 color;
out vec2 texture;


void main()
{
	position = a_Position;
	color = a_Color;
	texture = a_Texture;

	gl_Position = transform * vec4(a_Position, 1.0f);
}