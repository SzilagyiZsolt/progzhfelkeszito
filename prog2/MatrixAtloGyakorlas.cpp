#include <iostream>

using namespace std;

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

// ----------------------------------------

int main() {
    int matrix[5][5] = {
        {4,  2,  9,  1,  5},
        {8,  3,  7,  2,  4},
        {1,  5,  5,  9,  8},
        {2,  4,  6,  7,  1},
        {9,  8,  3,  2,  12}
    };
    
    int meret = 5;
    
    double osszeg = 0;
    int primDb = 0;
    
    int atloLnko = matrix[0][0];
    int atloLkkt = matrix[0][0];

    cout << "A foatlo elemei: ";
    
    for (int i = 0; i < meret; i++) {
        int aktualisElem = matrix[i][i];
        cout << aktualisElem << " ";
        
        // 1. Összegzés (az átlaghoz kell)
        osszeg += aktualisElem;
        
        // 2. Prímszámok megszámolása
        if (primE(aktualisElem)) {
            primDb++;
        }
        
        // 3. LNKO és LKKT folyamatos frissítése
        if (i > 0) {
            atloLnko = lnko(atloLnko, aktualisElem);
            atloLkkt = lkkt(atloLkkt, aktualisElem);
        }
    }
    
    cout << endl << "-----------------------------------" << endl;
    
    // Átlag kiszámítása
    double atlag = osszeg / meret;
    
    // Eredmények kiírása
    cout << "Az atlo elemeinek atlaga: " << atlag << endl;
    cout << "Primszamok darabszama az atloban: " << primDb << " db" << endl;
    cout << "Az atlo elemeinek LNKO-ja: " << atloLnko << endl;
    cout << "Az atlo elemeinek LKKT-je: " << atloLkkt << endl;

    return 0;
}