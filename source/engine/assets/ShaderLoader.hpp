#ifndef SAH_SHADERLOADER
#define SAH_SHADERLOADER

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include <glad.h>
#include <GLFW/glfw3.h>

#include "../../common/Vectors.hpp"

class ShaderLoader {
private:
    static std::string readShader(const char* filePath);
    static unsigned int compileShader(std::string shaderProgramName, unsigned int shaderType, std::string vertexShaderCode);

public:
    ShaderLoader() {};
    ~ShaderLoader() {};

    static void createShaderProgram(std::string shaderProgramName, std::string shaderFolder);

    static unsigned int getShader(std::string shaderProgramName);
    static std::map<std::string, unsigned int> shaderPrograms;


};

#endif
