#ifndef CUBE_HPP
#define CUBE_HPP

#include "DrawVertex.hpp"
#include "Texture.hpp"

class Cube : public DrawVertex {
public:
    Cube();
    void render() const override;
private:
    unsigned int EBO;
    const Texture& texture;
};

#endif // CUBE_HPP
