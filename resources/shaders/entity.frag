#version 460 core

in vec3 position;
in vec3 color;
in vec2 texture;

uniform sampler2D textureUnit;

out vec4 fragmentColor;


void main()
{
	fragmentColor = texture2D(textureUnit, texture) * vec4(color,1.0);
}