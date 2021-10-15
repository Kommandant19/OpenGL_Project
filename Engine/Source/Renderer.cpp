#include "Renderer.h"

void Renderer::Draw(const VertexArray& VAO, const IndexBuffer& IBO, Shader& shader)
{
    shader.SetUniform4f("u_Color", 1.0f, 2.0f, 0.0f, 0.0f);

    shader.Bind();
    VAO.Bind();
    IBO.Bind();

    glDrawElements(GL_TRIANGLES, IBO.GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Clear() const
{
    glClear(GL_COLOR_BUFFER_BIT);
}