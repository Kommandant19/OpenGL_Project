#include "VertexBuffer.h"
VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    glad_glGenBuffers   (1, &m_RendererID);
    glad_glBindBuffer   (GL_ARRAY_BUFFER, m_RendererID);
    glad_glBufferData   (GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer ()               {glad_glDeleteBuffers(1, &m_RendererID);}

void VertexBuffer::Bind     ()       const   {glad_glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);}
void VertexBuffer::unBind   ()       const   {glBindBuffer(GL_ARRAY_BUFFER, 0);}
