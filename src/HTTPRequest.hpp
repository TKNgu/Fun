#ifndef __HTTP_REQUEST_HPP__
#define __HTTP_REQUEST_HPP__

#define CURL_STATICLIB

#include <string> 
#include "curl/curl.h"

class HttpRequest {
public:
	HttpRequest();
	~HttpRequest();
	std::string get(std::string);
private:
	CURL* curl;
};

#endif
