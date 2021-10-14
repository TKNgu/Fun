#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <glm/glm.hpp>
#include "DrawVertex.hpp"
#include "Texture.hpp"

class Sprite : public DrawVertex {
public:
    Sprite(const Texture&);
    ~Sprite();
    void update(float) override;
    void render(glm::mat4) const override;
private:
    unsigned int EBO;
    const Texture& texture;
};

#endif // SPRITE_HPP
