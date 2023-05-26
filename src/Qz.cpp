#include <iostream>

#include <memory>  // for shared_ptr, __shared_ptr_access
#include <string>  // for operator+, to_string
#include <vector>

#include "screen.h"
#include "home.h"

#include "ftxui/component/component.hpp"

int main()
{
    qz::Screen* pScreen = qz::Screen::screen();
    qz::HomePage* pHP = qz::HomePage::homePage();
    
    pScreen->start(&pHP->component);

    return 0;
}