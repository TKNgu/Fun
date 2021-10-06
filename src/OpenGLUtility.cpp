#include "OpenGLUtility.hpp"

#include <sstream>
#include <istream>
#include <fstream>
#include <stdexcept>
#include "Resource.hpp"

using namespace std;

const ShaderProgram OpenGLUtility::BuildSimpleShaderProgram() {
    return ShaderProgram(Resource::getInstance().loadText("shader/Sample.vs"),
                         Resource::getInstance().loadText("shader/Sample.fs"));
}
