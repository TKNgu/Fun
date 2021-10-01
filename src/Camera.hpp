#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <string>

class Camera {
public:
	Camera(std::string, std::string);
	std::string getUrl() const;
	std::string getName() const;
	void setName(std::string);
	void setIsEnable(bool);
	bool getIsEnable() const;
private:
	const std::string url;
	std::string name;
	bool isEnable = true;
};

#endif