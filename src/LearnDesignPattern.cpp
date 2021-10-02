#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "WindowBuilder.hpp"
#include "Window.hpp"
#include "Triangle.hpp"

using namespace std;

#define FPS 60

int main() {
    try {
        auto window = WindowBuilder().setName("Fun Window").build();
        chrono::duration<double, ratio<1, FPS>> frameTime(1);
        chrono::time_point<chrono::high_resolution_clock> startTime;

        {
            Triangle triangle;
        }

        cout << "Init" << endl;
        Triangle triangle1;

        Triangle triagle2;

        while (!window.getIsClose()) {
            startTime = chrono::high_resolution_clock::now();

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            triangle1.render();

            triagle2.render();

            window.swapBuffer();
            window.pollEvent();
            this_thread::sleep_for(frameTime - (chrono::high_resolution_clock::now() - startTime));
        }
    } catch (runtime_error& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
