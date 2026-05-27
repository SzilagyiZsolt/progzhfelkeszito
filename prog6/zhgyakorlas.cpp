#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <map>

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

void sorMinMaxKulonbseg(int matrix[3][3], int eredmeny[3]) {
    for (int i = 0; i < 3; i++) {
        int sorMin = matrix[i][0];
        int sorMax = matrix[i][0];
        
        // Végigmegyünk a sor elemein
        for (int j = 1; j < 3; j++) {
            if (matrix[i][j] < sorMin) sorMin = matrix[i][j];
            if (matrix[i][j] > sorMax) sorMax = matrix[i][j];
        }
        
        eredmeny[i] = sorMax - sorMin;
    }
}

void manipula(int& a, int& b, int& c) {
    // 1. Megkeressük a legkisebb és legnagyobb értéket
    int legkisebb = min({a, b, c});
    int legnagyobb = max({a, b, c});
    
    // 2. Felülírjuk 0-ra a legkisebbet és a legnagyobbat
    if (a == legkisebb || a == legnagyobb) a = 0;
    if (b == legkisebb || b == legnagyobb) b = 0;
    if (c == legkisebb || c == legnagyobb) c = 0;
    
    // 3. Cserék elvégzése
    swap(a, c);
    swap(b, a);
}



struct Banan {
    double suly;
    string minoseg;
    bool bio;
};

bool sulySzerintRendez(const Banan& b1, const Banan& b2) {
    return b1.suly < b2.suly;
}

void otodikFeladat() {
    vector<string> sorok;
    string aktualisSor;
    
    // 1. Fájl beolvasása vektorba
    ifstream bemenet("sorok.txt");
    if (!bemenet.is_open()) return;
    
    while (getline(bemenet, aktualisSor)) {
        sorok.push_back(aktualisSor);
    }
    bemenet.close();

    // 2. Számlálás
    map<char, int> betuGyakorisag;
    int nagybetuDb = 0;

    for (const string& sor : sorok) {
        for (char karakter : sor) {
            
            if (karakter >= 'A' && karakter <= 'Z') {
                nagybetuDb++;
                
                char kisbetu = karakter + ('a' - 'A'); 
                betuGyakorisag[kisbetu]++;
            }
            else if (karakter >= 'a' && karakter <= 'z') {
                betuGyakorisag[karakter]++;
            }
        }
    }

    // 3. Legritkább betű kikeresése
    char legritkabbBetu = ' ';
    int minElofordulas = 999999;

    // Végigmegyünk a szótáron
    for (const auto& par : betuGyakorisag) {
        if (par.second < minElofordulas) {
            minElofordulas = par.second;
            legritkabbBetu = par.first;
        }
    }

    // 4. Eredmény kiírása
    ofstream kimenet("gyakori.txt");
    if (legritkabbBetu != ' ') {
        kimenet << "A legritkabban elofordulo betu: '" << legritkabbBetu 
                << "' (" << minElofordulas << " db)\n";
    }
    kimenet << "A nagybetuk szama osszesen: " << nagybetuDb << "\n";
    kimenet.close();
}

int main() {
    cout << "--- 1. Feladat ---" << endl;
    cout << "12 es 15 LKKT-je: " << lkkt(12, 15) << endl;

    cout << "\n--- 2. Feladat ---" << endl;
    int matrix[3][3] = {
        {10, 5, 8},   // Max-Min = 10-5 = 5
        {1, 2, 9},    // Max-Min = 9-1 = 8
        {4, 4, 4}     // Max-Min = 4-4 = 0
    };
    int eredmeny[3];
    sorMinMaxKulonbseg(matrix, eredmeny);
    cout << "Kulonbsegek: " << eredmeny[0] << ", " << eredmeny[1] << ", " << eredmeny[2] << endl;

    cout << "\n--- 3. Feladat ---" << endl;
    int a = 10, b = 20, c = 30;
    cout << "Csere elott: a=" << a << ", b=" << b << ", c=" << c << endl;
    manipula(a, b, c);
    cout << "Csere utan: a=" << a << ", b=" << b << ", c=" << c << endl;

    cout << "\n--- 4. Feladat ---" << endl;
    Banan bananok[5] = {
        {150.5, "A", true},
        {120.0, "B", false},
        {200.2, "A", true},
        {100.5, "B", true},
        {175.0, "A", false}
    };
    
    sort(bananok, bananok + 5, sulySzerintRendez);
    
    cout << "Rendezett bananok sulya:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << bananok[i].suly << " gramm (Minoseg: " << bananok[i].minoseg << ")" << endl;
    }

    cout << "\n--- 5. Feladat ---" << endl;
    otodikFeladat();
    cout << "Az 5. feladat lefutott, ellenorizd a 'gyakori.txt' fajlt!" << endl;

    return 0;
}