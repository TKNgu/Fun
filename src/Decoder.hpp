#ifndef DECODER_HPP
#define DECODER_HPP

#include <string>

class Decoder {
public:
    virtual ~Decoder() { };
    virtual void open() = 0;
    virtual void play() = 0;
    virtual void close() = 0;
};

#endif // DECODE_HPP
