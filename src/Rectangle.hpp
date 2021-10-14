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
    void update(float) override;
    void render(glm::mat4) const override;
private:
    unsigned int EBO;
};

#endif // RECTANGLE_HPP
