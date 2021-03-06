#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <glm/glm.hpp>
#include "DrawVertex.hpp"

class Rectangle : public DrawVertex {
public:
    Rectangle(glm::vec3, glm::vec3, glm::vec3, glm::vec3);
    Rectangle(glm::vec3, glm::vec3, glm::vec3, glm::vec3,
              glm::vec4, glm::vec4, glm::vec4, glm::vec4);
    ~Rectangle();
    void render() const override;
private:
    unsigned int EBO;
};

#endif // RECTANGLE_HPP
