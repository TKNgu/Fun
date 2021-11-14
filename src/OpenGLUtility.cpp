#include "OpenGLUtility.hpp"

#include <sstream>
#include <istream>
#include <fstream>
#include <stdexcept>
#include "Resource.hpp"
#include "glm/gtc/matrix_transform.hpp"

using namespace std;
using namespace glm;

const ShaderProgram OpenGLUtility::BuildSimpleShaderProgram() {
    return ShaderProgram(Resource::getInstance().loadText("shader/Sample.vs"),
                         Resource::getInstance().loadText("shader/Sample.fs"));
}

const TransformsFunction OpenGLUtility::translate(vec3 vector) {
    return [vector](mat4 modelMat) {
        return glm::translate(modelMat, vector);
    };
}

const TransformsFunction OpenGLUtility::rotate(float angle, glm::vec3 vector) {
    return [angle, vector](glm::mat4 modelMat) {
        return glm::rotate(modelMat, angle, vector);
    };
}

const TransformsFunction OpenGLUtility::scale(glm::vec3 ratio) {
    return [ratio](glm::mat4 modelMat) {
        return glm::scale(modelMat, ratio);
    };
}
