#include "jatekmester.hpp"
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

LepesEredmeny JatekMester::lepes(Mezo *mezo) {
    for (Mezo *m :_lepesek) {
        if(*m == *mezo) return HIBAS_LEPES;
    }
    // else
    _lepesekByPlayer[mezo->_player].push_back(mezo);

    // jatek vege ellenorzes
    if(_lepesekByPlayer[0].size() + _lepesekByPlayer[1].size() == _meret * _meret)
        return DONTETLEN;

    // itt jon a lenyeg, lett-e most evvel 5 hosszu Vonal
    // befejezni

    // egyebkent
    return LEPES_OK;
}

vector<Mezo*> JatekMester::getLepesek() {
    vector<Mezo*> ered;
    ered.insert(ered.end(), _lepesekByPlayer[0].begin(), _lepesekByPlayer[0].end());
    ered.insert(ered.end(), _lepesekByPlayer[1].begin(), _lepesekByPlayer[1].end());
    return ered;
}
