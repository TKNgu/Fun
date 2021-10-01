#include "CameraListViewItemAdapter.hpp"

#include <iostream>

using namespace std;

CameraListViewItemAdapter::CameraListViewItemAdapter(const Camera& camera) :
	camera(camera) {
	//TODO
}

string CameraListViewItemAdapter::name() const {
	return this->camera.getName();
}

int CameraListViewItemAdapter::getId() const {
	return this->id;
}

void CameraListViewItemAdapter::setId(int id) {
	this->id = id;
}

void CameraListViewItemAdapter::selected(bool isSelected) {
	this->isSelected = isSelected;
}

void CameraListViewItemAdapter::show() const {
	cout << this->id << ": " << this->camera.getName();
	if (this->isSelected) {
		cout << " play " << this->camera.getUrl();
	}
	cout << endl;
}

bool CameraListViewItemAdapter::isEnable() const {
	return this->camera.getIsEnable();
}