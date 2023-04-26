#include"Texture.hpp"

namespace Graphics
{
	unsigned char* loadPNGResource(int resource, int& widthImg, int& heightImg, int& numColCh)
	{
		HMODULE hModule = GetModuleHandle(NULL);
		HRSRC hResource = FindResource(hModule, MAKEINTRESOURCE(resource), MAKEINTRESOURCE(PNG));
		HGLOBAL hMemory = LoadResource(hModule, hResource);
		LPVOID pData = LockResource(hMemory);
		DWORD dwSize = SizeofResource(hModule, hResource);

		unsigned char* bytes = stbi_load_from_memory(static_cast<const stbi_uc*>(pData), dwSize, &widthImg, &heightImg, &numColCh, STBI_rgb_alpha);
		return bytes;
	}

	Texture::Texture()
	{

	}

	void Texture::init(int image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType)
	{
		type = texType;
		stbi_set_flip_vertically_on_load(true);

		int widthImg, heightImg, numColCh;
		unsigned char* bytes = loadPNGResource(image, widthImg, heightImg, numColCh);
		if (bytes == 0)
		{
			throw "TEXTURE::INIT -> Texture not found";
		}

		glGenTextures(1, &ID);
		glActiveTexture(slot);
		glBindTexture(texType, ID);

		glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// Extra lines in case you choose to use GL_CLAMP_TO_BORDER
		// float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
		// glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);

		/*std::string imageExtension = image;
		if(imageExtension.substr(imageExtension.size() - 4) == "jpeg")
		{
			glTexImage2D(texType, 0, GL_RGB, widthImg, heightImg, 0, format, pixelType, bytes);
		}
		else if (imageExtension.substr(imageExtension.size() - 3) == "jpg")
		{
			glTexImage2D(texType, 0, GL_RGB, widthImg, heightImg, 0, format, pixelType, bytes);
		}
		else if (imageExtension.substr(imageExtension.size() - 3) == "png")
		{
			glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes);
		}
		else
		{
			throw "TEXTURE::INIT -> Undefined image extension";
		}*/

		glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes);
		glGenerateMipmap(texType);

		stbi_image_free(bytes);

		glBindTexture(texType, 0);
	}

	void Texture::bind()
	{
		glBindTexture(type, ID);
	}

	void Texture::unbind()
	{
		glBindTexture(type, 0);
	}

	void Texture::destroy()
	{
		glDeleteTextures(1, &ID);
	}
}