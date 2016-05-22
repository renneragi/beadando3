#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED

#include <string>
#include <vector>

using namespace std;

class Mezo {
public:
    int _player, _i, _j;
    Mezo(int p, int i, int j): _player(p), _i(i), _j(j){}
    inline bool operator==(const Mezo &m2) const {return _i == m2._i && _j == m2._j;}
    inline bool operator!=(const Mezo &m2) const {return !(*this == m2);}
};

enum Irany {ED, KNY, EK, ENY};  // Észak-Dél, Kelet-Nyugat, Észak-Kelet, Észak-nyugat

class Vonal {
    Irany _irany;
    vector<Mezo*> mezok;
public:
    Vonal(Mezo *m1, Mezo* m2);  // ha nem szomszedosak, akkor ....
    bool addMezo(Mezo *m);      // false, ha nem esik egybe a jelenlegiekkel
};

enum LepesEredmeny {LEPES_OK=1, HIBAS_LEPES, NYERT, DONTETLEN};

class JatekMester {
private:
    int _meret;
    vector<Mezo*> _lepesek;
    vector<Mezo*> _lepesekByPlayer[2];
public:
    JatekMester(int meret) :_meret(meret){};
    LepesEredmeny lepes(Mezo *mezore);
    vector<Mezo*> getLepesek();

};

#endif // JATEKMESTER_HPP_INCLUDED
