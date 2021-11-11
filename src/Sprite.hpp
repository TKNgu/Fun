#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <glm/glm.hpp>
#include "DrawVertex.hpp"
#include "Texture.hpp"

class Sprite : public DrawVertex {
public:
    Sprite(const Texture&);
    ~Sprite();
    void render() const override;
private:
    unsigned int EBO;
    const Texture& texture;
};

#endif // SPRITE_HPP
