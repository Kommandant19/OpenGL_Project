#pragma once
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer
{
public:
	void Draw(unsigned int& VAO, const IndexBuffer& IBO, Shader& shader);

	void Clear() const;
};