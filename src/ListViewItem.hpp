#ifndef __LIST_VIEW_ITEM_HPP__
#define __LIST_VIEW_ITEM_HPP__

#include <string>

class ListViewItem {
public:
	virtual ~ListViewItem() {};
	virtual std::string name() const = 0;
	virtual int getId() const = 0;
	virtual bool isEnable() const = 0;
	virtual void selected(bool) = 0;
	virtual void show() const = 0;
};

#endif