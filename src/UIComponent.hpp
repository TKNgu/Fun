#ifndef UICOMPONENT_HPP
#define UICOMPONENT_HPP

#include <glm/glm.hpp>

class UIComponent {
public:
    virtual ~UIComponent();
    virtual void update(float) = 0;
    virtual void render(glm::mat4) const = 0;
    void translate(glm::vec3);
    void rotate(float, glm::vec3 = glm::vec3(0.0f, 0.0f, 1.0f));
    void scale(glm::vec3);
protected:
    glm::mat4 modelMat = glm::mat4(1.0f);
};

#endif // UICOMPONENT_HPP
