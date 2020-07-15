//
// Created by lefeihu on 2020/7/15.
//

#ifndef HELLOCPP_WINDOW_MGR_H
#define HELLOCPP_WINDOW_MGR_H

#include "Screen.h"
#include <vector>

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;

    void clear(ScreenIndex);

    ScreenIndex addScreen(const Screen &);

    ScreenIndex screenCount();

    Screen& getScreen(ScreenIndex index);

private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};


#endif //HELLOCPP_WINDOW_MGR_H
