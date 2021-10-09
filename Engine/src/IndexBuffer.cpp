#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
{
    static_assert(sizeof(unsigned int) == sizeof(GLuint));

    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}
IndexBuffer::~IndexBuffer(){glDeleteBuffers(1, &m_RendererID);}

void IndexBuffer::Bind      () const    {glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);}
void IndexBuffer::unBind    () const    {glBindBuffer(GL_ARRAY_BUFFER, 0);}