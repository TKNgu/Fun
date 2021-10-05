#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Window.hpp"
#include "Triangle.hpp"
#include "glm/glm.hpp"
#include "Rectangle.hpp"
#include "Resource.hpp"

using namespace std;
using namespace glm;

#define FPS 60

int main() {
    try {
        auto window = WindowBuilder().setName("Fun Window").build();
        chrono::duration<double, ratio<1, FPS>> frameTime(1);
        chrono::time_point<chrono::high_resolution_clock> startTime;
        auto resource = Resource::getInstance().setPath("resource");

        try {
            const Texture& tmp = resource.loadTexture("ipad/sprite_sheet.png");
            resource.loadTexture("ipad/sprite_sheet.png");
            resource.loadTexture("ipad/bg.png");
            resource.loadTexture("ipad/font.png");
            resource.loadTexture("ipad/sprite_sheet.png");
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }

        cout << "Init" << endl;
        Triangle triangle1({-0.5f, -0.5f, 0.0f},
                           {0.5f, -0.5f, 0.0f},
                           {0.0f,  0.5f, 0.0f});

        Triangle triagle2({-0.5f, -0.5f, 0.0f},
                          {0.5f, -0.5f, 0.0f},
                          {1.0f,  0.5f, 0.0f},
                          {0.7f,  0.235f, 0.171f, 1.0f},
                          {0.7f,  0.235f, 0.171f, 1.0f},
                          {0.7f,  0.235f, 0.171f, 1.0f});

        Rectangle rectangle({0.5f, 0.5f, 1.0f},
                            {0.0f, 0.5f, 1.0f},
                            {0.0f, 0.0f, 1.0f},
                            {0.5f, 0.0f, 1.0f},
                            {0.7f,  0.235f, 0.171f, 1.0f},
                            {0.7f,  0.235f, 0.171f, 1.0f},
                            {0.7f,  0.235f, 0.171f, 1.0f},
                            {0.4f,  0.5f, 0.71f, 1.0f});

        while (!window.getIsClose()) {
            startTime = chrono::high_resolution_clock::now();

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            triangle1.render();

            triagle2.render();

            rectangle.render();

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
