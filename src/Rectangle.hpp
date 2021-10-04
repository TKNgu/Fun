#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <glm/glm.hpp>
#include "DrawVertex.hpp"
#include "ShaderProgram.hpp"

class Rectangle : public DrawVertex {
public:
    Rectangle(glm::vec3, glm::vec3, glm::vec3, glm::vec3);
    Rectangle(glm::vec3, glm::vec3, glm::vec3, glm::vec3,
              glm::vec4, glm::vec4, glm::vec4, glm::vec4);
    ~Rectangle();
    void render() const override;
private:
    static const ShaderProgram* shaderProgram;
    unsigned int EBO;
};

#endif // RECTANGLE_HPP
