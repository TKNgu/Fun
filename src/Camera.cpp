#include "Camera.hpp"

using namespace std;

Camera::Camera(string url, string name) :
	url(url), name(name) {
	//TODO
}

string Camera::getUrl() const {
	return this->url;
}

string Camera::getName() const {
	return this->name;
}

void Camera::setName(string name) {
	this->name = name;
}

bool Camera::getIsEnable() const {
	return this->isEnable;
}

void Camera::setIsEnable(bool isEnable) {
	this->isEnable = isEnable;
}