#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// --- 1. ALAPVETŐ MATEMATIKAI FÜGGVÉNYEK ---

int lnko(int a, int b) {
    while (b != 0) {
        int maradek = a % b;
        a = b;
        b = maradek;
    }
    return a;
}

long long lkkt(long long a, long long b) {
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

// --- 2. STATISZTIKA KIÍRÓ FÜGGVÉNY ---
// Fontos: Az ofstream (fájlba író) változót referenciaként (&) kell átadni!
void statisztikaFajlbaIr(ofstream& kimenet, const string& nev, int elemek[], int meret) {
    double osszeg = 0;
    int primDb = 0;
    int actLnko = elemek[0];
    long long actLkkt = elemek[0];

    for (int i = 0; i < meret; i++) {
        osszeg += elemek[i];
        if (primE(elemek[i])) primDb++;
        
        if (i > 0) {
            actLnko = lnko(actLnko, elemek[i]);
            actLkkt = lkkt(actLkkt, elemek[i]);
        }
    }

    kimenet << "--- " << nev << " ---" << endl;
    kimenet << "Atlag: " << osszeg / meret << endl;
    kimenet << "Primek szama: " << primDb << " db" << endl;
    kimenet << "LNKO: " << actLnko << endl;
    kimenet << "LKKT: " << actLkkt << endl << endl;
}

// --- 3. FŐPROGRAM ---

int main() {
    int matrix[5][5];
    int meret = 5;

    // 1. MÁTRIX BEOLVASÁSA FÁJLBÓL
    ifstream bemenetiFajl("matrix.txt");
    if (!bemenetiFajl.is_open()) {
        cout << "Hiba: Nem talalhato a 'matrix.txt'!" << endl;
        return 1;
    }

    // Dupla ciklussal feltöltjük a mátrixot
    for (int i = 0; i < meret; i++) {
        for (int j = 0; j < meret; j++) {
            bemenetiFajl >> matrix[i][j];
        }
    }
    bemenetiFajl.close();

    // 2. KIMENETI FÁJL MEGNYITÁSA
    ofstream kimenetiFajl("eredmenyek.txt");
    if (!kimenetiFajl.is_open()) {
        cout << "Hiba: Nem sikerult letrehozni az 'eredmenyek.txt' fajlt!" << endl;
        return 1;
    }

    int ideiglenesTomb[5]; // Ebbe gyűjtjük ki épp az adott sort/oszlopot/átlót

    // 3/A. FŐÁTLÓ VIZSGÁLATA
    for (int i = 0; i < meret; i++) {
        ideiglenesTomb[i] = matrix[i][i];
    }
    statisztikaFajlbaIr(kimenetiFajl, "FOATLO", ideiglenesTomb, meret);

    // 3/B. SOROK VIZSGÁLATA
    for (int i = 0; i < meret; i++) {
        // Kimentjük az i. sort
        for (int j = 0; j < meret; j++) {
            ideiglenesTomb[j] = matrix[i][j];
        }
        // Létrehozunk egy szöveget, pl: "1. SOR"
        string sorNeve = to_string(i + 1) + ". SOR"; 
        statisztikaFajlbaIr(kimenetiFajl, sorNeve, ideiglenesTomb, meret);
    }

    // 3/C. OSZLOPOK VIZSGÁLATA
    for (int j = 0; j < meret; j++) {
        // Kimentjük a j. oszlopot (figyeld az indexeket, itt az 'i' a sor, az fut belül!)
        for (int i = 0; i < meret; i++) {
            ideiglenesTomb[i] = matrix[i][j];
        }
        string oszlopNeve = to_string(j + 1) + ". OSZLOP";
        statisztikaFajlbaIr(kimenetiFajl, oszlopNeve, ideiglenesTomb, meret);
    }

    kimenetiFajl.close();
    cout << "A vizsgalat veget ert! Az eredmenyek az 'eredmenyek.txt' fajlban talalhatok." << endl;

    return 0;
}