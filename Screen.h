//
// Created by lefeihu on 2020/7/15.
//

#ifndef HELLOCPP_SCREEN_H
#define HELLOCPP_SCREEN_H


#include <string>

class Screen {
    friend class Window_mgr;

public:
    using pos = std::string::size_type;

    Screen() = default;

    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    Screen &set(char);

    Screen &set(pos, pos, char);

    inline char get(pos r, pos c) const;

    void some_member() const;

    Screen &move(pos r, pos c);

    std::string strings(size_t size, char c);

    char get() const { return contents[cursor]; }

    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }

private:
    std::string contents;
    pos cursor = 0;
    pos height = 0, width = 0;
    mutable size_t access_ctr;

    void do_display(std::ostream &os) const {
        os << contents;
    }
};


#endif //HELLOCPP_SCREEN_H
