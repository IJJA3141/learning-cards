#include <iostream>

#include <memory>  // for shared_ptr, __shared_ptr_access
#include <string>  // for operator+, to_string
#include <vector>

#include "screen.h"
#include "home.h"

int main()
{
    qz::Screen* monitor = nullptr;
    ftxui::Component b = ftxui::Button("test: b", [&] 
        {
            monitor->stop();
        });
    ftxui::Component a = ftxui::Button("test: a", [&] 
        {
            monitor->swap(&b);
        });
    monitor = qz::Screen::screen(&a);
    monitor->start();

    return 0;
}

/*
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Button, Horizontal, Renderer
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for separator, gauge, text, Element, operator|, vbox, border
#include "ftxui/screen/color.hpp"
#include "ftxui/dom/node.hpp"
*/

/*
int main()
{
    ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::Fullscreen();

    ftxui::Component* nextComp = nullptr;
    bool end = false;

    ftxui::Component home = ftxui::Container::Horizontal({});
    ftxui::Component a = ftxui::Container::Vertical({});
    ftxui::Component b = ftxui::Container::Vertical({});
    
    auto toA = [&] {nextComp = &a; screen.Exit(); };
    auto toB = [&] {nextComp = &b; screen.Exit(); };
    auto quit = [&] {end = true; screen.Exit(); };
    auto toHome = [&] {nextComp = &home; screen.Exit(); };

    home->Add(ftxui::Button("a", toA));
    home->Add(ftxui::Button("b", toB));
    home->Add(ftxui::Button("Quit", quit));

    a->Add(ftxui::Button("A", toHome));
    a->Add(ftxui::Button("Quit", quit));
    b->Add(ftxui::Button("B", toHome));
    b->Add(ftxui::Button("Quit", quit));
    
    nextComp = &home;

    while (!end)
    {
        screen.Loop(*nextComp);
    }

    return 0;
}
*/