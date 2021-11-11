#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <functional>
#include <map>
#include <mutex>
#include <condition_variable>
#include "Window.hpp"
#include "Triangle.hpp"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "Rectangle.hpp"
#include "Resource.hpp"
#include "Sprite.hpp"
#include "UIContainer.hpp"
#include "Otomata.hpp"

using namespace std;
using namespace glm;

#define FPS 60

int main() {
    try {
        auto window = WindowBuilder().setName("Fun Window").build();
        chrono::duration<double, ratio<1, FPS>> frameTime(1);
        chrono::time_point<chrono::high_resolution_clock> startTime;
        auto resource = Resource::getInstance().setPath("resource");
        UIContainer container;
        auto& sprite = static_cast<Sprite&>(container.add(
                            new Sprite(Resource::getInstance().loadTexture("ipad/sprite_sheet.png"))));
//        sprite.scale(vec3(0.5f, 0.5f, 1.0f));
        auto& triangle = static_cast<Triangle&>(container.add(
                            new Triangle({-0.5f, -0.5f, 0.0f},
                                        {0.5f, -0.5f, 0.0f},
                                        {0.0f,  0.5f, 0.0f})));
        container.translate(glm::vec3(0.0f, 0.0f, -5.0f));
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 640.0f / 480.0f, 0.0f, 100.0f);
        glm::mat4 renderMat = view * projection;



        while (!window.getIsClose()) {
            startTime = chrono::high_resolution_clock::now();
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            container.rotate(glm::radians(50.0f), glm::vec3(1.0f, 1.0f, 1.0f));

            container.render(renderMat);
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
