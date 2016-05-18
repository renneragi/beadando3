/*
Feladat: Osszuk fel a 400*400-as k�perny�t 20*20-as mez�kre,
amelyek kezdetben feket�k. Fekete mez�re kattintva az feh�rre
v�lt, feh�rre kattintva pedig feket�re.
*/

#include <graphics.hpp>
#include <vector>
using namespace genv;
using namespace std;


// rajzol�st v�grehajt� m�velet
void rajzol(vector<vector<bool> > tabla, bool kijatszik);
// �rt�kv�ltoztat� m�velet
void valtoztat(vector<vector<bool> > &tabla, int x, int y);

int main() {
    bool kijatszik=true;

    vector<vector<bool> > tabla(20); // m�trix
    for (unsigned int i = 0; i < tabla.size(); i++)
        // el�jezeletlen int a fut�index a size miatt
    {
        tabla[i].resize(20); // m�trix sorainak m�retez�se
        for (unsigned int j = 0; j < tabla[i].size(); j++)
            tabla[i][j] = false; // kezd��rt�k legyen hamis (fekete)
    }
    gout.open(400,400);
    event ev;
    while (gin >> ev) {
        rajzol(tabla, kijatszik);

        if (ev.type == ev_mouse && ev.button == btn_left)
            // bal eg�rgombbal kattintottunk
        {
            kijatszik=!kijatszik;
            valtoztat(tabla, ev.pos_x, ev.pos_y);
        }
    }


    return 0;
}

void rajzol(vector<vector<bool> > tabla, bool kijatszik) {
    for (unsigned int i = 0; i < tabla.size(); i++) {
        for (unsigned int j = 0; j < tabla[i].size(); j++) {

            gout << move_to(i*20, j*20);
            if (tabla[i][j]) {
                if (kijatszik==true) {
                    gout << color(255,25,255);
                } else
                    gout << color(255,255,25);
            } else gout << color(0,34,0);
            gout << box(19,19);



        }
    }
    gout << refresh;
}

void valtoztat(vector<vector<bool> > &tabla, int x, int y) {
    tabla[x / 20][y / 20] = !tabla[x / 20][y / 20];
    // �rt�k v�ltoztat�sa az ellentettre
}
