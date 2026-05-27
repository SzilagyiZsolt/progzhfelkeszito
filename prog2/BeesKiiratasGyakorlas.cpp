#include <iostream>
#include <fstream>   
#include <vector>    
#include <string>    
#include <algorithm> 

using namespace std;

int main() {
    // 1. Változók deklarálása
    vector<string> szavak;
    string aktualisSzo;

    // 2. BEOLVASÁS
    ifstream forrasFajl("szavak.txt");

    // Hibakezelés: sikerült-e megnyitni?
    if (!forrasFajl.is_open()) {
        cout << "Hiba: A szavak.txt nem talalhato!" << endl;
        return 1;
    }

    // Beolvassuk a szavakat egyenként, amíg a fájl végére nem érünk
    while (forrasFajl >> aktualisSzo) {
        szavak.push_back(aktualisSzo);
    }

    forrasFajl.close();

    // 3. RENDEZÉS
    // A sort függvény karakterláncok esetén ábécé sorrendbe tesz
    sort(szavak.begin(), szavak.end());

    // 4. KIÍRÁS
    ofstream celFajl("rendezett.txt");

    if (!celFajl.is_open()) {
        cout << "Hiba: Nem sikerult letrehozni a cel-fajlt!" << endl;
        return 1;
    }

    for (const string& szo : szavak) {
        celFajl << szo << endl;
    }

    celFajl.close();

    cout << "A szavak rendezese sikeresen megtortent a 'rendezett.txt' fajlba!" << endl;

    return 0;
}