#include "VertexArray.h"
#include "VertexBuffer.h"

VertexArray::VertexArray   ()  {glad_glGenVertexArrays(1, &m_RendererID);}
VertexArray::~VertexArray  ()  {glad_glDeleteVertexArrays(1, &m_RendererID);}

void VertexArray::BufferAdd(VertexBuffer& vb, const VertexBufferLayout& layout)
{
    vb.Bind();
    unsigned int offset = 0;
    const auto& elements = layout.getElement();

    //set up layout
    for (unsigned int i = 0; i < elements.size(); ++i)
    {
        const auto& element = elements[i];
        offset += element.count * VertexBufferElement::getSizeofType(element.count);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer  (i, element.count, element.type, element.nor ,layout.getStride(), (const void*) offset);
    }
}
void VertexArray::Bind     ()   const    {glBindVertexArray(m_RendererID);}
void VertexArray::unBind   ()   const    {glBindVertexArray(0);}
