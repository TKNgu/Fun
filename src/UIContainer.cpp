#include "UIContainer.hpp"

using namespace std;

void Execute(const vector<UIComponent*>&, function<void (UIComponent*)>);

UIContainer::~UIContainer() {
    for (auto& ui : this->childrend) {
        delete ui;
    }
}

UIComponent& UIContainer::add(UIComponent *ui) {
    this->childrend.push_back(ui);
    return *ui;
}

void UIContainer::update(float dt) {
    Execute(this->childrend, [dt](UIComponent* ui) {
        ui->update(dt);
    });
}

void UIContainer::render(glm::mat4 renderMat) const {
    renderMat *= this->modelMat;
    Execute(this->childrend, [&renderMat](UIComponent* ui) {
        ui->render(renderMat);
    });
}


void Execute(const vector<UIComponent*>& listUI, function<void (UIComponent*)> call) {
    for (auto& ui : listUI) {
        call(ui);
    }
}
