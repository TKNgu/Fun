#ifndef VIDEOSAVE_HPP
#define VIDEOSAVE_HPP

#include <string>
#include "VideoProcess.hpp"

class VideoSave final : public VideoProcess {
public:
    VideoSave(Decoder*, std::string);
    ~VideoSave();
    void run() override;
    void stop() override;
private:
    void save();
    void plush();
private:
    const std::string filePath;
};

#endif // VIDEOSAVE_HPP
