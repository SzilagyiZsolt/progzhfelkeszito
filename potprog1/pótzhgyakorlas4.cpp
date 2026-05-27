//1. Feladat: Sztringek és Operátor túlterhelés
//Ezek a feladatok a karakterláncok bejárását és az egyedi operátorok definiálását gyakoroltatják.
    //A változat (Keresés sztringben operátorral):
    //Írjon operátor túlterhelést a * (szorzás) operátorra, melynek bal oldali operandusa egy std::string, jobb oldali operandusa pedig egy char. 
    //A művelet visszatérési értéke egy int legyen, amely megadja, hogy a megadott karakter hányszor szerepel a sztringben. (Pl.: "almakompót" * 'a' eredménye 2).

    //B változat (Sztringek összehasonlítása):
    //Írjon operátor túlterhelést a - (kivonás) operátorra! Két std::string típusú paramétert várjon. 
    //A visszatérési érték legyen egy int, amely megadja a két sztring hosszának különbségét (abszolút értékben).

    //C változat (Karakterek cseréje - operátor nélkül):
    //Írjon függvényt, amely egy karakterláncot vár paraméterként! 
    //A függvény térjen vissza egy új karakterlánccal, amelyben minden magánhangzót (a, e, i, o, u) nagybetűssé alakított.

//2. Feladat: 2D tömbök (Mátrixok) oszlop/sor szintű feldolgozása
//Itt a mátrixok indexelésén (sorok és oszlopok helyes felcserélésén a ciklusokban) van a hangsúly.

    //A változat (Oszlopok átlaga):
    //Írjon függvényt, amelynek paramétere egy 5x5-ös, egész számokat tartalmazó kétdimenziós tömb! 
    //A függvény visszatérési értéke egy 5 elemű (egydimenziós) tömb (vagy std::vector) legyen, amely az egyes oszlopok elemeinek átlagát tárolja double típusként.

    //B változat (Sorok pozitív elemeinek összege):
    //Írjon függvényt, amely egy 4x5-ös mátrixot kap paraméterül! 
    //A függvény térjen vissza egy 4 elemű tömbbel, amely minden egyes sornak csak a pozitív elemeinek összegét tartalmazza.

    //C változat (Oszloponkénti szélsőértékek):
    //Írjon függvényt, melynek paramétere egy 3x4-es mátrix! 
    //Térjen vissza egy 4 elemű tömbbel, amely minden oszlop esetében megadja az adott oszlop legnagyobb és legkisebb elemének összegét!

//3. Feladat: "Számológép" jellegű Void függvény (Referencia)
//A cél a void függvények és a referencia szerinti paraméterátadás (&) gyakorlása.

    //A változat (Sztring vezérlővel):
    //Írjon void visszatérési értékű függvényt, amely három paramétert vár:
        //Egy double típusú változót (az eredmény tárolására), referencia szerint.
        //Egy std::string-et, amely a műveletet jelöli ("osszead", "kivon", "oszt").
        //Egy double típusú számot (operandus). A függvény módosítsa az első paramétert a megadott művelet és a harmadik paraméter alapján! 
        //(Pl.: ha az 1. paraméter 10, a művelet "oszt", a 3. paraméter 2, akkor az 1. paraméter új értéke 5 legyen).

    //B változat (Karakter vezérlővel, modulus):
    //Írjon void függvényt 3 paraméterrel: egy int& (referencia), egy char műveleti jel (+, -, %), és egy int operandus. 
    //Végezze el a műveletet a referencia változón! Ha a % (maradékos osztás) műveletnél az operandus 0, írjon ki hibaüzenetet a képernyőre, és ne módosítsa az értéket!

    //C változat (Állapotmódosítás):
    //Írjon void függvényt, ami egy hős életerejét (int, referencia), egy akciót (string: "gyogyul", "sebzodik") és egy mértéket (int) vár. 
    //Módosítsa az életerőt értelemszerűen, de az életerő nem mehet 0 alá és 100 fölé!

//4. Feladat: Osztályok / Struktúrák
//A saját adattípusok létrehozása és objektumok tömbjének/vektorának kezelése a cél.

    //A változat (Keresés minimum alapján):
    //Hozzon létre egy struktúrát Hallgato néven, amelynek van nev (string), neptun_kod (string) és atlag (double) adattagja. 
    //A main függvényben hozzon létre 3 hallgatót fix adatokkal vagy bekéréssel. Keresse meg és írja ki a képernyőre a legmagasabb átlaggal rendelkező hallgató nevét és Neptun kódját!

    //B változat (Szűrés feltétel alapján):
    //Hozzon létre egy osztályt (vagy struktúrát) Termek néven (megnevezes, ar, raktarkeszlet). Hozzon létre egy 4 elemű tömböt termékekből. 
    //Írja ki a képernyőre azon termékek megnevezését, amelyekből kevesebb mint 10 darab van raktáron!

    //C változat (Számított mező alapján döntés):
    //Hozzon létre egy Auto struktúrát (tipus, gyartasi_ev, futott_km). Hozzon létre 3 autót. 
    //Számolja ki mindegyiknél az egy évre jutó átlagos kilométert (futott_km / (2026 - gyartasi_ev)), és írja ki a legkevesebbet futott autó típusát!

//5. Feladat: Fájlkezelés és Mátrix Átlók
//Ezek a feladatok az ifstream/ofstream használatát és a főátló (i == j) / mellékátló (i + j == N - 1) indexelését kérik számon.

    //A változat (Két átló összehasonlítása - ZH szintű):
    //Olvassa be a matrix.txt állományt (amely egy 4x4-es, egész számokat tartalmazó mátrixot tárol) egy kétdimenziós tömbbe!
        //Számítsa ki a főátló elemeinek összegét!
        //Számítsa ki a mellékátló elemeinek összegét!
        //A nagyobb összeget (és csak azt a számot) írja ki egy eredmeny.txt nevű fájlba!

    //B változat (Főátló maximuma és szűrés):
    //Olvassa be az adatok.txt 5x5-ös mátrixát! Keresse meg a főátló legnagyobb elemét! 
    //Válogassa ki azokat az elemeket a teljes mátrixból, amelyek kisebbek, mint ez a főátlós maximum, és írja ki őket egymás alá a kisebbek.txt fájlba!

    //C változat (Mellékátló módosítása):
    //Olvassa be a szamok.txt 5x5-ös mátrixát! A program cserélje ki a mellékátló minden elemét 0-ra! 
    //Az így módosított teljes mátrixot (5x5-ös formában, szóközökkel elválasztva) írja ki egy ujmatrix.txt fájlba!

#include <iostream>
#include <string>
#include <cmath> // Az abs() függvényhez a B változathoz
#include <fstream>

using namespace std;

//1. Feladat
// A változat: Keresés sztringben operátorral
int operator*(string s, char c) {
    int db = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c) {
            db++;
        }
    }
    return db;
}

// B változat: Sztringek összehasonlítása
int operator-(string s1, string s2) {
    return abs((int)s1.length() - (int)s2.length());
}

// C változat: Karakterek cseréje (Magánhangzó nagybetűsítés)
string nagybetusit(string s) {
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            s[i] = toupper(c); 
        }
    }
    return s;
}

//2. Feladat
// A változat: Oszlopok átlaga (5x5)
double* oszlopAtlag(int matrix[5][5]) {
    double* atlagok = new double[5]; 
    for (int j = 0; j < 5; j++) {
        double osszeg = 0;
        for (int i = 0; i < 5; i++) {
            osszeg += matrix[i][j];
        }
        atlagok[j] = osszeg / 5.0;
    }
    return atlagok;
}

// B változat: Sorok pozitív elemeinek összege (4x5)
int* pozitivSorOsszeg(int matrix[4][5]) {
    int* osszegek = new int[4];
    for (int i = 0; i < 4; i++) {
        osszegek[i] = 0;
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] > 0) {
                osszegek[i] += matrix[i][j];
            }
        }
    }
    return osszegek;
}

// C változat: Oszloponkénti min+max összeg (3x4)
int* oszlopMinMaxOsszeg(int matrix[3][4]) {
    int* eredmeny = new int[4];
    for (int j = 0; j < 4; j++) {
        int minElem = matrix[0][j];
        int maxElem = matrix[0][j];
        for (int i = 1; i < 3; i++) {
            if (matrix[i][j] < minElem) minElem = matrix[i][j];
            if (matrix[i][j] > maxElem) maxElem = matrix[i][j];
        }
        eredmeny[j] = minElem + maxElem;
    }
    return eredmeny;
}

//3. Feladat
// A változat: Sztring vezérlővel
void szamologep(double &eredmeny, string muvelet, double operandus) {
    if (muvelet == "osszead") eredmeny += operandus;
    else if (muvelet == "kivon") eredmeny -= operandus;
    else if (muvelet == "oszt") {
        if (operandus != 0) eredmeny /= operandus;
    }
}

// B változat: Karakter vezérlővel, modulus
void muveletChar(int &eredmeny, char muvelet, int operandus) {
    if (muvelet == '+') eredmeny += operandus;
    else if (muvelet == '-') eredmeny -= operandus;
    else if (muvelet == '%') {
        if (operandus == 0) cout << "Hiba: nullaval osztas!" << endl;
        else eredmeny %= operandus;
    }
}

// C változat: Állapotmódosítás (HP korlátok)
void hpModosito(int &hp, string akcio, int mertek) {
    if (akcio == "gyogyul") hp += mertek;
    else if (akcio == "sebzodik") hp -= mertek;

    if (hp < 0) hp = 0;
    if (hp > 100) hp = 100;
}

//4. Feladat
// --- Struktúrák definíciói ---
struct Hallgato {
    string nev;
    string neptun_kod;
    double atlag;
};

struct Termek {
    string megnevezes;
    int ar;
    int raktarkeszlet;
};

struct Auto {
    string tipus;
    int gyartasi_ev;
    int futott_km;
};

// --- Feladat variációk függvényei ---

// A változat: Legjobb átlagú hallgató keresése
void feladat4A() {
    cout << "--- A valtozat (Legjobb hallgato) ---" << endl;
    Hallgato h[3] = {
        {"Kiss Peter", "A1B2C3", 3.5},
        {"Nagy Anna", "X9Y8Z7", 4.8}, // Elvárt
        {"Kovacs Janos", "Q1W2E3", 2.9}
    };

    int maxIndex = 0;
    for (int i = 1; i < 3; i++) {
        if (h[i].atlag > h[maxIndex].atlag) {
            maxIndex = i;
        }
    }
    cout << "Legjobb hallgato: " << h[maxIndex].nev << " (" << h[maxIndex].neptun_kod << ")" << endl << endl;
}

// B változat: Raktárkészlet szűrés (< 10)
void feladat4B() {
    cout << "--- B valtozat (Keszlet szures < 10) ---" << endl;
    Termek t[4] = {
        {"Tolltarto", 1500, 15},
        {"Fuzet", 500, 5},     // Elvárt kiírás
        {"Taska", 12000, 2},    // Elvárt kiírás
        {"Ceruza", 200, 50}
    };

    cout << "Kritikus keszletu termekek:" << endl;
    for(int i = 0; i < 4; i++) {
        if(t[i].raktarkeszlet < 10) {
            cout << "- " << t[i].megnevezes << " (Raktaron: " << t[i].raktarkeszlet << " db)" << endl;
        }
    }
    cout << endl;
}

// C változat: Legkevesebb átlagos éves kilométert futott autó
void feladat4C() {
    cout << "--- C valtozat (Legkevesebb atlagos km) ---" << endl;
    Auto a[3] = {
        {"Ford", 2014, 150000},  // 150000 / 10 ev = 15000 km/ev
        {"Opel", 2020, 20000},   // 20000 / 4 ev = 5000 km/ev -> Elvárt
        {"Suzuki", 2004, 300000} // 300000 / 20 ev = 15000 km/ev
    };

    int minIndex = 0;
    // Feltételezzük, hogy a jelenlegi év 2024 (mint a feladatkiírásban)
    double minAtlag = (double)a[0].futott_km / (2024 - a[0].gyartasi_ev);

    for(int i = 1; i < 3; i++) {
        double atlag = (double)a[i].futott_km / (2024 - a[i].gyartasi_ev);
        if(atlag < minAtlag) {
            minAtlag = atlag;
            minIndex = i;
        }
    }
    cout << "Legkevesebbet futott auto atlagosan: " << a[minIndex].tipus << endl << endl;
}

//5. Feladat
// A változat: Főátló és mellékátló összehasonlítása (4x4)
void feladat5A() {
    int m[4][4];
    ifstream be("matrix.txt");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            be >> m[i][j];
        }
    }
    be.close();

    int foatlo = 0, mellekatlo = 0;
    for(int i = 0; i < 4; i++) {
        foatlo += m[i][i];         // Főátló: [0][0], [1][1]...
        mellekatlo += m[i][3 - i]; // Mellékátló (N-1-i, ahol N=4, így 3-i)
    }

    ofstream ki("eredmeny.txt");
    if (foatlo > mellekatlo) ki << foatlo;
    else ki << mellekatlo;
    ki.close();

    // Konzolos ellenőrzés nekünk:
    ifstream ellenoriz("eredmeny.txt");
    int eredmeny;
    ellenoriz >> eredmeny;
    cout << "A valtozat -> 'eredmeny.txt' tartalma: " << eredmeny << " (Elvart: 38)" << endl;
    ellenoriz.close();
}

// B változat: Főátló maximumánál kisebb elemek kigyűjtése (5x5)
void feladat5B() {
    int m[5][5];
    ifstream be("adatok.txt");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            be >> m[i][j];
        }
    }
    be.close();

    int maxFo = m[0][0];
    for(int i = 1; i < 5; i++) {
        if(m[i][i] > maxFo) {
            maxFo = m[i][i];
        }
    }

    ofstream ki("kisebbek.txt");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(m[i][j] < maxFo) {
                ki << m[i][j] << " ";
            }
        }
    }
    ki.close();
    cout << "B valtozat -> 'kisebbek.txt' sikeresen letrehozva a 10-nel kisebb szamokkal." << endl;
}

// C változat: Mellékátló nullázása (5x5)
void feladat5C() {
    int m[5][5];
    ifstream be("szamok.txt");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            be >> m[i][j];
        }
    }
    be.close();

    // Mellékátló nullázása (N=5, így az oszlopindex: 4 - i)
    for(int i = 0; i < 5; i++) {
        m[i][4 - i] = 0; 
    }

    ofstream ki("ujmatrix.txt");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            ki << m[i][j] << " ";
        }
        ki << endl;
    }
    ki.close();

    // Konzolos ellenőrzés nekünk (kiírjuk hogyan néz ki a módosított fájl):
    cout << "C valtozat -> 'ujmatrix.txt' (a mellekatloban 0-knak kell lenniuk):" << endl;
    ifstream ellenoriz("ujmatrix.txt");
    string sor;
    while(getline(ellenoriz, sor)) {
        cout << "   " << sor << endl;
    }
    ellenoriz.close();
}

int main() {
//1. Feladat
    cout << "--- 1. FELADAT ELLENORZESE ---" << endl;

    // A változat tesztelése
    string szo = "almakompot";
    char karakter = 'a';
    int db = szo * karakter;
    cout << "A valtozat ('" << szo << "' * '" << karakter << "'): " << db << " db talalat. (Elvart: 2)" << endl;

    // B változat tesztelése
    string s1 = "programozas"; // 11 karakter
    string s2 = "info";        // 4 karakter
    int kulonbseg = s1 - s2;
    cout << "B valtozat (\"" << s1 << "\" - \"" << s2 << "\"): " << kulonbseg << ". (Elvart: 7)" << endl;

    // C változat tesztelése
    string szoveg = "szia jovo heten potzh";
    string modositott = nagybetusit(szoveg);
    cout << "C valtozat (Eredeti):   " << szoveg << endl;
    cout << "C valtozat (Modositott): " << modositott << " (Elvart: szIA jOvO hEtEn pOtzh)" << endl;

//2. Feladat
    cout << "--- 2. FELADAT ELLENORZESE ---" << endl;

    // A változat tesztelése (Minden oszlop összege mas, igy az atlaguk is)
    int m5x5[5][5] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}
    };
    double* resA = oszlopAtlag(m5x5);
    cout << "A valtozat (Oszlopatlagok): ";
    for(int i = 0; i < 5; i++) cout << resA[i] << " "; // Elvárt: 1 2 3 4 5
    cout << endl;
    delete[] resA; // Dinamikus tömb felszabadítása

    // B változat tesztelése (Negatív számokat nem szabad hozzáadnia)
    int m4x5[4][5] = {
        {-1,  2, -3,  4,  5},  // Pozitívak: 2 + 4 + 5 = 11
        { 0,  0,  1,  1, -5},  // Pozitívak: 1 + 1 = 2
        {-2, -3, -4, -5,  6},  // Pozitívak: 6
        { 1,  1,  1,  1,  1}   // Pozitívak: 5
    };
    int* resB = pozitivSorOsszeg(m4x5);
    cout << "B valtozat (Pozitiv sorosszegek): ";
    for(int i = 0; i < 4; i++) cout << resB[i] << " "; // Elvárt: 11 2 6 5
    cout << endl;
    delete[] resB;

    // C változat tesztelése (Legkisebb + legnagyobb oszloponként)
    int m3x4[3][4] = {
        {10, 20, 30, 40}, // Maxok
        { 1,  2,  3,  4}, // Minok
        { 5,  5,  5,  5}
    };
    int* resC = oszlopMinMaxOsszeg(m3x4);
    cout << "C valtozat (Min+Max oszloponkent): ";
    for(int i = 0; i < 4; i++) cout << resC[i] << " "; // Elvárt: 11 22 33 44
    cout << endl;
    delete[] resC;

//3. Feladat
    cout << "--- 3. FELADAT ELLENORZESE ---" << endl;

    // A változat tesztelése (Referencia miatt a valtozo erteke helyben módosul)
    double szamA = 10.0;
    szamologep(szamA, "oszt", 2.0);
    cout << "A valtozat (10 osztva 2-vel): " << szamA << " (Elvart: 5)" << endl;

    // B változat tesztelése
    int szamB = 17;
    muveletChar(szamB, '%', 5);
    cout << "B valtozat (17 % 5 maradeka): " << szamB << " (Elvart: 2)" << endl;

    // C változat tesztelése (Korlátok ellenőrzése)
    int eletEro = 90;
    hpModosito(eletEro, "gyogyul", 20); // 90 + 20 = 110 lenne, de max 100 lehet
    cout << "C valtozat (90 HP + 20 gyogyulas): " << eletEro << " HP (Elvart: 100)" << endl;

    hpModosito(eletEro, "sebzodik", 150); // 100 - 150 = -50 lenne, de min 0 lehet
    cout << "C valtozat (100 HP - 150 sebzodes): " << eletEro << " HP (Elvart: 0)" << endl;

//4. Feladat
    cout << "===== 4. FELADAT ELLENORZESE =====" << endl << endl;
    
    feladat4A();
    feladat4B();
    feladat4C();

//5. Feladat
    cout << "===== 5. FELADAT ELLENORZESE =====" << endl << endl;

    feladat5A();
    cout << endl;
    feladat5B();
    cout << endl;
    feladat5C();
}