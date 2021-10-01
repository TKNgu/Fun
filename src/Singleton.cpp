#include "Singleton.hpp"

Singleton& Singleton::getInstance() {
	static Singleton instance;
	return instance;
}

int Singleton::getValue() const {
	return this->value;
}