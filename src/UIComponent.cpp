#include "UIComponent.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

using namespace glm;
using namespace std;

UIComponent::~UIComponent() {
    //TODO
}

void UIComponent::translate(vec3 vector) {
    this->modelMat = glm::translate(this->modelMat, vector);
}

void UIComponent::rotate(float angle, vec3 location) {
    this->modelMat = glm::rotate(this->modelMat, glm::radians(angle), location);
}

void UIComponent::scale(vec3 ratio) {
    this->modelMat = glm::scale(this->modelMat, ratio);

    cout << "Log" << endl;
}
