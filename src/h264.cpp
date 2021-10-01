#include "h264.hpp"

#include <iostream>

using namespace std;

h264::h264(string url) : Decoder(), url(url) {
    //TODO
}

void h264::open() {
    cout << "Open " << this->url << endl;
}

void h264::play() {
    cout << "Decoder H264" << endl;
}

void h264::close() {
    cout << "Close " << this->url << endl;
}
