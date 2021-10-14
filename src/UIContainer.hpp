#ifndef UICONTAINER_HPP
#define UICONTAINER_HPP

#include "UIComponent.hpp"

#include <glm/glm.hpp>
#include <vector>

class UIContainer : public UIComponent {
public:
    ~UIContainer();
    UIComponent& add(UIComponent*);
    void update(float) override;
    void render(glm::mat4) const override;
private:
    std::vector<UIComponent*> childrend;
};

#endif // UICONTAINER_HPP
