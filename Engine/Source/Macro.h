#if DEBUG
#define checkGLError() debugCheckGLError()
#else
#define checkGLError()
#endif
