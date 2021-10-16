#pragma once
#include "VertexBuffer.h"

class VertexBufferLayout;

class VertexArray
{
private:
     unsigned int m_RendererID = 0;

public:
    VertexArray     ();
    ~VertexArray    ();

    void BufferAdd  (VertexBuffer& vb, const VertexBufferLayout& layout);
    void Bind       ()     const;
    void unBind     ()     const;
};
