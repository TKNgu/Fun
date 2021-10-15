#include "FactoryUI.hpp"

#include <iostream>
#include "Button.hpp"
#include "CheckBox.hpp"

using namespace std;

FactoryUI::FactoryUI() {
	cout << "Contructor Factory UI" << endl;
}

FactoryUI::~FactoryUI() {
	cout << "Destroy Factory UI" << endl;
}

UI* FactoryUI::createUI(UIType type) {
//	switch (type) {
//	case UIType::ButtonType: {
//		return new Button;
//	}
//	case UIType::CheckBoxType: {
//		return new CheckBox;
//	}
//	default: {
//		return nullptr;
//	}
//	}
	return nullptr;
}
