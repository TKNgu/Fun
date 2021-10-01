#ifndef __CAMERA_LIST_VIEW_ITEM_ADAPTER_HPP__
#define __CAMERA_LIST_VIEW_ITEM_ADAPTER_HPP__

#include "Camera.hpp"
#include "ListViewItem.hpp"

class CameraListViewItemAdapter : public ListViewItem {
public:
	CameraListViewItemAdapter(const Camera&);
	std::string name() const override;
	virtual bool isEnable() const;
	int getId() const override;
	void setId(int);
	void selected(bool) override;
	void show() const override;
private:
	const Camera& camera;
	int id = 0;
	bool isSelected = false;
};

#endif