#include "h265.hpp"

#include <iostream>

using namespace std;

h265::h265(string url) : Decoder(), url(url) {
    //TODO
}

void h265::open() {
    cout << "Open " << this->url << endl;
}

void h265::play() {
    cout << "Decoder h265" << endl;
}

void h265::close() {
    cout << "Close " << this->url << endl;
}
