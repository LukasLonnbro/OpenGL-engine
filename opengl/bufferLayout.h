#pragma once
#include "glew/glew.h"

#include <vector>

struct vertexBufferElement
{
	int count;
	unsigned int type;
	bool normalized;
};

//Add template to allow pushing of different types of values.
class bufferLayout
{
public:
	bufferLayout();
	~bufferLayout();

	template<typename T>
	void push(int count, bool normalized) 
	{
		static_assert(false);
	}

	template <>
	void push<float>(int count, bool normalized)
	{
		elements.push_back({ count, GL_FLOAT, normalized });
		stride += getTypeSize(GL_FLOAT);
	}

	template <>
	void push<unsigned char>(int count, bool normalized)
	{
		elements.push_back({ count, GL_UNSIGNED_BYTE, normalized });
		stride += getTypeSize(GL_UNSIGNED_BYTE);
	}

	int getTypeSize(unsigned int type) const
	{
		switch (type)
		{
		case GL_FLOAT:				return sizeof(GLfloat); break;
		case GL_UNSIGNED_BYTE:		return sizeof(GLubyte); break;
		}
	}

	void tellMe();
	inline unsigned int getStride() const { return stride; }
	inline const std::vector<vertexBufferElement> getLayout() const& { return elements; }

private: 
	std::vector<vertexBufferElement> elements;

	unsigned int stride;
	void incStride(unsigned int size) { stride += size; };
};

