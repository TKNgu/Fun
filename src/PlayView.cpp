#include "PlayView.hpp"

#include <iostream>

using namespace std;

PlayView::PlayView(Decoder* decoder) : VideoProcess(decoder) {
    //TODO
}

void PlayView::run() {
    this->decoder->open();
    this->decoder->play();
    render();
}

void PlayView::render() {
    cout << "Render" << endl;
}

void PlayView::stop() {
    this->decoder->close();
}
