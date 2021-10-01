#include "ListView.hpp"

#include <algorithm>

using namespace std;

ListView::~ListView() {
	for (auto& item : this->items) {
		delete item;
	}
}

unsigned int ListView::addItem(ListViewItem* item) {
	this->items.push_back(item);
	return this->countId++;
}

void ListView::removerItem(int id) {
	this->items.erase(find_if(this->items.begin(), this->items.end(),
		[id](const ListViewItem* item) {return item->getId() == id; }));
}

bool ListView::select(int id) {
	auto tmp = find_if(this->items.begin(), this->items.end(),
		[id](const auto& item) {return item->getId() == id; });
	if (this->items.end() != tmp) {
		auto item = *tmp;
		if (item->isEnable()) {
			item->selected(true);
			return true;
		}
	}
	return false;
}

bool ListView::unselect(int id) {
	auto tmp = find_if(this->items.begin(), this->items.end(),
		[id](const auto& item) {return item->getId() == id; });
	if (tmp != this->items.end()) {
		auto item = *tmp;
		if (item->isEnable()) {
			item->selected(false);
		}
	}
	return false;
}

void ListView::show() const {
	for (auto& item : this->items) {
		item->show();
	}
}