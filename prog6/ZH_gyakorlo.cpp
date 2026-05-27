#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include <iomanip>

using namespace std;

bool isPrime(int n) {
    // A 0, az 1 és a negatív számok nem prímek
    if (n <= 1) return false;
    
    // Elég a szám négyzetgyökéig vizsgálni az osztókat
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false; // Ha találunk osztót, nem prím
        }
    }
    return true; // Ha idáig eljutott, akkor prím
}

// Legnagyobb Közös Osztó (LNKO) - Euklideszi algoritmussal
int lnko(int a, int b) {
    while (b != 0) {
        int maradek = a % b;
        a = b;
        b = maradek;
    }
    return a;
}

// Legkisebb Közös Többszörös (LKKT)
// Kiszámításához felhasználjuk a már megírt LNKO függvényt!
int lkkt(int a, int b) {
    if (a == 0 || b == 0) return 0;
    // A képlet: (a * b) / lnko(a, b)
    return (a / lnko(a, b)) * b; // Így írva elkerüljük a túlcsordulást nagy számoknál
}

//FIBONACCI
//Mikor használd? Ha a feladat az, hogy "Írj egy függvényt, ami visszaadja az n-edik Fibonacci-számot!"
int fibonacci(int n) {
    if (n <= 1) return n; // A 0. és 1. szám önmaga
    
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b; // A következő szám a két előző összege
        a = b;     // Léptetjük az 'a'-t
        b = c;     // Léptetjük a 'b'-t
    }
    return c;
}
//FIBONACCI
//Mikor használd? Ha a feladat kifejezetten kéri, hogy "Oldd meg rekurzióval!"
int fibRekurziv(int n) {
    if (n <= 1) return n;
    return fibRekurziv(n - 1) + fibRekurziv(n - 2);
}

const int N = 4; // Mátrix mérete

void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << std::setw(3) << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//Palindrom
//Szöveg vizsgálata
bool isPalindromeString(std::string s) {
    int bal = 0;                  // Szó eleje
    int jobb = s.length() - 1;    // Szó vége

    while (bal < jobb) {
        if (s[bal] != s[jobb]) {
            return false; // Ha eltérés van, nem palindrom
        }
        bal++;   // Lépünk befelé balról
        jobb--;  // Lépünk befelé jobbról
    }
    return true; // Ha végigért és minden egyezett
}

//Palindrom
//Szám vizsgálat
bool isPalindromeNum(int n) {
    if (n < 0) return false; // A negatív számok a mínusz jel miatt sosem palindromok

    int eredeti = n;
    int megforditott = 0;

    // Számjegyek levágása és újraépítése fordítva
    while (n > 0) {
        int utolso_szamjegy = n % 10;
        megforditott = (megforditott * 10) + utolso_szamjegy;
        n = n / 10; // Levágjuk az utolsó számjegyet
    }

    return eredeti == megforditott;
}
int main()
{
    
    //PRIME keresés
    // Eredeti adatok a vektorban
    vector<int> szamok = { -5, 0, 1, 2, 3, 4, 5, 10, 13, 17, 20, 97 };
    
    // --- 1. MÓDSZER: Hagyományos For-ciklus ---
    cout << "Primek (ciklussal): ";
    for (int szam : szamok) {
        if (isPrime(szam)) {
            std::cout << szam << " ";
        }
    }
    cout << "\n";

    // --- 2. MÓDSZER: Modern C++ (std::copy_if) ---
    // Ha a prímeket egy új vektorba akarod kimenteni
    vector<int> primek;
    
    copy_if(szamok.begin(), szamok.end(), back_inserter(primek), isPrime);
    
    std::cout << "Primek (uj vektorban): ";
    for (int p : primek) {
        cout << p << " ";
    }
    cout << "\n";

    return 0;

    //----------------------------------------------------------------------------------------------------
    //LNKO és LKKT
    //#include <numeric> // 1. EZ MEGY LEGFELÜLRE!
    int a = 24;
    int b = 36;

    // 2. EZ PEDIG MEGY A MAIN-BE!
    int legnagyobb_kozos_oszto = std::gcd(a, b);
    int legkisebb_kozos_tobbszoros = std::lcm(a, b);

    std::cout << "LNKO: " << legnagyobb_kozos_oszto << "\n";
    std::cout << "LKKT: " << legkisebb_kozos_tobbszoros << "\n";

    return 0;

    //----------------------------------------------------------------------------------------------------

    //FIBONACCI
    //Mikor használd? Ha a feladat nem csak egy számot kér, hanem azt mondja: "Tölts fel egy vektort a Fibonacci-sorozat első N elemével, majd írasd ki!"
    int n = 10; // Hányadik számig akarjuk generálni?
    std::vector<int> fib;
    
    // Kezdőértékek beállítása
    fib.push_back(0); 
    fib.push_back(1);

    // Sorozat feltöltése
    for (int i = 2; i <= n; i++) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }

    // Kiíratás a képernyőre
    for (int szam : fib) {
        std::cout << szam << " ";
    }
    // Eredmény: 0 1 1 2 3 5 8 13 21 34 55

    return 0;

    //----------------------------------------------------------------------------------------------------

    //FILE-ba írás
    // 1. Megnyitás írásra (Output File Stream)
    std::ofstream kimenet("eredmeny.txt"); 

    // 2. Ellenőrzés, hogy sikerült-e megnyitni
    if (kimenet.is_open()) {
        
        // 3. Írás pontosan úgy, mint a cout esetében
        kimenet << "A legnagyobb kozos oszto: " << 6 << "\n";
        kimenet << "Ez egy ujabb sor a fajlban.\n";
        
        // 4. Fájl bezárása (ZH-n kötelező szokott lenni!)
        kimenet.close(); 
    } else {
        std::cout << "Hiba a fajl megnyitasakor!\n";
    }

    return 0;

    //----------------------------------------------------------------------------------------------------

    //File-ból olvasás
    std::ifstream bemenet("adatok.txt"); // Megnyitás olvasásra (Input)  teljes útvonalat kell megadni mert a rövid nem fog működni
    std::string sor;

    if (bemenet.is_open()) {
        // Ciklus, ami addig fut, amíg van új sor a fájlban
        while (std::getline(bemenet, sor)) { 
            std::cout << sor << "\n"; // Itt dolgozhatsz az adott sorral
        }
        bemenet.close();
    }
    return 0;

    //----------------------------------------------------------------------------------------------------
    //Mikor használd? Ha egy szóközökkel vagy sortörésekkel elválasztott számsort kell beolvasni egy fájlból, hogy aztán matekozz velük.
    std::ifstream fajl("szamok.txt");
    std::vector<int> adatok;
    int aktualis_szam;

    if (fajl.is_open()) {
        // A ">>" automatikusan átugorja a szóközöket és az entereket!
        // Addig olvas, amíg el nem fogy a fájl tartalma.
        while (fajl >> aktualis_szam) {
            adatok.push_back(aktualis_szam);
        }
        fajl.close();
    }

    // Ellenőrzésképp kiírjuk, mit olvastunk be:
    std::cout << "Beolvasott adatok: ";
    for (int szam : adatok) {
        std::cout << szam << " ";
    }

    return 0;
    //----------------------------------------------------------------------------------------------------
    //Mátrix
    int matrix[N][N] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };

    std::cout << "Eredeti matrix:" << std::endl;
    printMatrix(matrix);
    std::cout << "--------------------------" << std::endl;

    // 1. FŐÁTLÓ (Bal felső -> Jobb alsó)
    std::cout << "Foatlo elemei: ";
    for (int i = 0; i < N; i++) {
        std::cout << matrix[i][i] << " ";
    }
    std::cout << "\n\n";

    // 2. MELLÉKÁTLÓ (Jobb felső -> Bal alsó)
    std::cout << "Mellekatlo elemei: ";
    for (int i = 0; i < N; i++) {
        std::cout << matrix[i][N - 1 - i] << " ";
    }
    std::cout << "\n\n";

    //----------------------------------------------------------------------------------------------------

    //PALINDROM
    // Szöveg tesztelése
    std::string szo = "kajak";
    if (isPalindromeString(szo)) {
        std::cout << szo << " egy palindrom szo.\n";
    }

    // Szám tesztelése
    int szam = 12321;
    if (isPalindromeNum(szam)) {
        std::cout << szam << " egy palindrom szam.\n";
    }

    return 0;
}



//--------------------------------------------------------------------------------------------------------------------
//Két szám közötti legnagyobb Fibonacci
/*
#include <iostream>
#include <algorithm> // A std::swap miatt kell

int maxFib(int a, int b) {
    // Ha fordítva adták meg a számokat, megcseréljük őket
    if (a > b) std::swap(a, b); 

    int x = 0, y = 1, valasz = -1;

    // Addig generáljuk a Fibonacci számokat, amíg el nem érjük a felső határt (b)
    while (x <= b) {
        // Ha a jelenlegi szám nagyobb vagy egyenlő az alsó határnál (a), elmentjük
        if (x >= a) {
            valasz = x; 
        }
        
        // Kiszámoljuk a következőt, és léptetünk
        int kovetkezo = x + y;
        x = y;
        y = kovetkezo;
    }

    return valasz;
}

int main() {
    std::cout << maxFib(10, 100) << std::endl; // Eredmény: 89
    //vagy int also, felso
    //cin >> also;
    //cin >> felso;
    //std::cout << maxFib(also, felso) << std::endl;
    return 0;
}
*/
//--------------------------------------------------------------------------------------------------------------
// 4x4-es Kétdimenziós tömb sorainak átlaga egydimenziós tömbben
/*
#include <iostream>

// A függvény megkapja a 4x4-es mátrixot, és az üres "eredmeny" tömböt
void sorAtlagok(int matrix[4][4], double eredmeny[4]) {
    
    // Végigmegyünk a 4 soron
    for (int i = 0; i < 4; i++) {
        double osszeg = 0;
        
        // Végigmegyünk az aktuális sor 4 elemén, és összeadjuk őket
        for (int j = 0; j < 4; j++) {
            osszeg += matrix[i][j];
        }
        
        // Kiszámoljuk az átlagot (osztunk 4-gyel), és beletesszük az eredmény tömbbe
        eredmeny[i] = osszeg / 4.0;
    }
}

int main() {
    // Létrehozunk egy 4x4-es teszt mátrixot
    int peldaMatrix[4][4] = {
        {2, 4, 6, 8},     // Ennek az átlaga 5 lesz
        {1, 1, 1, 1},     // Ennek 1
        {10, 20, 30, 40}, // Ennek 25
        {0, 0, 0, 0}      // Ennek 0
    };

    // Létrehozzuk az 1 dimenziós, 4 méretű tömböt az eredményeknek
    // (Mivel az átlag lehet tizedestört, érdemes double típust használni)
    double atlagok[4];

    // Meghívjuk a függvényt
    sorAtlagok(peldaMatrix, atlagok);

    // Kiírjuk a végeredményt a képernyőre
    std::cout << "A soronkoenti atlagok:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << i + 1 << ". sor: " << atlagok[i] << std::endl;
    }

    return 0;
}
*/
//--------------------------------------------------------------------------------------------------------------

// 4x4-es Kétdimenziós tömb oszlopainak átlaga egydimenziós tömbben
/*
#include <iostream>

// A függvény megkapja a 4x4-es mátrixot, és az üres "eredmeny" tömböt
void oszlopAtlagok(int matrix[4][4], double eredmeny[4]) {
    
    // KÜLÖNBSÉG: A külső ciklus most az oszlopokon (j) megy végig balról jobbra
    for (int j = 0; j < 4; j++) {
        double osszeg = 0;
        
        // A belső ciklus a sorokon (i) lépked lefelé az adott oszlopban
        for (int i = 0; i < 4; i++) {
            // Figyeld meg az indexelést: 'i' a sor, 'j' az oszlop!
            osszeg += matrix[i][j];
        }
        
        // Kiszámoljuk az átlagot, és beletesszük a j-edik oszlop eredményébe
        eredmeny[j] = osszeg / 4.0;
    }
}

int main() {
    // Készítettem egy olyan mátrixot, ahol most az oszlopokban vannak az előző számok
    int peldaMatrix[4][4] = {
        {2, 1, 10, 0}, 
        {4, 1, 20, 0}, 
        {6, 1, 30, 0}, 
        {8, 1, 40, 0}  
    };
    // Így az 1. oszlop átlaga: (2+4+6+8)/4 = 5
    // A 2. oszlop átlaga: 1
    // A 3. oszlop átlaga: 25
    // A 4. oszlop átlaga: 0

    double atlagok[4];

    // Meghívjuk a függvényt
    oszlopAtlagok(peldaMatrix, atlagok);

    // Kiírjuk a végeredményt a képernyőre
    std::cout << "Az oszloponkenti atlagok:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << i + 1 << ". oszlop: " << atlagok[i] << std::endl;
    }

    return 0;
}
*/
//--------------------------------------------------------------------------------------------------------------

//Írjon függvényt amelynek van egy karakter (a), egy 10 méretű karakter tömb és még egy karakter (b) paramétere, visszatérési értéke void. A függvény másolja be a tömb b-edik elemének értékét az a intigerbe 
/*
#include <iostream>

// A függvény paraméterei:
// 1. char& a : Referencia, hogy az eredeti változót tudjuk felülírni
// 2. char tomb[10] : A 10 méretű karaktertömb
// 3. char b : A karakter, ami az indexet tárolja
void ertekMasolo(char& a, char tomb[10], char b) {
    
    // Bemásoljuk a tömb 'b'-edik elemét az 'a' változóba.
    a = tomb[b];
}

int main() {
    char celValtozo = 'X';
    char peldaTomb[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
    // FIGYELEM: A 'b'-nek itt egy valódi számértéket adunk (3), nem pedig a '3'-as karaktert!
    char index = 3; 
    
    ertekMasolo(celValtozo, peldaTomb, index);
    
    // Mivel az indexelés 0-tól indul, a 3-as index a 4. elemet (D) jelenti.
    std::cout << "Az 'a' valtozo uj erteke: " << celValtozo << std::endl; 
    
    return 0;
}
*/

//--------------------------------------------------------------------------------------------------------------
//Máshogy
/*
#include <iostream>

// Most az 'a' csak egy sima ertek (nem kell &)
// A 'tomb' automatikusan az eredetit modositja
void ertekVisszaMasolo(char a, char tomb[10], char b) {
    
    // Bemásoljuk az 'a' értékét a tömb 'b'-edik helyére
    tomb[b] = a;
}

int main() {
    char beirandoKarakter = 'Z'; // Ezt fogjuk betenni a tömbbe
    char peldaTomb[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
    char index = 3; // A 3-as index a 4. elemet jelenti ('D')
    
    // Meghívjuk a függvényt
    ertekVisszaMasolo(beirandoKarakter, peldaTomb, index);
    
    // Ellenőrizzük, hogy tényleg megváltozott-e a tömb:
    std::cout << "A tomb uj tartalma a 3. indexen: " << peldaTomb[index] << std::endl; 
    
    return 0;
}
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Kérjen be a felhasználótól egy egész számot majd a megadott számosságú szóköz nélküli stringet. Írja ki a képernyőre a legrövidebbet és a leghoszabbat 
/*
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    
    // 1. Bekérjük a darabszámot
    cout << "Hany szot szeretnel megadni? ";
    cin >> n;

    // Biztonsági ellenőrzés
    if (n <= 0) {
        cout << "A darabszamnak nagyobbnak kell lennie 0-nal!" << endl;
        return 0;
    }

    string aktualis, legrovidebb, leghosszabb;

    cout << "Add meg a szavakat (szokozzel vagy enterrel elvalasztva):" << endl;

    // 2. Beolvassuk a legelső szót. Kezdetben ez lesz a legrövidebb és a leghosszabb is.
    cin >> aktualis;
    legrovidebb = aktualis;
    leghosszabb = aktualis;

    // 3. Egy ciklusban beolvassuk a maradék (n-1) darab szót
    for (int i = 1; i < n; i++) {
        cin >> aktualis;
        
        // Ha az aktuális szó hossza kisebb, mint az eddigi legrövidebbé, felülírjuk
        if (aktualis.length() < legrovidebb.length()) {
            legrovidebb = aktualis;
        }
        
        // Ha az aktuális szó hossza nagyobb, mint az eddigi leghosszabbé, felülírjuk
        if (aktualis.length() > leghosszabb.length()) {
            leghosszabb = aktualis;
        }
    }

    // 4. Kiíratás a végén
    cout << "\nEredmenyek:" << endl;
    cout << "Legrovidebb szo: " << legrovidebb << endl;
    cout << "Leghosszabb szo: " << leghosszabb << endl;

    return 0;
}
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Struktúra Dobozoknak magassággal
/*
#include <iostream>

// Létrehozzuk a Doboz struktúrát
struct Doboz {
    double szelesseg;
    double magassag;
    double melyseg;
};

int main() {
    // Létrehozunk egy 5 méretű tömböt, és rögtön feltöltjük konkrét dobozokkal.
    // A kapcsos zárójelek közötti értékek sorrendje: {szélesség, magasság, mélység}
    Doboz dobozok[5] = {
        {10.5, 5.0, 10.5},  // 1. doboz (magassága: 5.0)
        {8.0,  4.2, 8.0},   // 2. doboz (magassága: 4.2)
        {12.0, 6.0, 12.0},  // 3. doboz (magassága: 6.0)
        {5.0,  3.5, 5.0},   // 4. doboz (magassága: 3.5)
        {7.5,  2.0, 7.5}    // 5. doboz (magassága: 2.0)
    };

    double toronyMagassag = 0.0;

    // Végigmegyünk a tömbön, és minden doboz magasságát hozzáadjuk az eddigiekhez
    for (int i = 0; i < 5; i++) {
        toronyMagassag += dobozok[i].magassag;
    }

    // Kiírjuk a végeredményt
    std::cout << "Ha a dobozokat egymasra tesszuk, a torony magassaga: " 
              << toronyMagassag << std::endl;

    return 0;
}
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Struktúra Dobozoknak hosszal
/*
#include <iostream>

struct Doboz {
    double szelesseg;
    double magassag;
    double melyseg;
};

int main() {
    Doboz dobozok[5] = {
        {10.5, 5.0, 10.5},  // 1. doboz (szélessége: 10.5)
        {8.0,  4.2, 8.0},   // 2. doboz (szélessége: 8.0)
        {12.0, 6.0, 12.0},  // 3. doboz (szélessége: 12.0)
        {5.0,  3.5, 5.0},   // 4. doboz (szélessége: 5.0)
        {7.5,  2.0, 7.5}    // 5. doboz (szélessége: 7.5)
    };

    double teljesHossz = 0.0;

    // Végigmegyünk a tömbön, de most a SZÉLESSÉGET adjuk hozzá az összeghez
    for (int i = 0; i < 5; i++) {
        teljesHossz += dobozok[i].szelesseg;
    }

    // Kiírjuk az új végeredményt
    std::cout << "Ha a dobozokat egymas melle tesszuk, a teljes hossz: " 
              << teljesHossz << std::endl;

    return 0;
}
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Olvassa be a random.txt állományt egy tetszőleges adatszerkezetbe. Soronként döntse el, hogy az adott sor átlaga kisebb-e mint 37. Az eldöntés eredményét (Igen/Nem) írja be soronként a kisebb.txt-be 
/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // 1. Tetszőleges adatszerkezet: kétdimenziós vektor (vektor a vektorban)
    // Ez tárolja a fájl összes sorát, soronként pedig a számokat.
    vector<vector<double>> adatok;
    
    // Fájl megnyitása olvasásra
    ifstream bemenet("random.txt");
    if (!bemenet.is_open()) {
        cout << "Hiba: Nem sikerult megnyitni a random.txt fajlt!" << endl;
        return 1; // Kilépés hibakóddal
    }

    string sorSzoveg;
    // Soronkénti beolvasás a fájlból
    while (getline(bemenet, sorSzoveg)) {
        vector<double> aktualisSor;
        stringstream ss(sorSzoveg);
        double szam;
        
        // Számok kinyerése az aktuális sorból szóközök mentén
        while (ss >> szam) {
            aktualisSor.push_back(szam);
        }
        
        // Ha nem üres a sor, hozzáadjuk a fő adatszerkezethez
        if (!aktualisSor.empty()) {
            adatok.push_back(aktualisSor);
        }
    }
    bemenet.close();

    // 2. Fájl megnyitása írásra
    ofstream kimenet("kisebb.txt");
    if (!kimenet.is_open()) {
        cout << "Hiba: Nem sikerult letrehozni a kisebb.txt fajlt!" << endl;
        return 1;
    }

    // 3. Soronkénti átlagolás és eldöntés
    for (int i = 0; i < adatok.size(); i++) {
        double osszeg = 0.0;
        
        // Végigmegyünk az adott sor elemein és összeadjuk őket
        for (int j = 0; j < adatok[i].size(); j++) {
            osszeg += adatok[i][j];
        }
        
        // Átlag kiszámítása
        double atlag = osszeg / adatok[i].size();

        // Feltétel vizsgálata és fájlba írás
        if (atlag < 37.0) {
            kimenet << "Igen\n";
        } else {
            kimenet << "Nem\n";
        }
    }
    
    kimenet.close();

    cout << "A feldolgozas sikeresen befejezodott. Eredmenyek a kisebb.txt fajlban." << endl;

    return 0;
}
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//A Mátrix Legnagyobb Elemének Keresése
/*
#include <iostream>

using namespace std;

int main() {
    // 1. Létrehozunk egy 3 soros és 4 oszlopos tesztmátrixot
    int matrix[3][4] = {
        {5, 12, 7, 2},
        {18, -4, 99, 1},
        {3, 21, 8, 42}
    };

    // 2. Kezdőértékek beállítása
    // ARANYSZABÁLY: Soha ne 0-ról indítsd a maximumot, mert mi van, ha csak negatív számok vannak?
    // Mindig a tömb/mátrix legelső elemét (0. sor, 0. oszlop) tekintjük a "bajnoknak" induláskor.
    int maxErtek = matrix[0][0]; 
    int maxI = 0; // A sor indexe
    int maxJ = 0; // Az oszlop indexe

    // 3. Dupla ciklussal végigmegyünk a mátrix összes elemén
    for (int i = 0; i < 3; i++) {         // A külső ciklus a sorokon lépked
        for (int j = 0; j < 4; j++) {     // A belső ciklus az adott sor oszlopain lépked
            
            // Ha az aktuális elem nagyobb, mint az eddigi maximum...
            if (matrix[i][j] > maxErtek) {
                maxErtek = matrix[i][j];  // ...akkor letaszítja a trónról, ő lesz az új maximum
                maxI = i;                 // ...és azonnal felírjuk a "lakcímét" (sor)
                maxJ = j;                 // ...és (oszlop)
            }
        }
    }

    // 4. Eredmény kiíratása
    cout << "A matrix legnagyobb eleme: " << maxErtek << endl;
    
    // Programozói (0-tól induló) indexek:
    cout << "Indexei (C++ szerint): i = " << maxI << ", j = " << maxJ << endl;
    
    // "Emberi" (1-től induló) sorszámozás, ha a tanár így kérné:
    cout << "Emberi nyelven: " << maxI + 1 << ". sor, " << maxJ + 1 << ". oszlop" << endl;

    return 0;
}
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Fájl tartalmának szétválogatása két külön fájlba
/*
#include <iostream>
#include <fstream> // Ez kell a fájlkezeléshez (ifstream, ofstream)

using namespace std;

int main() {
    // 1. Bemeneti fájl megnyitása olvasásra (ifstream = input file stream)
    ifstream bemenet("szamok.txt");
    
    // Mindig ellenőrizzük, hogy sikerült-e megnyitni! ZH-n ez kötelező pont.
    if (!bemenet.is_open()) {
        cout << "Hiba: Nem talalhato a szamok.txt fajl!" << endl;
        return 1; // Kilépés hibával
    }

    // 2. Kimeneti fájlok megnyitása írásra (ofstream = output file stream)
    // Ha nem léteznek, a C++ automatikusan létrehozza őket. Ha léteznek, felülírja a tartalmukat.
    ofstream pozitivKimenet("pozitiv.txt");
    ofstream negativKimenet("negativ.txt");

    // Ezeket is érdemes ellenőrizni (ritkán van hiba, de profibb így)
    if (!pozitivKimenet.is_open() || !negativKimenet.is_open()) {
        cout << "Hiba a kimeneti fajlok letrehozasakor!" << endl;
        return 1;
    }

    int aktualisSzam;

    // 3. Beolvasás és szétválogatás "röptében"
    // A "while (bemenet >> aktualisSzam)" egy zseniális C++ trükk. 
    // Automatikusan szóközönként/soronként olvas, és megáll, ha elfogyott a fájl (EOF).
    while (bemenet >> aktualisSzam) {
        
        // Szétválogatás tétele: eldöntjük, melyik fájlba menjen
        if (aktualisSzam >= 0) {
            pozitivKimenet << aktualisSzam << endl; // Beírjuk, és rakunk mögé egy entert
        } else {
            negativKimenet << aktualisSzam << endl;
        }
    }

    // 4. Fájlok lezárása (Takarítás)
    // Ha ezt kihagyod, előfordulhat, hogy az utolsó néhány szám nem íródik ki a lemezre!
    bemenet.close();
    pozitivKimenet.close();
    negativKimenet.close();

    cout << "A szetvalogatas sikeresen befejezodott!" << endl;

    return 0;
}
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Magánhangzók cseréje csillagra
/*
#include <iostream>
#include <string>

using namespace std;

int main() {
    string mondat;
    
    cout << "Kerlek, irj be egy mondatot: ";
    getline(cin, mondat);

    // Végigmegyünk a mondat minden egyes karakterén
    for (int i = 0; i < mondat.length(); i++) {
        
        // Kimentjük az aktuális karaktert egy változóba az egyszerűbb vizsgálatért
        char aktualis = mondat[i]; 

        // Ellenőrizzük, hogy magánhangzó-e (kis- és nagybetű is)
        if (aktualis == 'a' || aktualis == 'A' ||
            aktualis == 'e' || aktualis == 'E' ||
            aktualis == 'i' || aktualis == 'I' ||
            aktualis == 'o' || aktualis == 'O' ||
            aktualis == 'u' || aktualis == 'U') {
            
            // Ha igaz a feltétel, azonnal lecseréljük az eredeti stringben!
            mondat[i] = '*';
        }
    }

    // Kiírjuk a már módosított mondatot
    cout << "A modositott mondat: " << mondat << endl;

    return 0;
}
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Struktúrában mentsünk el nevet életkort súlyt, és írjuk ki a legfiatalabbat, átlagéletkort
/*
#include <iostream>
#include <string>

using namespace std;

// 1. A struktúra létrehozása
struct Szemely {
    string nev;
    int eletkor;
    double suly;
};

int main() {
    // 2. Létrehozunk egy 4 fős tömböt, és rögtön feltöltjük adatokkal
    Szemely emberek[4] = {
        {"Anna", 25, 60.5},
        {"Bela", 19, 80.0},
        {"Cecilia", 30, 65.2},
        {"David", 22, 75.4}
    };

    // Változók a számoláshoz
    double osszEletkor = 0.0;
    
    // Figyelem: Itt nem a legkisebb kort mentjük el, hanem a legfiatalabb ember INDEXÉT!
    // Ez azért fontos, mert a végén a nevét is ki akarjuk írni, nem csak a korát.
    int minIndex = 0; // Feltételezzük, hogy a 0. ember (Anna) a legfiatalabb

    // 3. Végigmegyünk a tömbön
    for (int i = 0; i < 4; i++) {
        
        // Összeadjuk a korokat az átlaghoz
        osszEletkor += emberek[i].eletkor;

        // Minimumkiválasztás: Ha az aktuális ember fiatalabb, mint az eddigi legfiatalabb...
        if (emberek[i].eletkor < emberek[minIndex].eletkor) {
            // ...akkor megjegyezzük az ő sorszámát (indexét)
            minIndex = i;
        }
    }

    // 4. Átlag kiszámítása
    double atlag = osszEletkor / 4.0;

    // 5. Eredmények kiíratása
    cout << "A legfiatalabb szemely: " << emberek[minIndex].nev 
         << " (" << emberek[minIndex].eletkor << " eves)" << endl;
         
    cout << "A csoport atlageletkora: " << atlag << " ev" << endl;

    return 0;
}
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Lineáris keresés (Van-e ilyen, és ha igen, hol?)
/*
#include <iostream>
using namespace std;

int main() {
    int tomb[6] = {12, 25, 18, 32, 29, 35};
    int n = 6;
    int i = 0;

    // 1. Ciklus: Addig megyünk, amíg el nem érjük a tömb végét (i < n) 
    // ÉS (&&) amíg a feltétel NEM teljesül (tehát nem nagyobb 30-nál)
    while (i < n && !(tomb[i] > 30)) {
        i++;
    }

    // 2. Értékelés: Ha az i kisebb, mint n, akkor idő előtt megállt a ciklus, tehát MEGTALÁLTUK
    if (i < n) {
        cout << "Van ilyen elem, az indexe: " << i << " (Erteke: " << tomb[i] << ")" << endl;
    } else {
        cout << "Nincs ilyen elem a tombben." << endl;
    }

    return 0;
}
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Kiválogatás egy másik tömbbe
/*
#include <iostream>
using namespace std;

int main() {
    int eredeti[6] = {5, 8, 11, 14, 20, 7};
    int n = 6;
    
    // A cél tömb mérete legyen ugyanakkora, mint az eredetié (ha esetleg minden elem megfelelne)
    int kigyujtott[6]; 
    int db = 0; // Ez számolja, hányat találtunk, ÉS ez lesz a cél tömb indexe is!

    for (int i = 0; i < n; i++) {
        // Feltétel: Páros szám-e? (A maradékos osztás operátora a %)
        if (eredeti[i] % 2 == 0) {
            
            // Beletesszük a cél tömb aktuális (db) helyére
            kigyujtott[db] = eredeti[i];
            db++; // Növeljük a darabszámot, így a következő találat már a következő helyre kerül
        }
    }

    // Kiíratás
    cout << "Osszesen " << db << " db paros szamot talaltam:" << endl;
    for (int i = 0; i < db; i++) {
        cout << kigyujtott[i] << " ";
    }

    return 0;
}
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Egyszerű Rendezés (Buborékrendezés)
//Csökkenő sorrendhez: Csak a relációs jelet fordítsd meg az if-ben: if (tomb[j] < tomb[j + 1])
//Struktúrák rendezése: Ha mondjuk a Szemely nevű struktúrádat kell életkor alapján növekvőbe rendezni, 
//akkor a feltétel ez lesz: if (tomb[j].eletkor > tomb[j+1].eletkor). A cserénél pedig figyelj, hogy a csere változó típusa Szemely legyen, ne int, hiszen a teljes embert cseréled, nem csak a korát!

/*
#include <iostream>
using namespace std;

int main() {
    int tomb[5] = {42, 12, 7, 88, 1};
    int n = 5;

    // A dupla ciklus (mindig így néz ki, ezt csak be kell vágni)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            
            // Ha a bal oldali elem nagyobb, mint a jobb oldali (mellette lévő)...
            if (tomb[j] > tomb[j + 1]) {
                
                // ...akkor felcseréljük őket!
                int csere = tomb[j];
                tomb[j] = tomb[j + 1];
                tomb[j + 1] = csere;
            }
        }
    }

    cout << "A rendezett tomb: ";
    for (int i = 0; i < n; i++) {
        cout << tomb[i] << " ";
    }

    return 0;
}
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Mátrix átló átlag
/*
#include <iostream>

using namespace std;

int main() {
    // Egy 3x3-as négyzetes mátrix (átlója csak négyzetes mátrixnak van!)
    int matrix[3][3] = {
        {4, 8, 2},
        {1, 5, 9},
        {7, 3, 6}
    };
    
    int meret = 3; // A mátrix mérete (N)
    double osszeg = 0.0; // Double, hogy az átlag pontos legyen

    // EGYETLEN ciklus elég!
    for (int i = 0; i < meret; i++) {
        // Hozzáadjuk a főátló aktuális elemét
        osszeg += matrix[i][i]; 
    }

    // Átlag kiszámítása
    double atlag = osszeg / meret;

    cout << "A foatlo elemeinek atlaga: " << atlag << endl;

    return 0;
}
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Szavak száma és átlagos hosszuk (Fix és Bekért verzió)
/*
#include <iostream>
#include <string>
#include <sstream> // Kötelező a szavakra bontáshoz!

using namespace std;

// Készítünk egy külön függvényt a logikának, hogy ne kelljen kétszer leírni ugyanazt
void mondatElemzo(string mondat) {
    // 1. Létrehozzuk a "darabolót" és beletöltjük a mondatot
    stringstream ss(mondat);
    string szo;
    
    int szoDarab = 0;       // Ez számolja, hány szó van
    int osszesBetu = 0;     // Ez összegzi a szavak hosszát
    
    // 2. A ciklus automatikusan szavanként olvas (a szóközöket átugorja!)
    while (ss >> szo) {
        szoDarab++;                  // Találtunk egy szót, növeljük a darabszámot
        osszesBetu += szo.length();  // Hozzáadjuk a szó hosszát az eddigiekhez
    }

    // Biztonsági ellenőrzés (0-val nem oszthatunk, ha esetleg üres lett volna a mondat)
    if (szoDarab == 0) {
        cout << "A mondat ures volt, nincsenek szavak." << endl;
        return; // Kilépünk a függvényből
    }

    // 3. Átlag kiszámítása
    // Az (double) vagy a * 1.0 azért kell, hogy ne egészosztás történjen!
    double atlag = (double)osszesBetu / szoDarab;

    // 4. Eredmények kiíratása
    cout << "A mondat: \"" << mondat << "\"" << endl;
    cout << "Szavak szama: " << szoDarab << " db" << endl;
    cout << "Szavak atlagos hossza: " << atlag << " karakter/szo\n" << endl;
}

int main() {
    // --- 1. VERZIÓ: Fixen megadott mondat ---
    cout << "--- 1. Fix mondat elemzese ---" << endl;
    string fixMondat = "Az eg kek."; 
    mondatElemzo(fixMondat);


    // --- 2. VERZIÓ: Felhasználó által megadott mondat ---
    cout << "--- 2. Felhasznaloi mondat elemzese ---" << endl;
    string bekeresMondat;
    
    cout << "Irj be egy sajat mondatot: ";
    // Kötelező a getline(), mert ha cin >> bekeresMondat lenne, megállna az első szóköz után!
    getline(cin, bekeresMondat);
    
    mondatElemzo(bekeresMondat);

    return 0;
}
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Esetleges ZH feladatok??
/*
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath> // Ez az abs() függvényhez kell (tizedestörtek abszolútértéke)

using namespace std;

// 1. FELADAT: Legnagyobb szám a határok között, ami osztható 2-vel és 3-mal
int elso_feladat(int a, int b) {
    // max(a,b)-től indulunk lefelé (hogy benne legyenek a határok is)
    for (int i = max(a, b); i >= min(a, b); i--) {
        if (i % 2 == 0 && i % 3 == 0) {
            return i;
        }
    }
    return 0; // Ha nem találtunk ilyet
}

// 2. FELADAT: 5x5-ös mátrix 5 legkisebb eleme
// JAVÍTVA: A visszatérési érték (mutató) helyett egy üres eredmény tömböt kérünk be paraméterként
void masodik_feladat(int a[5][5], int eredmeny[5]) {
    vector<int> szamok;

    // Kigyűjtjük az összes számot a vektorba
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            szamok.push_back(a[i][j]);
        }
    }

    // Sorba rendezzük növekvőbe
    sort(szamok.begin(), szamok.end());

    // Az első (legkisebb) 5 elemet áttöltjük az eredmény tömbbe
    for (int i = 0; i < 5; i++) {
        eredmeny[i] = szamok[i];
    }
}

// 3. FELADAT: 3 változó értékének körbeforgatása (a->b, b->c, c->a)
// JAVÍTVA: Sokkal rövidebb és átláthatóbb logika
void harmadik_feladat(int &a, int &b, int &c) {
    int temp = a; // Kimentjük az elsőt
    a = b;        // 'a' megkapja 'b'-t
    b = c;        // 'b' megkapja 'c'-t
    c = temp;     // 'c' megkapja a kimentett 'a'-t
}

// 4. FELADAT: Átlagos hosszhoz legközelebbi szó
void negyedik_feladat() {
    int szam;
    double atlag_hossz = 0;
    
    cout << "Hany szot fogsz megadni? ";
    cin >> szam;

    if (szam <= 0) return; // Biztonsági kilépés, ha 0-t ad meg

    vector<string> szavak;
    string szo;
    
    cout << "Add meg a szavakat:\n";
    for (int i = 0; i < szam; i++) {
        cin >> szo;
        atlag_hossz += szo.length();
        szavak.push_back(szo);
    }
    
    atlag_hossz /= (double)szam; // Átlag kiszámítása
    
    // Kezdőérték beállítása az első elemre
    double min_tavolsag = abs((double)szavak[0].length() - atlag_hossz);
    szo = szavak[0];

    // Minimumkiválasztás tételével megkeressük a legkisebb eltérést
    for (int i = 1; i < szam; i++) {
        if (abs((double)szavak[i].length() - atlag_hossz) < min_tavolsag) {
            min_tavolsag = abs((double)szavak[i].length() - atlag_hossz);
            szo = szavak[i];
        }
    }

    cout << "Az atlaghoz (" << atlag_hossz << ") legkozelebb eso szo: " << szo << endl;
}

// 5. FELADAT: Dobozok méreteinek szűrése
void otodik_feladat() {
    struct Doboz {
        double szelesseg, magassag, melyseg;
    };

    Doboz dobozok[5];

    cout << "Add meg az 5 doboz mereteit (szelesseg magassag melyseg):\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". doboz: ";
        cin >> dobozok[i].szelesseg >> dobozok[i].magassag >> dobozok[i].melyseg;
    }
    
    cout << "Megfelelo dobozok:\n";
    for (int i = 0; i < 5; i++) {
        if (dobozok[i].szelesseg >= 10 && dobozok[i].magassag >= 15 && dobozok[i].melyseg >= 12) {
            cout << "   " << dobozok[i].szelesseg << "  " << dobozok[i].magassag << "  " << dobozok[i].melyseg << endl;
        }
    }
}

// 6. FELADAT: Fájlból olvasás és írás
void hatodik_feladat() {
    ifstream fin("sorok.txt");
    
    // JAVÍTVA: Fájl megnyitásának ellenőrzése
    if (!fin.is_open()) {
        cout << "Hiba: A sorok.txt fajl nem talalhato!" << endl;
        return; 
    }

    vector<string> txt_szavak;
    string sorok;
    double sorok_szama = 0;
    double sorok_hossza = 0;

    cout << "A fajl tartalma:\n";
    while (getline(fin, sorok)) {
        cout << sorok << endl;
        sorok_hossza += sorok.length();
        sorok_szama++;
        txt_szavak.push_back(sorok);
    }
    fin.close();
    
    // JAVÍTVA: Nullával osztás elleni védelem (ha üres lenne a fájl)
    if (sorok_szama > 0) {
        cout << "Atlagos sorhossz: " << sorok_hossza / sorok_szama << endl;
    } else {
        cout << "A fajl ures volt." << endl;
    }

    ofstream fout("sorhossz.txt");
    
    // Fájl mentés ellenőrzése
    if (!fout.is_open()) {
        cout << "Hiba: Nem sikerult letrehozni a sorhossz.txt fajlt!" << endl;
        return;
    }

    for (string x : txt_szavak) {
        fout << x.length() << endl;
    }
    fout.close();
    cout << "A sorhosszok sikeresen elmentve a sorhossz.txt fajlba." << endl;
}


int main() {
    cout << "--- 1. FELADAT ---" << endl;
    cout << "Kereses 6 es 66 kozott (eredmeny): " << elso_feladat(6, 66) << endl;
    cout << "------------------\n" << endl;

    cout << "--- 2. FELADAT ---" << endl;
    int b[5][5] = {
        {4, 6, 12, 6, 88},
        {66, 5, 1, 76, 32},
        {5, 2, 8, 4, 8},
        {45, 2, 7, 2, 8},
        {99, 43, 8, 8678, 0}
    };
    int legkisebbek[5]; 
    masodik_feladat(b, legkisebbek); // Itt adjuk át a mátrixot ÉS az üres tömböt
    
    cout << "A matrix 5 legkisebb eleme: ";
    for (int i = 0; i < 5; i++) {
        cout << legkisebbek[i] << " ";
    }
    cout << "\n------------------\n" << endl;

    cout << "--- 3. FELADAT ---" << endl;
    int x = 1, y = 2, z = 3;
    cout << "Csere elott: x=" << x << ", y=" << y << ", z=" << z << endl;
    harmadik_feladat(x, y, z);
    cout << "Csere utan:  x=" << x << ", y=" << y << ", z=" << z << endl;
    cout << "------------------\n" << endl;

    cout << "--- 4. FELADAT ---" << endl;
    negyedik_feladat();
    cout << "------------------\n" << endl;
    
    cout << "--- 5. FELADAT ---" << endl;
    otodik_feladat();
    cout << "------------------\n" << endl;

    cout << "--- 6. FELADAT ---" << endl;
    hatodik_feladat();
    cout << "------------------\n" << endl;

    return 0;
}
*/