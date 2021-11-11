#ifndef CUBE_HPP
#define CUBE_HPP

#include "DrawVertex.hpp"

class Cube : public DrawVertex {
public:
    Cube();
    void update(float) override;
    void render(glm::mat4) const override;
};

#endif // CUBE_HPP
