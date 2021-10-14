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
    void translate(glm::vec3);
    void rotate(float, glm::vec3 = glm::vec3(0.0f, 0.0f, 1.0f));
    void scale(glm::vec3);
private:
    unsigned int EBO;
    const Texture& texture;
    glm::mat4 modelMat = glm::mat4(1.0f);
};

#endif // SPRITE_HPP
