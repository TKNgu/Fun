//#include <iostream>
//#include <string>
//#include <chrono>
//#include <thread>
//#include <functional>
//#include <map>
//#include <mutex>
//#include <condition_variable>
//#include "Window.hpp"
//#include "Triangle.hpp"
//#include "glm/glm.hpp"
//#include "Rectangle.hpp"
//#include "Resource.hpp"
//#include "Sprite.hpp"
//#include "UIContainer.hpp"

//using namespace std;
//using namespace glm;

//#define FPS 60

//enum StateName {Start, Play, Pause, Reset, End};

//class State {
//public:
//    State(StateName name, function<bool (StateName, int)> callBack, int value) : name(name), callBack(callBack), value(value) {
//        this->threadRunning = thread(&State::worker, this);
//    }
//    ~State() {
//        std::cout << "Delete " << this->name << " " << this->value << endl;
//        this->running = false;
//        this->threadRunning.join();
//        cout << "Join" << endl;
//    }
//private:
//    void worker() {
//        while(this->running && this->callBack(this->name, this->value++)) {
//            cout << "Update state " << this->name << " " << this->value  << endl;
//            this_thread::sleep_for(chrono::milliseconds(1000));
//        }
//    }
//private:
//    bool running = true;
//    thread threadRunning;
//    int value = 0;
//    StateName name;
//    function<bool (StateName, int)>callBack;
//};

//class Otomata {
//public:
//    Otomata();
//    ~Otomata();
//private:
//    bool controlStart(int);
//    bool controlPlay(int);
//    bool controlPause(int);
//    bool controlReset(int);
//    bool controlEnd(int);
//    void controlMain();
//private:
//    thread mainControl;
//    mutex isChangState;
//    State* state = nullptr;
//    bool running = true;
//    condition_variable cv;
//    StateName name;
//    int value = 0;
//    function<void ()> changState;
//};

//Otomata::Otomata() {
//    this->mainControl = thread(&Otomata::controlMain, this);
//    this->state = new State(StateName::Start, [this](StateName name, int value) {
//            return controlStart(value);
//    }, this->value);
//}

//Otomata::~Otomata() {
//    if (this->running) {
//        this->changState = [this](){};
//        this->running = false;
//        this->cv.notify_all();
//    }
//    this->mainControl.join();
//}

//void Otomata::controlMain() {
//    cout << "Starte" << endl;
//    while(this->running) {
//        cout << "Wait" << endl;
//        unique_lock<mutex> lck(this->isChangState);
//        this->cv.wait(lck);
//        delete this->state;
//        this->changState();
//    }
//    cout << "Exit" << endl;
//}

//bool Otomata::controlStart(int value) {
//    this->value = value;
//    if (value >= 10) {
//        this->changState = [this]() {
//            this->state = new State(StateName::Play, [this](StateName name, int value){
//                    return controlPlay(value);
//        }, this->value);
//        };
//        cout << "Notify" << endl;
//        this->cv.notify_all();
//        return false;
//    }
//    return true;
//}

//bool Otomata::controlPlay(int value) {
//    this->value = value;
//    if (value == 20 || value == 40 || value == 60 || value == 90) {
//        this->changState = [this]() {
//            this->state = new State(StateName::Pause, [this](StateName name, int value){
//                    return controlPause(value);
//        }, this->value);
//        };
//        this->cv.notify_all();
//        return false;
//    }
//    return true;
//}

//bool Otomata::controlPause(int value) {
//    this->value = value;
//    if (value == 30 || value == 50) {
//        this->changState = [this]() {
//            this->state = new State(StateName::Play, [this](StateName name, int value){
//                    return controlPlay(value);
//        }, this->value);
//        };
//        this->cv.notify_all();
//        return false;
//    } else if (value == 70 || value == 100) {
//        this->changState = [this]() {
//            this->state = new State(StateName::Reset, [this](StateName name, int value){
//                return controlReset(value);
//        }, this->value);
//        };
//        this->cv.notify_all();
//        return false;
//    }
//    return true;
//}

//bool Otomata::controlReset(int value) {
//    this->value = value;
//    if (value == 80) {
//        this->changState = [this]() {
//            this->state = new State(StateName::Play, [this](StateName name, int value){
//                return controlPlay(value);
//        }, this->value);
//        };
//        this->cv.notify_all();
//        return false;
//    } else if (value == 110) {
//        this->changState = [this]() {
//            this->state = new State(StateName::End, [this](StateName name, int value){
//                return controlEnd(value);
//        }, this->value);
//        };
//        this->cv.notify_all();
//        return false;
//    }
//    return true;
//}

//bool Otomata::controlEnd(int value) {
//    this->value = value;
//    if (value == 120) {
//        this->changState = [this]() {
//            cout << "End" << endl;
//            this->running = false;
//        };
//        this->cv.notify_all();
//        return false;
//    }
//    return true;
//}

//class CallBack {
//public:
//    CallBack(function<void (int)> callback) : callback(callback) {
//        this->threadRunning = thread(&CallBack::worker, this);
//    }
//    ~CallBack() {
//        this->running = false;
//        this->threadRunning.join();
//    }
//    void stop() {
//        this->running = false;
//    }
//private:
//    void worker() {
//        while(this->running) {
//            cout << "Call back" << endl;
//            this_thread::sleep_for(chrono::milliseconds(1000));
//            this->callback(this->value++);
//        }
//    }
//private:
//    bool running = true;
//    thread threadRunning;
//    int value = 0;
//    function<void (int)> callback;
//};

//int main() {

//    Otomata otomate;

//    try {
//        auto window = WindowBuilder().setName("Fun Window").build();
//        chrono::duration<double, ratio<1, FPS>> frameTime(1);
//        chrono::time_point<chrono::high_resolution_clock> startTime;
//        auto resource = Resource::getInstance().setPath("resource");

//        UIContainer container;

//        auto& sprite = static_cast<Sprite&>(container.add(
//                            new Sprite(Resource::getInstance().loadTexture("ipad/sprite_sheet.png"))));
//        sprite.scale(vec3(0.5f, 0.5f, 1.0f));

//        auto& triangle = static_cast<Triangle&>(container.add(
//                            new Triangle({-0.5f, -0.5f, 0.0f},
//                                        {0.5f, -0.5f, 0.0f},
//                                        {0.0f,  0.5f, 0.0f})));

////        CallBack callBack([&triangle](int value) {
////            triangle.rotate(value);
////            cout << "Value " << value << endl;
////        });
////        triangle.rotate(45.0f);

////        cout << "Init" << endl;
////        Triangle triangle1({-0.5f, -0.5f, 0.0f},
////                           {0.5f, -0.5f, 0.0f},
////                           {0.0f,  0.5f, 0.0f});

////        Triangle triagle2({-0.5f, -0.5f, 0.0f},
////                          {0.5f, -0.5f, 0.0f},
////                          {1.0f,  0.5f, 0.0f},
////                          {0.7f,  0.235f, 0.171f, 1.0f},
////                          {0.7f,  0.235f, 0.171f, 1.0f},
////                          {0.7f,  0.235f, 0.171f, 1.0f});

////        Rectangle rectangle({0.5f, 0.5f, 1.0f},
////                            {0.0f, 0.5f, 1.0f},
////                            {0.0f, 0.0f, 1.0f},
////                            {0.5f, 0.0f, 1.0f},
////                            {0.7f,  0.235f, 0.171f, 1.0f},
////                            {0.7f,  0.235f, 0.171f, 1.0f},
////                            {0.7f,  0.235f, 0.171f, 1.0f},
////                            {0.4f,  0.5f, 0.71f, 1.0f});

////        auto sprite = Sprite(Resource::getInstance().loadTexture("ipad/sprite_sheet.png"));
////        sprite.translate(glm::vec3(1.0f, 1.0f, 0.0f));
////        sprite.rotate(45.0f);
////        sprite.scale(vec3(0.5f, 0.5f, 1.0f));

////        Sprite& wall = dynamic_cast<Sprite&>(rectangle.add(new Sprite(Resource::getInstance().loadTexture("wall.jpg"))));
////        wall.scale(vec3(0.25f, 0.25f, 0.0f));

//        glm::mat4 renderMat = glm::mat4(1.0f);
//        while (!window.getIsClose()) {
//            startTime = chrono::high_resolution_clock::now();

//            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//            glClear(GL_COLOR_BUFFER_BIT);

////            triangle1.render(renderMap);

////            triagle2.render(renderMap);

////            rectangle.render(renderMap);

////            sprite.render(renderMap);

//            container.render(renderMat);

//            window.swapBuffer();
//            window.pollEvent();
//            this_thread::sleep_for(frameTime - (chrono::high_resolution_clock::now() - startTime));
//        }
////        callBack.stop();
//    } catch (runtime_error& e) {
//        cout << e.what() << endl;
//        return 1;
//    }

//    return 0;
//}


//
// Copyright (c) 2013 Mikko Mononen memon@inside.org
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

#include <stdio.h>
//#include <glad/glad.h>
#ifdef NANOVG_GLEW
#	include <GL/glew.h>
#endif
#ifdef __APPLE__
#	define GLFW_INCLUDE_GLCOREARB
#endif
#define GLFW_INCLUDE_GLEXT
#include <GLFW/glfw3.h>
#include "nanovg.h"
#define NANOVG_GL3_IMPLEMENTATION
#include "nanovg_gl.h"
#include "demo.h"
#include "perf.h"


void errorcb(int error, const char* desc)
{
    printf("GLFW error %d: %s\n", error, desc);
}

int blowup = 0;
int screenshot = 0;
int premult = 0;

static void key(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    NVG_NOTUSED(scancode);
    NVG_NOTUSED(mods);
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
        blowup = !blowup;
    if (key == GLFW_KEY_S && action == GLFW_PRESS)
        screenshot = 1;
    if (key == GLFW_KEY_P && action == GLFW_PRESS)
        premult = !premult;
}

int main()
{
    GLFWwindow* window;
    DemoData data;
    NVGcontext* vg = NULL;
    GPUtimer gpuTimer;
    PerfGraph fps, cpuGraph, gpuGraph;
    double prevt = 0, cpuTime = 0;

    if (!glfwInit()) {
        printf("Failed to init GLFW.");
        return -1;
    }

    initGraph(&fps, GRAPH_RENDER_FPS, "Frame Time");
    initGraph(&cpuGraph, GRAPH_RENDER_MS, "CPU Time");
    initGraph(&gpuGraph, GRAPH_RENDER_MS, "GPU Time");

    glfwSetErrorCallback(errorcb);
#ifndef _WIN32 // don't require this on win32, and works with more cards
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, 1);

#ifdef DEMO_MSAA
    glfwWindowHint(GLFW_SAMPLES, 4);
#endif
    window = glfwCreateWindow(1000, 600, "NanoVG", NULL, NULL);
//	window = glfwCreateWindow(1000, 600, "NanoVG", glfwGetPrimaryMonitor(), NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwSetKeyCallback(window, key);

    glfwMakeContextCurrent(window);
#ifdef NANOVG_GLEW
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK) {
        printf("Could not init glew.\n");
        return -1;
    }
    // GLEW generates GL error because it calls glGetString(GL_EXTENSIONS), we'll consume it here.
    glGetError();
#endif

#ifdef DEMO_MSAA
    vg = nvgCreateGL3(NVG_STENCIL_STROKES | NVG_DEBUG);
#else
    vg = nvgCreateGL3(NVG_ANTIALIAS | NVG_STENCIL_STROKES | NVG_DEBUG);
#endif
    if (vg == NULL) {
        printf("Could not init nanovg.\n");
        return -1;
    }

    if (loadDemoData(vg, &data) == -1)
        return -1;

    glfwSwapInterval(0);

    initGPUTimer(&gpuTimer);

    glfwSetTime(0);
    prevt = glfwGetTime();

    while (!glfwWindowShouldClose(window))
    {
        double mx, my, t, dt;
        int winWidth, winHeight;
        int fbWidth, fbHeight;
        float pxRatio;
        float gpuTimes[3];
        int i, n;

        t = glfwGetTime();
        dt = t - prevt;
        prevt = t;

        startGPUTimer(&gpuTimer);

        glfwGetCursorPos(window, &mx, &my);
        glfwGetWindowSize(window, &winWidth, &winHeight);
        glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
        // Calculate pixel ration for hi-dpi devices.
        pxRatio = (float)fbWidth / (float)winWidth;

        // Update and render
        glViewport(0, 0, fbWidth, fbHeight);
        if (premult)
            glClearColor(0,0,0,0);
        else
            glClearColor(0.3f, 0.3f, 0.32f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);

        nvgBeginFrame(vg, winWidth, winHeight, pxRatio);

        renderDemo(vg, mx,my, winWidth,winHeight, t, blowup, &data);

        renderGraph(vg, 5,5, &fps);
        renderGraph(vg, 5+200+5,5, &cpuGraph);
        if (gpuTimer.supported)
            renderGraph(vg, 5+200+5+200+5,5, &gpuGraph);

//        nvgEndFrame(vg);

        // Measure the CPU time taken excluding swap buffers (as the swap may wait for GPU)
        cpuTime = glfwGetTime() - t;

        updateGraph(&fps, dt);
        updateGraph(&cpuGraph, cpuTime);

        // We may get multiple results.
        n = stopGPUTimer(&gpuTimer, gpuTimes, 3);
        for (i = 0; i < n; i++)
            updateGraph(&gpuGraph, gpuTimes[i]);

//        if (screenshot) {
//            screenshot = 0;
//            saveScreenShot(fbWidth, fbHeight, premult, "dump.png");
//        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    freeDemoData(vg, &data);

    nvgDeleteGL3(vg);

    printf("Average Frame Time: %.2f ms\n", getGraphAverage(&fps) * 1000.0f);
    printf("          CPU Time: %.2f ms\n", getGraphAverage(&cpuGraph) * 1000.0f);
    printf("          GPU Time: %.2f ms\n", getGraphAverage(&gpuGraph) * 1000.0f);

    glfwTerminate();
    return 0;
}
