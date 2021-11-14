#include "UIContainer.hpp"
#include <functional>

using namespace std;

void Execute(const vector<UIComponent*>&, function<void (UIComponent*)>);

UIContainer::~UIContainer() {
    for (auto& ui : this->childrend) {
        delete ui;
    }
}

UIComponent& UIContainer::add(UIComponent *ui) {
    ui->setViewMat(this->renderMat);
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
