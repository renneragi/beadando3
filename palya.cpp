#include "palya.hpp"
#include "jatekmester.hpp"
#include "widgets.hpp"
#include "amobaapplication.hpp"
#include "playwindow.hpp"
#include <string>
#include <vector>
using namespace std;
using namespace genv;

const int palya_meret = 40;

Palya::Palya(PlayWindow& win, int x, int y, int sx, int sy) : Widget(x, y, sx, sy), _win(win) {
    _mester = new JatekMester(palya_meret);
}

void Palya::handle(event ev) {
    if (ev.type == ev_mouse && ev.button==btn_left) {
        int mezoMeret = _size_x / palya_meret;
        Mezo *m = new Mezo(_win.getActivePlayerId(), (ev.pos_x-_x) / mezoMeret, (ev.pos_y-_y) / mezoMeret);

        // jatekmester lepes ellenorzes
        LepesEredmeny eredmeny = _mester->lepes(m);

        if (eredmeny != HIBAS_LEPES) {
            if (eredmeny == LEPES_OK) {
                _win.changeActivePlayer();
            } else if (eredmeny == NYERT) {
                _win.nyert();
            } else if (eredmeny == DONTETLEN) {
                // TODO....
//                _win.exit_event_loop();
            }
        } else {
            // nem váltjuk a jatekost, de nem is fogadjuk el a lepest!
        }
    }

}

const color player_szinek[2] = {color(255,0, 0), color(0,0,255)};

void Palya::draw() const {
    // TODO palyat kirajzolni, és az eddigi lepeseket (_lepesek) a megfelelõ szinnel
    int mezoMeret = _size_x / palya_meret;

    int k = palya_meret * mezoMeret;
    gout << move_to(_x, _y) << color(122,121,76) << box( _size_x, k-10);

    gout<<color(0,0,0);
    for (int i=0; i < palya_meret-1; i++ ) {
        gout<<move_to(_x, _y+ i*mezoMeret)<<line(k, 0);
    }
    for (int i=0; i < palya_meret-1; i++ ) {
        gout<<move_to(_x+i*mezoMeret, _y)<<line(0, k);
    }

    for(int i=0; i < _mester->getLepesek().size(); i++){
        Mezo *m = _mester->getLepesek()[i];
        gout << move_to(_x + mezoMeret * m->_i, _y + mezoMeret * m->_j);
        gout << color( player_szinek[m->_player]);
        gout << box(mezoMeret, mezoMeret);
    }
}
