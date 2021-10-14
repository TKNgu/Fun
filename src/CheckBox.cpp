#include "CheckBox.hpp"

#include <iostream>

using namespace std;

CheckBox::CheckBox() {
	cout << "Contructor Check Box" << endl;
}

CheckBox::~CheckBox() {
	cout << "Destroyter Check Box" << endl;
}

string CheckBox::getName() const {
	return "Check Box";
}
