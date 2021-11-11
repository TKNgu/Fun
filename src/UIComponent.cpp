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

void UIComponent::transforms(function<mat4 (mat4)> transformsFunction) {
    this->modelMat = transformsFunction(mat4(this->modelMat));
    updateRenderMat();
}

//void UIComponent::updateRenderMat(std::function<glm::mat4 (glm::mat4)> transforms) {
//    this->renderMat = transforms(mat4(1.0f));
////    updateRenderMat();
//}

//void UIComponent::translate(vec3 vector) {
//    this->modelMat = glm::translate(this->modelMat, vector);
//    updateRenderMat();
//}

//void UIComponent::rotate(float angle, vec3 location) {
//    this->modelMat = glm::rotate(this->modelMat, glm::radians(angle), location);
//    updateRenderMat();
//}

//void UIComponent::scale(vec3 ratio) {
//    this->modelMat = glm::scale(this->modelMat, ratio);
//    updateRenderMat();
//}

void UIComponent::updateRenderMat() {
    this->renderMat = this->viewMat * this->modelMat;
}
