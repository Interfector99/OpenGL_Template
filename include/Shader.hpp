#pragma once
#ifndef SHADER_HPP
#define SHADER_HPP

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

namespace Graphics
{
	std::string get_file_contents(const char* filename);

	class Shader
	{
	public:
		GLuint ID;

		Shader();
		void init(const char* vertexFile, const char* fragmentFile);
		void bind();
		void destroy();
	private:
		void compileErrors(unsigned int shader, const char* type);
	};
}

#endif // SHADER_HPP