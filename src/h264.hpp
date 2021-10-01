#ifndef H264_HPP
#define H264_HPP

#include <string>
#include "Decoder.hpp"

class h264 final : public Decoder {
public:
    h264(std::string);
protected:
    void open() override;
    void play() override;
    void close() override;
private:
    const std::string url;
};

#endif // H264_HPP
