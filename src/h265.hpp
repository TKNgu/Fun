#ifndef H265_HPP
#define H265_HPP

#include <string>
#include "Decoder.hpp"

class h265 final : public Decoder {
public:
    h265(std::string);
protected:
    void open() override;
    void play() override;
    void close() override;
private:
    const std::string url;
};

#endif // H265_HPP
