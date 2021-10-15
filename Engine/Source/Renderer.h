#pragma once
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer
{
public:
	void Draw	(const VertexArray& VAO, const IndexBuffer& IBO, Shader& shader);

	void Clear() const;
};