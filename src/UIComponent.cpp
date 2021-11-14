#include "UIComponent.hpp"

#include <glm/gtc/matrix_transform.hpp>

using namespace glm;
using namespace std;

UIComponent::~UIComponent() {
    //TODO
}

void UIComponent::setViewMat(glm::mat4 viewMat) {
    this->viewMat = viewMat;
    updateRenderMat();
}

void UIComponent::transforms(TransformsFunction transformsFunction) {
    this->modelMat = transformsFunction(mat4(this->modelMat));
    updateRenderMat();
}

void UIComponent::updateRenderMat() {
    this->renderMat = this->viewMat * this->modelMat;
}
