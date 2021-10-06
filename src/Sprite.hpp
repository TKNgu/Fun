#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <glm/glm.hpp>
#include "Rectangle.hpp"

class Sprite : public Rectangle {
public:
    Sprite(glm::vec3, glm::vec3, glm::vec3, glm::vec3);
    ~Sprite();
private:
    unsigned int EBO;
//    void render() conts override;
};

#endif // SPRITE_HPP
