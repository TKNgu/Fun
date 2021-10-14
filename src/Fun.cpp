#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Window.hpp"
#include "Triangle.hpp"
#include "glm/glm.hpp"
#include "Rectangle.hpp"
#include "Resource.hpp"
#include "Sprite.hpp"
#include "UIContainer.hpp"

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

        Sprite& sprite = static_cast<Sprite&>(container.add(
                            new Sprite(Resource::getInstance().loadTexture("ipad/sprite_sheet.png"))));
        sprite.scale(vec3(0.5f, 0.5f, 1.0f));

        Triangle& triangle = static_cast<Triangle&>(container.add(
                            new Triangle({-0.5f, -0.5f, 0.0f},
                                        {0.5f, -0.5f, 0.0f},
                                        {0.0f,  0.5f, 0.0f})));
        triangle.rotate(45.0f);

//        cout << "Init" << endl;
//        Triangle triangle1({-0.5f, -0.5f, 0.0f},
//                           {0.5f, -0.5f, 0.0f},
//                           {0.0f,  0.5f, 0.0f});

//        Triangle triagle2({-0.5f, -0.5f, 0.0f},
//                          {0.5f, -0.5f, 0.0f},
//                          {1.0f,  0.5f, 0.0f},
//                          {0.7f,  0.235f, 0.171f, 1.0f},
//                          {0.7f,  0.235f, 0.171f, 1.0f},
//                          {0.7f,  0.235f, 0.171f, 1.0f});

//        Rectangle rectangle({0.5f, 0.5f, 1.0f},
//                            {0.0f, 0.5f, 1.0f},
//                            {0.0f, 0.0f, 1.0f},
//                            {0.5f, 0.0f, 1.0f},
//                            {0.7f,  0.235f, 0.171f, 1.0f},
//                            {0.7f,  0.235f, 0.171f, 1.0f},
//                            {0.7f,  0.235f, 0.171f, 1.0f},
//                            {0.4f,  0.5f, 0.71f, 1.0f});

//        auto sprite = Sprite(Resource::getInstance().loadTexture("ipad/sprite_sheet.png"));
//        sprite.translate(glm::vec3(1.0f, 1.0f, 0.0f));
//        sprite.rotate(45.0f);
//        sprite.scale(vec3(0.5f, 0.5f, 1.0f));

//        Sprite& wall = dynamic_cast<Sprite&>(rectangle.add(new Sprite(Resource::getInstance().loadTexture("wall.jpg"))));
//        wall.scale(vec3(0.25f, 0.25f, 0.0f));

        glm::mat4 renderMat = glm::mat4(1.0f);
        while (!window.getIsClose()) {
            startTime = chrono::high_resolution_clock::now();

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

//            triangle1.render(renderMap);

//            triagle2.render(renderMap);

//            rectangle.render(renderMap);

//            sprite.render(renderMap);

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
