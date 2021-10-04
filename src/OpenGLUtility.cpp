#include "OpenGLUtility.hpp"

#include "Resource.hpp"

using namespace std;

const ShaderProgram& OpenGLUtility::BuildSimpleShaderProgram() {
    const static string vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main () {\n"
        "   gl_Position = vec4(aPos, 1.0f);\n"
        "}\0";

    const static string fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main () {\n"
        "   FragColor = vec4(1.0f, 1.0f, 0.2f, 1.0f);\n"
        "}\0";

    auto resource = Resource::getInstance();
    static auto tmp = ShaderProgram(resource.loadText( "shader/Sample.vs") , resource.loadText("shader/Sample.fs"));
    return tmp;
}
