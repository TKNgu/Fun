#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "DrawVertex.hpp"
#include "glm/glm.hpp"

class Triangle : public DrawVertex {
public:
    Triangle(glm::vec3, glm::vec3, glm::vec3);
    Triangle(glm::vec3, glm::vec3, glm::vec3,
             glm::vec4, glm::vec4, glm::vec4);
    void setColor(glm::vec3, glm::vec3, glm::vec3);
    void render() const override;
};

#endif // TRIANGLE_HPP
