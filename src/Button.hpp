#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include "UI.hpp"

class Button : public UI {
public:
	Button();
	virtual ~Button();
	virtual std::string getName() const override;
};

#endif