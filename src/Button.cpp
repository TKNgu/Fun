#include "Button.hpp"

#include <iostream>

using namespace std;

Button::Button() : UI() {
	cout << "Init button" << endl;
}

Button::~Button() {
	cout << "Destroy button" << endl;
}

string Button::getName() const {
	return "Button";
}