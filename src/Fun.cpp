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
#include "OpenGLUtility.hpp"
#include "Cube.hpp"

using namespace std;
using namespace glm;

#define FPS 60

int main() {
    try {
        static auto window = WindowBuilder().setName("Fun Window").build();
        chrono::duration<double, ratio<1, FPS>> frameTime(1);
        chrono::time_point<chrono::high_resolution_clock> startTime;
        auto resource = Resource::getInstance().setPath("resource");

        glm::mat4 view = glm::mat4(1.0f);
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f));
        glm::mat4 projection = glm::perspective(glm::radians(75.0f), 640.0f / 480.0f, 0.1f, 100.0f);
        glm::mat4 tmpMat = view * projection;

        UIContainer containerCube;
        containerCube.setViewMat(tmpMat);
        std::vector<UIComponent*> cubes;
        glm::vec3 cubePositions[] = {
            glm::vec3( 0.0f,  0.0f,  0.0f),
            glm::vec3( 2.0f,  5.0f, -4.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -6.3f),
            glm::vec3( 2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f,  3.0f, -7.5f),
            glm::vec3( 1.3f, -2.0f, -2.5f),
            glm::vec3( 1.5f,  2.0f, -2.5f),
            glm::vec3( 1.5f,  0.2f, -1.5f),
            glm::vec3(-1.3f,  1.0f, -1.5f)
        };
        for (int index = 0; index < 1; index++) {
            auto& cube = static_cast<Cube&>(containerCube.add(new Cube()));
            cube.transforms(OpenGLUtility::scale(glm::vec3(0.15f, 0.15f, 0.15f)));
            cube.transforms(OpenGLUtility::translate(cubePositions[index]));
            cubes.push_back(&cube);
        }

        glEnable(GL_DEPTH_TEST);
        while (!window.getIsClose()) {
            startTime = chrono::high_resolution_clock::now();
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//            int index = 0;
//            for (auto cube : cubes) {
//                index++;
//                float angle = 20.0f * index;
//                cube->transforms(OpenGLUtility::rotate(glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f)));
//            }
            containerCube.render();

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
