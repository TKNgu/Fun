#ifndef UICOMPONENT_HPP
#define UICOMPONENT_HPP

#include <functional>
#include <glm/glm.hpp>

class UIComponent {
public:
    virtual ~UIComponent();
    void setViewMat(glm::mat4);
    virtual void transforms(std::function<glm::mat4 (glm::mat4)>);
//    void translate(glm::vec3);
//    void rotate(float, glm::vec3 = glm::vec3(0.0f, 0.0f, 1.0f));
//    void scale(glm::vec3);
    virtual void render() const = 0;
protected:
    virtual void updateRenderMat();
protected:
    glm::mat4 viewMat = glm::mat4(1.0f);
    glm::mat4 modelMat = glm::mat4(1.0f);
    glm::mat4 renderMat = glm::mat4(1.0f);
};

#endif // UICOMPONENT_HPP
