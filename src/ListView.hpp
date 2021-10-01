#ifndef __LIST_VIEW_HPP__
#define __LIST_VIEW_HPP__

#include<vector>
#include "ListViewItem.hpp"

class ListView {
public:
	~ListView();
	unsigned int addItem(ListViewItem*);
	void removerItem(int);
	bool select(int);
	bool unselect(int);
	void show() const;
private:
	std::vector<ListViewItem*> items;
	unsigned int countId = 0;
};

#endif