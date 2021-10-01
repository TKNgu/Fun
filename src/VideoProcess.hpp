#ifndef VIDEOPROCESS_HPP
#define VIDEOPROCESS_HPP

#include "Decoder.hpp"

class VideoProcess {
public:
    VideoProcess(Decoder*);
    virtual ~VideoProcess();
    virtual void run() = 0;
    virtual void stop() = 0;
protected:
    Decoder* decoder;
};

#endif // VIDEOPROCESS_HPP
