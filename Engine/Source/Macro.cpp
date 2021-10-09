include "Macro.h"

void checkGLError()
{
    GLenum err;
    while((err = glGetError()) != GL_NO_ERROR){
        std::cout << err;
    }
}