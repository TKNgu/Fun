#include <iostream>
#include <vector>
#include "Singleton.hpp"
#include "UI.hpp"
#include "FactoryUI.hpp"
#include "Window.hpp"
#include "WindowBuilder.hpp"
#include "Camera.hpp"
#include "ListView.hpp"
#include "ListViewItem.hpp"
#include "CameraListViewItemAdapter.hpp"
#include "curl/curl.h"
#include "HTTPRequest.hpp"
#include "PlayView.hpp"
#include "h264.hpp"
#include "h265.hpp"
#include "VideoProcess.hpp"
#include "VideoSave.hpp"

#include <stdio.h>

using namespace std;

int Day1();
int Day2();

int main() {
    bool running = true;
    string cmd;
    while (running) {
        cout << ">";
        getline(cin, cmd);
        if (cmd == "day1") {
            return Day1();
        }
        if (cmd == "day2") {
            return Day2();
        }
    }
	return 0;
}

int Day1() {
    string message("");
    try {
        HttpRequest server;
        message = server.get("https://google.com");
    } catch (runtime_error& e) {
       cout << e.what() << endl;
       return 1;
    }
    cout << message << endl;
    cout << "Hello CMake." << endl;
    auto singleton = Singleton::getInstance();
    cout << "Singleton value " << singleton.getValue() << endl;

    auto button = FactoryUI::createUI(UIType::ButtonType);
    cout << "New UI" << endl;
    cout << button->getName() << endl;
    delete button;

    auto checkbox = FactoryUI::createUI(UIType::CheckBoxType);
    cout << "New checkbox" << endl;
    cout << checkbox->getName() << endl;
    delete checkbox;

    auto window = WindowBuilder().setName("Haha").setSize(480, 640).setOpenGLType(OpenGLType::GL4).setOffset(0, 0).build();
    window.render();

    Camera cam1("rtsp://cam1", "cam1");
    cout << cam1.getUrl() << " " << cam1.getName() << endl;

    vector<Camera*> cameras;
    ListView lisetView;
    for (auto& camera : cameras) {
        auto tmp = new CameraListViewItemAdapter(*camera);
        tmp->setId(lisetView.addItem(tmp));
    }

    bool running = true;
    string cmd;
    while (running) {
        cout << ">";
        getline(cin, cmd);
        if (cmd == "ls") {
            lisetView.show();
        }
        if (cmd == "add") {
            cout << "Camera name: ";
            string name;
            cin >> name;
            cout << "URL: ";
            string url;
            cin >> url;
            auto camera = new Camera(url, name);
            cameras.push_back(camera);
            auto tmp = new CameraListViewItemAdapter(*camera);
            tmp->setId(lisetView.addItem(tmp));
        }
        if (cmd == "select") {
            int id;
            cin >> id;
            lisetView.select(id);
        }
        if (cmd == "unselect") {
            int id;
            cin >> id;
            lisetView.unselect(id);
        }
    }

    for (auto* camera : cameras) {
        delete camera;
    }
    return 0;
}

void TestProcess(VideoProcess*);

void TestView(Decoder*);

int Day2() {
    cout << "View1" << endl;
    Decoder* decoder = new h264("rtsp://camera.h264");
    TestView(decoder);

    cout << "View2" << endl;
    decoder = new h265("rtsp://camera.h265");
    TestView(decoder);

    cout << "Process" << endl;
    VideoProcess* process = new PlayView(new h264("rtsp://h264.com"));
    TestProcess(process);
    delete  process;

    cout << "Save" << endl;
    process = new VideoSave(new h264("rtsp://h264.com"), "file.h264");
    TestProcess(process);
    delete process;

    process = new VideoSave(new h265("rtsp://h265.com"), "file.h265");
    TestProcess(process);
    delete process;
}

void TestProcess(VideoProcess* process) {
    process->run();
    process->stop();
}

void TestView(Decoder* decoder) {
    auto view = new PlayView(decoder);
    view->run();
    view->stop();
    delete view;
}
