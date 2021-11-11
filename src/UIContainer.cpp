#include "UIContainer.hpp"
#include <functional>

using namespace std;

void Execute(const vector<UIComponent*>&, function<void (UIComponent*)>);

UIContainer::~UIContainer() {
    for (auto& ui : this->childrend) {
        delete ui;
    }
}

//void UIContainer::updateRenderMat(std::function<glm::mat4 (glm::mat4)> transforms) {
//    Execute(this->childrend, [&transforms](UIComponent* ui) {
//        ui->updateRenderMat(transforms);
//    });
//}

UIComponent& UIContainer::add(UIComponent *ui) {
    this->childrend.push_back(ui);
    return *ui;
}

void UIContainer::updateRenderMat() {
    UIComponent::updateRenderMat();
    Execute(this->childrend, [this](UIComponent* ui) {
        ui->setViewMat(this->renderMat);
    });
}

void UIContainer::render() const {
    Execute(this->childrend, [this](UIComponent* ui) {
        ui->render();
    });
}

void Execute(const vector<UIComponent*>& listUI, function<void (UIComponent*)> call) {
    for (auto& ui : listUI) {
        call(ui);
    }
}
