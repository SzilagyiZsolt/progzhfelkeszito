#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

/**
1.	Írjon függvényt, amelynek két integer paramétere van, 
a visszatérési értéke pedig a két szám közötti legnagyobb fibonacci szám.
*/

int legnagyobbf(int a, int b){
    int legnagyobb = -1;
    int x=0;
    int y=1;
    while(x<=b){
        if(x>=a){
            legnagyobb = x;
        }
        int kov = x+y;
        x=y;
        y=kov;
    }
    return legnagyobb;
}

/*
2.	Írjon függvényt, amelynek egy 4x4-es kétdimenziós tömb a paramétere és 
visszaadja a soronkénti átlagokat egy egydimenziós 4 méretű tömbben.
*/

int* soratlag(int t[4][4]){
    int* visszaad = new int[4];

    return visszaad;
}

//vagy

array<double, 4> soratlag2(int t[4][4]){
    array<double, 4> atlagok;

    for(int i=0; i<4; i++){
        int osszeg=0;
        for(int j=0; j<4; j++){
            osszeg+=t[i][j];
        }

        atlagok[i]=(double)osszeg/4.0;
    }
    return atlagok;
}

/* 
3.	Írjon függvényt, amelynek van egy karakter (a), egy 10 méretű karakter tömb és egy karakter (b) paramétere,
 visszatérési értéke void. A függvény másolja be a tömb b-edik elemének értékét az a integerbe.
*/
void fv3(char& a, char ct[10], int b){
    a=ct[b];
}

/*
5.	Hozzon létre egy osztályt vagy struktúrát Doboz néven, amelynek van szélessége, magassága, mélysége. 
Töltsön fel egy 5 méretű tömböt dobozokkal. Írja ki, hogy ha ezeket a dobozokat egymás tetejére tesszük, 
milyen magas lesz a torony.
*/
struct Doboz{
    int szelesseg;
    int magassag;
    int melyseg;
};


int main(){
    cout << legnagyobbf(1,10) << endl;    //1. Feladat

    int temp[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};    //2. Feladat
    int* sa =soratlag(temp);
    //vagy
    for(double d: soratlag2(temp)){
        cout << d << " ";
    }
    cout << endl;

/*
4.	Kérjen be a felhasználótól egy egész számot, majd a megadott számosságú szóköz nélküli stringet. 
Írja ki a képernyőre a legrövidebbet és leghosszabbat.
*/
    int n;
    cout << "Mennyi szót szeretne felvenni?" << endl;
    cin >> n;
    cout << "Adjon meg " << n << "db szóköz nélküli stringet" << endl;
    string szavak[n];

    for(int i=0; i<n; i++){
        cin >> szavak[i];
    }

    string rovid =szavak[0];
    string hosszu = szavak[0];

    for(int i=0; i<n; i++){
        if(szavak[i].length()>hosszu.length()){
            hosszu =szavak[i];
        }
        if(szavak[i].length() < rovid.length()){
            rovid=szavak[i];
        }
    }

    cout << rovid << " " << hosszu << endl;

//3. Feladat
    Doboz dt[5] = {{1,1,1},{2,2,2},{3,3,3},{4,4,4},{5,5,5}};
    int magassag=0;
    for(int i=0; i<5; i++){
        magassag+=dt[i].magassag;
    }
    cout << "A dobozok magassaga: " << magassag << endl;

/*
6.	Olvassa be a randomok.txt állományt egy tetszőleges adatszerkezetbe. 
Soronként döntse el, hogy az adott sor átlaga kisebb-e mint 37. 
Az eldöntés eredményét (Igen/Nem) írja be soronként a kisebb.txt-be.
*/

    ifstream be ("C:/temp/randomok.txt");
    ofstream ki ("kisebb.txt");

    vector<vector<int>> adatok;
    string sor;

    while(getline(be, sor)){
        stringstream ss(sor);
        vector<int> egysor;
        int szam;

        while(ss >> szam){
            egysor.push_back(szam);
        }
        adatok.push_back(egysor);
    }

    for(vector<int> v : adatok){
        for(int i:v){
            cout << i << " ";
        }
        cout << endl;
    }

    for(int i=0; i<adatok.size(); i++){
        int osszeg=0;

        for(int j=0; j<adatok[i].size(); j++){
            osszeg+=adatok[i][j];
        }
        double atlag=(double) osszeg/adatok[i].size();
        //cout << atlag << endl;

        if(atlag<37){
            ki << "Igen" << endl;
        } else{
            ki << "Nem" << endl;
        }
    }
    be.close();
    ki.close();
}