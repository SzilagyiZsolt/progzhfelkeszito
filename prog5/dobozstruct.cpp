#include <iostream>

using namespace std;

struct Doboz {
    double szelesseg;
    double magassag;
    double melyseg;
};

int main() {
    Doboz dobozok[5];

    for (int i = 0; i < 5; i++) {
        dobozok[i].szelesseg = 10.0;
        dobozok[i].magassag = (i + 1) * 5.0;
        dobozok[i].melyseg = 10.0;
    }

    double toronyMagassaga = 0;
    
    for (int i = 0; i < 5; i++) {
        toronyMagassaga += dobozok[i].magassag; 
    }

    cout << "Ha a dobozokat egymasra tesszuk, a torony " << toronyMagassaga << " magas lesz." << endl;

    return 0;
}