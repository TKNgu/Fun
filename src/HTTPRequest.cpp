#include "HTTPRequest.hpp"

#include <stdexcept>
using namespace std;

HttpRequest::HttpRequest() {
//	this->curl = curl_easy_init();
//    if (this->curl == nullptr) {
//        throw runtime_error("Error intit CURL");
//    }
}

HttpRequest::~HttpRequest() {
//	curl_global_cleanup();
}

string HttpRequest::get(string url) {
//    curl_easy_setopt(this->curl, CURLOPT_URL, url.c_str());
//    curl_easy_setopt(this->curl, CURLOPT_PROXY, "http://proxybsh.bkav.com:3128");
//    auto res = curl_easy_perform(this->curl);
//    curl_easy_cleanup(this->curl);
//    if (res != CURLE_OK) {
//        throw runtime_error(curl_easy_strerror(res));
//    }
    return "Hello";
}
