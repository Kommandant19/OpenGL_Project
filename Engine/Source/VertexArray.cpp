#include "VertexArray.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

VertexArray::VertexArray   ()  {glGenVertexArrays       (1, &m_RendererID);}
VertexArray::~VertexArray  ()  {glDeleteVertexArrays    (1, &m_RendererID);}

void VertexArray::BufferAdd(VertexBuffer& VBO, const VertexBufferLayout& layout)
{
    VBO.Bind();
    unsigned int offset = 0;
    const auto& elements = layout.getElement();

    //set up layout
    for (unsigned int i = 0; i < elements.size(); ++i)
    {
        const auto& element = elements[i];
        offset += element.count * VertexBufferElement::getSizeofType(element.count);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer  (i, element.count, element.type, element.condition ,layout.getStride(), (const void*) offset);
    }
}
void VertexArray::Bind     ()   const    {glBindVertexArray(m_RendererID);}
void VertexArray::unBind   ()   const    {glBindVertexArray(0);}