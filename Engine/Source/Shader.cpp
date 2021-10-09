#include "Shader.h"

Shader::Shader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile) : m_RendererID(0)
{ m_RendererID = CreateShader(vertexShaderFile, fragmentShaderFile);}

Shader::~Shader()   {glad_glDeleteProgram(m_RendererID);}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
    unsigned int ID = glad_glCreateShader(type);

    const char* src = source.c_str(); //source*[0]

    int result;

    glad_glShaderSource     (ID, 1, &src, nullptr);
    glad_glCompileShader    (ID);

    glad_glGetShaderiv(ID, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE)
    {
        int length{};
        char* message = (char*)malloc(length * sizeof(char));

        glad_glGetShaderiv          (ID, GL_INFO_LOG_LENGTH, &length);
        glad_glGetShaderInfoLog     (ID, length, &length, message);

        std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? " vertex" : " fragment") << '\n';
        std::cout << message << std::endl;

        glad_glDeleteShader(ID);

        return 0;
    }
    return ID;
}

unsigned int Shader::CreateShader(const std::string &vertexShaderFile, const std::string &fragmentShaderFile)
{
    std::ifstream i_vs(vertexShaderFile);
    const std::string f_vs((std::istreambuf_iterator<char>(i_vs)), std::istreambuf_iterator<char>());

    std::ifstream i_fs(fragmentShaderFile);
    const std::string f_fs((std::istreambuf_iterator<char>(i_fs)), std::istreambuf_iterator<char>());

    ProgramID = glad_glCreateProgram();

    unsigned int vs = CompileShader(GL_VERTEX_SHADER, f_vs);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, f_fs);

    glad_glAttachShader(ProgramID, vs);
    glad_glAttachShader(ProgramID, fs);

    glad_glLinkProgram(ProgramID);
    glad_glValidateProgram(ProgramID);

    glad_glDeleteShader(vs);
    glad_glDeleteShader(fs);

    return true;
}

void Shader::Bind   ()   const   {glad_glUseProgram(m_RendererID);}
void Shader::unBind ()   const   {glad_glUseProgram(0);}

//unsigned int Shader::GetUniformLocation(const std::string& name)
//{
//    if (m_LocationCache.find(name) != m_LocationCache.end())    {return m_LocationCache[name];}
//
//    int location = glad_glGetUniformLocation(m_RendererID, name.c_str());
//
//    if (location == -1) {std::cout << "Warning!!! Uniform: " << name << " doesn't exist! \n";}
//    else                {m_LocationCache[name] = location;}
//
//    return location;
//}
