#ifndef __CHECK_BOX_HPP__
#define __CHECK_BOX_HPP__

#include "UI.hpp"

class CheckBox : public UI {
public:
	CheckBox();
	~CheckBox();
	std::string getName() const override;
};

#endif
