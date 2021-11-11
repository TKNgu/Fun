#include "Otomata.hpp"
#include <iostream>

using namespace std;

class State {
public:
    State(StateName name, function<bool (StateName, int)> callBack, int value) : name(name), callBack(callBack), value(value) {
        this->threadRunning = thread(&State::worker, this);
    }
    ~State() {
        std::cout << "Delete " << this->name << " " << this->value << endl;
        this->running = false;
        this->threadRunning.join();
        cout << "Join" << endl;
    }
private:
    void worker() {
        while(this->running && this->callBack(this->name, this->value++)) {
            cout << "Update state " << this->name << " " << this->value  << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
    }
private:
    bool running = true;
    thread threadRunning;
    int value = 0;
    StateName name;
    function<bool (StateName, int)>callBack;
};

Otomata::Otomata() {
    this->mainControl = thread(&Otomata::controlMain, this);
    this->state = new State(StateName::Start, [this](StateName name, int value) {
            return controlStart(value);
    }, this->value);
}

Otomata::~Otomata() {
    if (this->running) {
        this->changState = [this](){};
        this->running = false;
        this->cv.notify_all();
    }
    this->mainControl.join();
}

void Otomata::controlMain() {
    cout << "Starte" << endl;
    while(this->running) {
        cout << "Wait" << endl;
        unique_lock<mutex> lck(this->isChangState);
        this->cv.wait(lck);
        delete this->state;
        this->changState();
    }
    cout << "Exit" << endl;
}

bool Otomata::controlStart(int value) {
    this->value = value;
    if (value >= 10) {
        this->changState = [this]() {
            this->state = new State(StateName::Play, [this](StateName name, int value){
                    return controlPlay(value);
        }, this->value);
        };
        cout << "Notify" << endl;
        this->cv.notify_all();
        return false;
    }
    return true;
}

bool Otomata::controlPlay(int value) {
    this->value = value;
    if (value == 20 || value == 40 || value == 60 || value == 90) {
        this->changState = [this]() {
            this->state = new State(StateName::Pause, [this](StateName name, int value){
                    return controlPause(value);
        }, this->value);
        };
        this->cv.notify_all();
        return false;
    }
    return true;
}

bool Otomata::controlPause(int value) {
    this->value = value;
    if (value == 30 || value == 50) {
        this->changState = [this]() {
            this->state = new State(StateName::Play, [this](StateName name, int value){
                    return controlPlay(value);
        }, this->value);
        };
        this->cv.notify_all();
        return false;
    } else if (value == 70 || value == 100) {
        this->changState = [this]() {
            this->state = new State(StateName::Reset, [this](StateName name, int value){
                return controlReset(value);
        }, this->value);
        };
        this->cv.notify_all();
        return false;
    }
    return true;
}

bool Otomata::controlReset(int value) {
    this->value = value;
    if (value == 80) {
        this->changState = [this]() {
            this->state = new State(StateName::Play, [this](StateName name, int value){
                return controlPlay(value);
        }, this->value);
        };
        this->cv.notify_all();
        return false;
    } else if (value == 110) {
        this->changState = [this]() {
            this->state = new State(StateName::End, [this](StateName name, int value){
                return controlEnd(value);
        }, this->value);
        };
        this->cv.notify_all();
        return false;
    }
    return true;
}

bool Otomata::controlEnd(int value) {
    this->value = value;
    if (value == 120) {
        this->changState = [this]() {
            cout << "End" << endl;
            this->running = false;
        };
        this->cv.notify_all();
        return false;
    }
    return true;
}
