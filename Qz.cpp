#include <memory>  // for shared_ptr, __shared_ptr_access
#include <string>  // for operator+, to_string
#include <vector>

#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Button, Horizontal, Renderer
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for separator, gauge, text, Element, operator|, vbox, border

#include "readAndWrite.h"

ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::Fullscreen();
ftxui::Component component;

ftxui::Component bt = ftxui::Button("Exit", screen.ExitLoopClosure());
ftxui::Component no = ftxui::Renderer(bt, [&]{
    return bt->Render();
    });

int it = 0;

void f() {
    std::cout << "Hi!\n";
    component.swap(no);
    screen.ExitLoopClosure();
    return;
}

ftxui::Component createInputList(std::vector<std::vector<std::string>>* _strVector)
{
    ftxui::Component topParent;
    ftxui::Components compVector;

    for (int i = 0; i < _strVector->size(); i++)
    {
        compVector.push_back(ftxui::Container::Horizontal({
        ftxui::Input(&_strVector->at(i)[0], "...") | ftxui::border,
        ftxui::Input(&_strVector->at(i)[1], "...") | ftxui::border,
            }));
    }

    ftxui::Component button = ftxui::Button("No!", [&] {
        it++;
        f();});
    compVector.push_back(button);

    topParent = ftxui::Container::Vertical(compVector);

    return topParent;
}

int main(int argc, const char* argv[]) {
    std::vector<std::vector<std::string>> strVector{ {"...","..."}, {"...","..."}, {"...","..."} };

    ftxui::Component inputs = createInputList(&strVector);
    component = ftxui::Renderer(inputs, [&] {
        return ftxui::window(ftxui::text("Qz"), ftxui::flexbox({
            inputs->Render(),
            ftxui::separator(),
            })
            );
        });

    screen.Loop(component);
    screen.Loop(component);
    
    writeFile("out.txt", &strVector);

    std::cout << it;
    return 0;
}

/*
    std::string content = "";
    std::string placeholder = ".:..:::..::...";

    int value = 50;

    ftxui::Element title = ftxui::text("Title") | ftxui::center;

    ftxui::Component buttons = ftxui::Container::Horizontal({
        ftxui::Button("Decrease", [&] { value--; }),
        ftxui::Button("Increase", [&] { value++; }),
        });

    ftxui::Component in = ftxui::Container::Vertical({
        ftxui::Input(&content, &placeholder),
        });

    ftxui::Component all = ftxui::Container::Vertical({
        buttons,
        in,
        });

    ftxui::Component component = ftxui::Renderer(all, [&] {
        return ftxui::window(title, ftxui::vbox({
                   ftxui::separator(),
                   ftxui::text("value = " + std::to_string(value)),
                   ftxui::separator(),
                   ftxui::gauge(value * 0.01f),
                   ftxui::separator(),
                   buttons->Render(),
                   ftxui::filler(),
                   ftxui::separator(),
                   in->Render(),
            }));
        });



    auto ev = ftxui::CatchEvent(component, [&](ftxui::Event e) {
        if (e.is_character()) {

        }
        screen.ExitLoopClosure();
        return false;
        });

    screen.Loop(ev);

    */