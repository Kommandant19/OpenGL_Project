#pragma once
#include "VertexBuffer.h"

template<typename T>
struct foobar : std::false_type
        { };

struct VertexBufferElement
        {
    unsigned int type;
    unsigned int count;
    bool nor;

    static unsigned int getSizeofType(unsigned int type)
    {
        switch (type)
        {
            case GL_FLOAT:          return 4;
            case GL_UNSIGNED_INT:   return 4;
            case GL_UNSIGNED_BYTE:  return 1;
        }
        return  0;
    }
        };

class VertexBufferLayout
        {
        private:
            std::vector<VertexBufferElement> m_Element;
            unsigned int m_Stride;

        public:
            VertexBufferLayout() : m_Stride(0) {};

            template<class T>
                    void push(unsigned int count)
                    {
                        static_assert(foobar<T>::value);
                    }

                    inline std::vector<VertexBufferElement> getElement	        () const& { return m_Element; }
                    inline unsigned int getStride					            () const  { return m_Stride; }
        };
template<>
inline void VertexBufferLayout::push<float>(unsigned int count)
{
    m_Element.push_back({ GL_FLOAT, count, GL_FALSE });
    m_Stride += VertexBufferElement::getSizeofType(GL_FLOAT);
}

template<>
inline void  VertexBufferLayout::push<unsigned int>(unsigned int count)
{
    m_Element.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
    m_Stride += VertexBufferElement::getSizeofType(GL_UNSIGNED_INT);
}

template<>
inline void  VertexBufferLayout::push<unsigned char>(unsigned int count)
{
    m_Element.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
    m_Stride += VertexBufferElement::getSizeofType(GL_UNSIGNED_BYTE);
}