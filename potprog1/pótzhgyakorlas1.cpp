//1. Feladat
//Írjon operátor túlterhelést a % operátorra, melynek első paramétere egy karakterlánc, második pedig egy karakter. 
//Az op. túlterhelés visszatérési értéke egy integer, ami azt jelzi, hogy a karakter hányszor található meg a stringben.

//2. Feladat
//Írjon függvényt, amelynek egy 3x3-ös kétdimenziós tömb a paramétere, visszatérési értéke egy 3 elemű tömb, 
//amely az oszlopok maximuma és minimuma közötti különbségeket tárolja.

//3. Feladat
//Írjon függvényt, három paramétere van, visszatérési értéke pedig void. 
//Az első paraméter egy integer (a), a második egy string, ami a műveletet jelöli, a harmadik pedig egy integer, ami a művelet második operandusa lesz. 
//Valósítsa meg a növel, csökkent, szoroz, oszt műveleteket. Példa: muv(10, „szoroz”, 2), aminek a hatására az első operandus értéke megduplázódik.

//4. Feladat
//Hozzon létre egy osztályt vagy struktúrát Kutya néven, amelynek van fajtása, mérete, születési éve. 
//Írja ki a legfiatalabb kutya adatait.

//5. Feladat
//Olvassa be a randomok.txt állományt egy tetszőleges adatszerkezetbe. 
//Döntse el, hogy a két átló elemeinek szorzata közül melyik a nagyobb. 
//A nagyobb átló elemeit írja ki a nagyobb.txt-be. 1. átló: 3, 65, 7, 23, 37

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//1. feladat
int operator%(string szoveg, char karakter){
    int darab;

    for(int i=0; i<szoveg.length(); i++){
        if(szoveg[i]==karakter){
            darab++;
        }
    }
    return darab;
}

//2. Feladat
vector<int> oszlopKulonbseg(int matrix[3][3]) {
    vector<int> eredmeny;
    
    for (int j = 0; j < 3; j++) {
        int maxErt = matrix[0][j];
        int minErt = matrix[0][j];

        for (int i = 1; i < 3; i++) {
            if (matrix[i][j] > maxErt) maxErt = matrix[i][j];
            if (matrix[i][j] < minErt) minErt = matrix[i][j];
        }
        
        eredmeny.push_back(maxErt - minErt);
    }
    
    return eredmeny;
}

//3. Feladat
void muv(int& a, string muvelet, int b){
    if(muvelet=="növel"){
        a=a+b;
    }
    else if(muvelet == "csökkent"){
        a=a-b;
    }
    else if(muvelet == "szoroz"){
        a=a*b;
    }
    else if(muvelet == "oszt"){
        if(b!=0){
            a=a/b;
        }
    }
}

//4. Feladat
struct Kutya{
    string fajta;
    string meret;
    int szulev;
};

//5. Feladat

int main(){
    //1.feladat
    cout << "1. feladat" << endl;
    string szoveg="almafa";
    char karakter='a';
    cout << "A szovegben " << szoveg % karakter << " darab " << karakter << " van" << endl;

    //2.feladat
    cout << " " << endl;
    cout << "2. Feladat" << endl;
    int tesztMatrix[3][3] = {
        {1,  8, 5},
        {4,  2, 9},
        {7, 10, 3}
    };

    vector<int> kapottEredmeny = oszlopKulonbseg(tesztMatrix);

    cout << "Az oszlopok maximumanak es minimumanak kulonbsegei:" << endl;
    
    for (int i = 0; i < kapottEredmeny.size(); i++) {
        cout << (i + 1) << ". oszlop: " << kapottEredmeny[i] << endl;
    }

    //3. Feladat
    cout << " " << endl;
    cout << "3. Feladat" << endl;
    int szam=10;
    muv(szam, "szoroz", 2);
    cout << szam << endl;

    //4. Feladat
    cout << " " << endl;
    cout << "4. Feladat" << endl;
    Kutya kutyak[4]={
        {"Német Juhász", "Nagy", 2018},
        {"Tacskó", "Kicsi", 2020},
        {"Csivava", "Kicsi", 2023},
        {"Puli", "Közepes", 2017}
    };

    Kutya legfiatalabb =kutyak[0];

    for(int i=0; i<4; i++){
        if(kutyak[i].szulev>legfiatalabb.szulev){
            legfiatalabb=kutyak[i];
        }
    }

    cout << legfiatalabb.fajta << " " << legfiatalabb.meret << " " << legfiatalabb.szulev << endl;

    //5. Feladat
    int matrix[5][5];
    
    // 1. BEOLVASÁS
    ifstream beFajl("randomok.txt");
    if (!beFajl.is_open()) {
        cout << "Hiba: Nem talalhato a randomok.txt!" << endl;
        return 1; // Kilépünk hibával
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            beFajl >> matrix[i][j];
        }
    }
    beFajl.close();
    
    // 2. SZÁMOLÁS
    long long foAtlo = 1;     
    long long mellekAtlo = 1;
    
    for (int i = 0; i < 5; i++) {
        foAtlo *= matrix[i][i];         
        mellekAtlo *= matrix[i][4 - i]; 
    }
    
    // 3. ÍRÁS FÁJLBA
    ofstream kiFajl("nagyobb.txt");
    if (foAtlo > mellekAtlo) {
        for (int i = 0; i < 5; i++) kiFajl << matrix[i][i] << " ";
    } else {
        for (int i = 0; i < 5; i++) kiFajl << matrix[i][4 - i] << " ";
    }
    kiFajl.close();
    
    // --- ELLENŐRZÉS (Hogy lássuk, jól működött-e) ---
    cout << "A foatlo szorzata: " << foAtlo << endl;
    cout << "A mellekatlo szorzata: " << mellekAtlo << endl;
    
    cout << "Beolvasas a 'nagyobb.txt'-bol ellenorzeskepp: ";
    ifstream ellenorzoOlvaso("nagyobb.txt");
    int szam;
    while (ellenorzoOlvaso >> szam) {
        cout << szam << " ";
    }
    ellenorzoOlvaso.close();
    cout << endl;
}