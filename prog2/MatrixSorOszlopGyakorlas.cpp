#include <iostream>

using namespace std;

// --- Segédfüggvények (ugyanazok, mint korábban) ---
int lnko(int a, int b) {
    while (b != 0) {
        int maradek = a % b;
        a = b;
        b = maradek;
    }
    return a;
}

int lkkt(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return (a * b) / lnko(a, b);
}

bool primE(int szam) {
    if (szam <= 1) return false;
    for (int i = 2; i * i <= szam; i++) {
        if (szam % i == 0) return false;
    }
    return true;
}
// --------------------------------------------------

int main() {
    int matrix[5][5] = {
        {4,  2,  9,  1,  5},
        {8,  3,  7,  2,  4},
        {1,  5,  5,  9,  8},
        {2,  4,  6,  7,  1},
        {9,  8,  3,  2,  12}
    };
    
    int meret = 5;

    // --- 1. FELADAT: Egy konkrét SOR vizsgálata ---
    // Vizsgáljuk a 2-es indexű (tehát a 3.) sort: {1, 5, 5, 9, 8}
    int vizsgaltSor = 2; 
    
    double sorOsszeg = 0;
    int sorPrimDb = 0;
    int sorLnko = matrix[vizsgaltSor][0]; // A sor első eleme a kezdőérték
    int sorLkkt = matrix[vizsgaltSor][0];

    cout << "A(z) " << vizsgaltSor << ". indexu sor elemei: ";
    for (int i = 0; i < meret; i++) {
        int aktualisElem = matrix[vizsgaltSor][i]; // Figyeld az indexelést!
        cout << aktualisElem << " ";
        
        sorOsszeg += aktualisElem;
        if (primE(aktualisElem)) sorPrimDb++;
        
        if (i > 0) {
            sorLnko = lnko(sorLnko, aktualisElem);
            sorLkkt = lkkt(sorLkkt, aktualisElem);
        }
    }
    
    cout << "\nSor atlaga: " << sorOsszeg / meret << "\nPrimek: " << sorPrimDb 
         << "\nLNKO: " << sorLnko << "\nLKKT: " << sorLkkt << endl;
         
    cout << "-----------------------------------" << endl;

    // --- 2. FELADAT: Egy konkrét OSZLOP vizsgálata ---
    // Vizsgáljuk a 0-s indexű (tehát a legelső) oszlopot: {4, 8, 1, 2, 9}
    int vizsgaltOszlop = 0; 
    
    double oszlopOsszeg = 0;
    int oszlopPrimDb = 0;
    int oszlopLnko = matrix[0][vizsgaltOszlop]; // Az oszlop első eleme a kezdőérték
    int oszlopLkkt = matrix[0][vizsgaltOszlop];

    cout << "A(z) " << vizsgaltOszlop << ". indexu oszlop elemei: ";
    for (int i = 0; i < meret; i++) {
        int aktualisElem = matrix[i][vizsgaltOszlop]; // Itt a sor indexe (i) változik!
        cout << aktualisElem << " ";
        
        oszlopOsszeg += aktualisElem;
        if (primE(aktualisElem)) oszlopPrimDb++;
        
        if (i > 0) {
            oszlopLnko = lnko(oszlopLnko, aktualisElem);
            oszlopLkkt = lkkt(oszlopLkkt, aktualisElem);
        }
    }
    
    cout << "\nOszlop atlaga: " << oszlopOsszeg / meret << "\nPrimek: " << oszlopPrimDb 
         << "\nLNKO: " << oszlopLnko << "\nLKKT: " << oszlopLkkt << endl;

    return 0;
}