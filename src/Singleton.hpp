#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__

class Singleton {
public:
	static Singleton& getInstance();
	int getValue() const;
private:
	Singleton() { };
//	Singleton(Singleton&) = delete;
//	Singleton& operator=(Singleton&) = delete;
private:
	int value;
};

#endif