#pragma once
#include "PCH.h"

class Shader{
private:
    std::unordered_map<std::string, int> m_LocationCache;
    std::string m_FilePath;

    unsigned int m_RendererID;
    unsigned int ProgramID{};
public:
    Shader  (const char* vertexShaderFile, const char* fragmentShaderFile);
    ~Shader ();

    //bind the shader
    void Bind         ()   const;
    void unBind       ()   const;

//    unsigned int GetUniformLocation (const std::string& name);
//    unsigned int CompileShader      (unsigned int type, const std::string& source);
//    unsigned int CreateShader       (const std::string& vertexShader, const std::string& fragmentShader);
    std::string readFile          (const char *filePath);
    unsigned int LoadShader       (const char *vertex_path, const char* fragment_path);

    //Set uniform
    void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
};