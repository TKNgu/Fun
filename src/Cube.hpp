#ifndef CUBE_HPP
#define CUBE_HPP

#include "DrawVertex.hpp"

class Cube : public DrawVertex {
public:
    Cube();
    void render() const override;
};

#endif // CUBE_HPP
