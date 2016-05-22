#ifndef PALYA_HPP_INCLUDED
#define PALYA_HPP_INCLUDED

#include "widgets.hpp"
#include "playwindow.hpp"
#include "jatekmester.hpp"
#include <vector>

using namespace std;

class Palya : public Widget {
protected:
    PlayWindow &_win;
    JatekMester *_mester;
public:
    Palya(PlayWindow& win, int x, int y, int sx, int sy);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
//    virtual bool focusable() const {return true;};

};


#endif // PALYA_HPP_INCLUDED
