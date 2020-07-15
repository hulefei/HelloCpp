//
// Created by lefeihu on 2020/7/15.
//

#include "Window_mgr.h"

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = s.strings(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& s)
{
    screens.push_back(s);
    return screens.size() - 1;
}

Window_mgr::ScreenIndex Window_mgr::screenCount() {
    return screens.size();
}

Screen &Window_mgr::getScreen(Window_mgr::ScreenIndex index) {
    return screens.at(index);
}
