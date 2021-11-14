#ifndef UICONTAINER_HPP
#define UICONTAINER_HPP

#include "UIComponent.hpp"

#include <glm/glm.hpp>
#include <vector>

class UIContainer : public UIComponent {
public:
    ~UIContainer();
    UIComponent& add(UIComponent*);
    void render() const override;
protected:
    void updateRenderMat() override;
private:
    std::vector<UIComponent*> childrend;
};

#endif // UICONTAINER_HPP
