#include "VideoProcess.hpp"

#include <iostream>

using namespace std;

VideoProcess::VideoProcess(Decoder* decoder) : decoder(decoder) {
    //TODO
}

VideoProcess::~VideoProcess() {
    cout << "Delete decoder" << std::endl;
    delete this->decoder;
}
