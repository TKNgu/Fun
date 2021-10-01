#ifndef PLAYVIEW_HPP
#define PLAYVIEW_HPP

#include <string>
#include "Decoder.hpp"
#include "VideoProcess.hpp"

class PlayView final : public VideoProcess {
public:
    PlayView(Decoder*);
    void run() override;
    void stop() override;
private:
    void render();
};

#endif // PLAYVIEW_HPP
