#ifndef __FACTORY_UI_HPP__
#define __FACTORY_UI_HPP__

#include "UI.hpp"

enum UIType { ButtonType, CheckBoxType};

class FactoryUI {
public:
	static UI* createUI(UIType);
	~FactoryUI();
private:
	FactoryUI();
};

#endif