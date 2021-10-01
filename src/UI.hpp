#ifndef __UI_HPP__
#define __UI_HPP__

#include <string>

class UI {
public:
	UI();
	virtual ~UI();
	virtual std::string getName() const = 0;
};

#endif