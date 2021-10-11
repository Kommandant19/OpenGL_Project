#include "Shader.h"

//Shader::Shader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
//{ m_RendererID = CreateShader(vertexShaderFile, fragmentShaderFile);}
//
//Shader::~Shader()
//{glad_glDeleteProgram(m_RendererID);}
//

//unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
//{
//    unsigned int ID = glCreateShader(type);
//
//    const char* src = source.c_str(); //source*[0]
//    int result;
//
//    glShaderSource   (ID, 1, &src, nullptr);
//    glCompileShader  (ID);
//
//    glad_glGetShaderiv(ID, GL_COMPILE_STATUS, &result);
//
//    if (result == GL_FALSE)
//    {
//        int length{};
//        char* message = (char*)malloc(length * sizeof(char));
//
//        glGetShaderiv          (ID, GL_INFO_LOG_LENGTH, &length);
//        glGetShaderInfoLog     (ID, length, &length, message);
//
//        std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? " vertex" : " fragment") << '\n';
//        std::cout << message << std::endl;
//
//        glDeleteShader(ID);
//
//        return 0;
//    }
//    return ID;
//}
//
//unsigned int Shader::CreateShader(const std::string &vertexShaderFile, const std::string &fragmentShaderFile)
//{
//    std::ifstream i_vs(vertexShaderFile);
//    const std::string f_vs((std::istreambuf_iterator<char>(i_vs)), std::istreambuf_iterator<char>());
//
//    std::ifstream i_fs(fragmentShaderFile);
//    const std::string f_fs((std::istreambuf_iterator<char>(i_fs)), std::istreambuf_iterator<char>());
//
//    ProgramID = glCreateProgram();
//
//    unsigned int vs = CompileShader(GL_VERTEX_SHADER, f_vs);
//    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, f_fs);
//
//    glAttachShader(ProgramID, vs);
//    glAttachShader(ProgramID, fs);
//
//    glLinkProgram(ProgramID);
//    glValidateProgram(ProgramID);
//
//    glDeleteShader(vs);
//    glDeleteShader(fs);
//
//    return true;
//}

std::string readFile(const char *filePath) {
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);

    if(!fileStream.is_open()) {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";
    while(!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}


GLuint LoadShader(const char *vertex_path, const char *fragment_path) {
    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Read shaders

    std::string vertShaderStr = readFile(vertex_path);
    std::string fragShaderStr = readFile(fragment_path);
    const char *vertShaderSrc = vertShaderStr.c_str();
    const char *fragShaderSrc = fragShaderStr.c_str();

    GLint result = GL_FALSE;
    int logLength;

    // Compile vertex shader

    std::cout << "Compiling vertex shader." << std::endl;
    glShaderSource(vertShader, 1, &vertShaderSrc, nullptr);
    glCompileShader(vertShader);

    // Check vertex shader

    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<int>vertShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(vertShader, logLength, nullptr, reinterpret_cast<GLchar *>(&vertShaderError[0]));
    std::cout << &vertShaderError[0] << std::endl;

    // Compile fragment shader

    std::cout << "Compiling fragment shader." << std::endl;
    glShaderSource(fragShader, 1, &fragShaderSrc, nullptr);
    glCompileShader(fragShader);

    // Check fragment shader

    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<int> fragShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(fragShader, logLength, nullptr, reinterpret_cast<GLchar *>(&fragShaderError[0]));
    std::cout << &fragShaderError[0] << std::endl;

    std::cout << "Linking program" << std::endl;
    GLuint program = glCreateProgram();
    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &result);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> programError( (logLength > 1) ? logLength : 1 );
    glGetProgramInfoLog(program, logLength, nullptr, &programError[0]);
    std::cout << &programError[0] << std::endl;

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);

    return program;
}

void Shader::Bind   ()   const    {glUseProgram(m_RendererID);}
void Shader::unBind ()   const    {glUseProgram(0);}

//unsigned int Shader::GetUniformLocation(const std::string& name)
//{
//    if (m_LocationCache.find(name) != m_LocationCache.end())    {return m_LocationCache[name];}
//
//    int location = glGetUniformLocation(m_RendererID, name.c_str());
//
//    if (location == -1) {std::cout << "Warning!!! Uniform: " << name << " doesn't exist! \n";}
//    else                {m_LocationCache[name] = location;}
//
//    return location;
//}
//void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)  {glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);}