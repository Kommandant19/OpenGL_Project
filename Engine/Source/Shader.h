#pragma once
#include "PCH.h"

class Shader {
private:
    static std::unordered_map<std::string, int> m_LocationCache;       //Storage for shader's location data
    std::string FilePath;

    unsigned int m_RendererID;
    unsigned int ProgramID;

    unsigned int CompileShader      (unsigned int Type, const std::string& Source);
    unsigned int CreateShader       (const std::string& VertexShaderFile, const std::string& VertexFragmentFile);
    unsigned int GetUniformLocation (const std::string& Name) const;

public:
    void Bind   () const;
    void unBind () const;

    Shader(const std::string& VertexShaderFile, const std::string& VertexFragmentFile);
    ~Shader();

    void         SetUniform4f       (const std::string& name, float v0, float v1, float v2, float v3) const;
};

