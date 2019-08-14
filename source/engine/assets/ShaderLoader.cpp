#include "ShaderLoader.hpp"

std::map<std::string, unsigned int> ShaderLoader::shaderPrograms;

void ShaderLoader::createShaderProgram(std::string shaderProgramName, std::string shaderFolder){
    // read & compile shader files
    std::string vertexShaderFile = shaderFolder + "/VertexShader.glsl";
    std::string vertex_shader_code = readShader(vertexShaderFile.c_str());
    unsigned int vertex_shader = compileShader(shaderProgramName, GL_VERTEX_SHADER, vertex_shader_code);

    std::string FragmentShaderFile = shaderFolder + "/FragmentShader.glsl";
    std::string fragment_shader_code = readShader(FragmentShaderFile.c_str());
    unsigned int fragment_shader = compileShader(shaderProgramName, GL_FRAGMENT_SHADER, fragment_shader_code);

    // create Shader Program
    unsigned int shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertex_shader);
    glAttachShader(shaderProgram, fragment_shader);
    glLinkProgram(shaderProgram);

    // Check for link errors
    int link_result = 0;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &link_result);
    if (link_result == GL_FALSE) {
        int info_log_length = 0;
        glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &info_log_length);
        std::vector<char> program_log(info_log_length);
        glGetProgramInfoLog(shaderProgram, info_log_length, NULL, &program_log[0]);
        std::cout << "LINK ERROR for: \"" << shaderProgramName << "\" Shader Program."<< std::endl;
        std::cout << &program_log[0] << std::endl;
        return;
    }

    // clean up shaders
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    // add the program to programs vector
    shaderPrograms[shaderProgramName] = shaderProgram;
};

std::string ShaderLoader::readShader(const char* filePath) {
    std::string shaderCode;
    std::ifstream file(filePath, std::ios::in);

    if (!file.good()) {
        std::cout << "WARNING: can't read file \"" << filePath << "\"" << std::endl;
        std::terminate();
        return "";
    }

    // read shader file content
    file.seekg(0, std::ios::end);
    shaderCode.resize((unsigned int)file.tellg());
    file.seekg(0, std::ios::beg);
    file.read(&shaderCode[0], shaderCode.size());
    file.close();

    return shaderCode;
};

unsigned int ShaderLoader::compileShader(std::string shaderProgramName, unsigned int shaderType, std::string source) {
    unsigned int shader = glCreateShader(shaderType);

    const char* vertexShaderCode = source.c_str();
    const int shader_code_size = source.size();

    glShaderSource(shader, 1, &vertexShaderCode, &shader_code_size);
    glCompileShader(shader);

    // check for compilation errors
    int compile_result = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_result);
    if (compile_result == GL_FALSE) {
        int info_log_length = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_length);
        std::vector<char> shader_log(info_log_length);
        glGetShaderInfoLog(shader, info_log_length, NULL, &shader_log[0]);

        // print error
        std::cout << "ERROR compiling ";
        switch (shaderType) {
            case GL_VERTEX_SHADER:
                std::cout << "Vertex Shader";
                break;
            case GL_FRAGMENT_SHADER:
                std::cout << "Fragment Shader";
                break;
            default:
                std::cout << "unknown Shader";
                break;
        }
        std::cout << " for: \"" << shaderProgramName << "\" Shader Program."<< std::endl;
        std::cout << &shader_log[0] << std::endl << std::endl; // print shader compilation error
        return 0;
    }

    return shader;
};

unsigned int ShaderLoader::getShader(std::string shaderProgramName) {
    return shaderPrograms[shaderProgramName];
};
