#ifndef OTOMATA_HPP
#define OTOMATA_HPP

#include <thread>

enum StateName {Start, Play, Pause, Reset, End};

class State;

class Otomata {
public:
    Otomata();
    ~Otomata();
private:
    bool controlStart(int);
    bool controlPlay(int);
    bool controlPause(int);
    bool controlReset(int);
    bool controlEnd(int);
    void controlMain();
private:
    std::thread mainControl;
    std::mutex isChangState;
    State* state = nullptr;
    bool running = true;
    std::condition_variable cv;
    StateName name;
    int value = 0;
    std::function<void ()> changState;
};

#endif // OTOMATA_HPP
