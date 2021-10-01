#include "VideoSave.hpp"

#include <iostream>
using namespace std;

VideoSave::VideoSave(Decoder* decoder, string filePath) :
    VideoProcess(decoder), filePath(filePath) {
    cout << "Open file " << this->filePath << endl;
}

VideoSave::~VideoSave() {
    cout << "Close file " << this->filePath << endl;
}

void VideoSave::run() {
    this->decoder->open();
    this->decoder->play();
    save();
}

void VideoSave::stop() {
    this->decoder->close();
    plush();
}

void VideoSave::save() {
    cout << "Save" << endl;
}

void VideoSave::plush() {
    cout << "Plush" << endl;
}
