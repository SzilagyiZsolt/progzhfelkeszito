#include <iostream>

using namespace std;

int main(){
    struct{ //anonim struktúra
        int szulev;
        string nev;
    } szemely1, szemely2;
    //int x, y;

    szemely1.szulev=2002;
    szemely1.nev="Béla";

    szemely2 = {2004, "Kitti"};

    cout << szemely1.nev << " " << szemely1.szulev << endl;

    szemely2 = szemely1;

    szemely1.nev = "Luca";

    cout << szemely1.nev << " " << szemely2.nev << endl;

    struct jarmu{
        string marka;
        string tipus;
        short int evjarat;
    };

    jarmu j1 = {"Suzuki", "Swift", 2004};
    jarmu j2 = {"Opel", "Astra", 1999};

    if(j1.evjarat > j2.evjarat){
        cout << j1.marka << " " << j1.tipus << " " << "fiatalabb" << endl;
    }
    else if(j1.evjarat == j2.evjarat){
        cout << "egyidősek" << endl;
    }
    else{
        cout << j2.marka << " " << j2.tipus << " " << "fiatalabb" << endl;
    }

    string st = "narancs";
    string& gyomulcs = st;
    //string& st           string & st           string &st

    gyomulcs = "alma";

    cout << st << " " << gyomulcs << endl;

    cout << &st << " " << &gyomulcs << endl;

    cout << &szemely1 << " " << &szemely1.szulev << " " << &szemely1.nev << " " << &szemely2 << endl;

    int a = 10;
    int* b = &a; //típusa pointer, értéke mindig memóriacím!

    cout << a << " " << &a << " " << b << " " << &b << endl;

    cout << sizeof(b) << endl;

    cout << *b << endl;

    *b = 15;
    cout << a << endl;

    int z = 1;
    int * zptr = &z;
    int ** zpptr = &zptr;
    int *** zppptr = &zpptr;

    cout << z << " " << *zptr << " " << **zpptr << " " << ***zppptr << endl;

    int t[5]= {1,2,3,4,5};
    cout << t << endl;

    int* tptr = t;

    cout << t << " " << &t[0] << " " << tptr << endl;

    cout << t[4] << " " << (&t[0])[4] << " " << tptr[4] << endl;

    for(int* ptr = &t[0]; ptr <= &t[4]; ptr++){
        cout << *ptr << " " << ptr << endl;
    }

    tptr = &t[4];
    while(tptr >= t){
        cout << *tptr << " " << tptr-- << endl;
    }

    *(t+4)=500; //*(&t[0]+4) = 500 ==> t[4] = 500

    for(int i = 0; i < 5; i++){
        *(t+i) = 5 - i;
        cout << *(t+i) << " ";
    }
    cout << endl;

    int tmp = *(t);
    *(t)=*(t+4);
    *(t+4)=tmp;
    for(int i = 0; i < 5; i++){
        cout << *(t+i) << " ";
    }
    cout << endl;




    int tomb2[5]= {1,3,5,7,9};
    int mtomb[5];
    int * kezdo_ptr = tomb2;
    int * veg_ptr = &tomb2[4];
    int * cel_ptr = mtomb;

    for(int* kezdo_ptr = &tomb2[0]; kezdo_ptr <= &tomb2[4]; kezdo_ptr++){
        cout << cel_ptr << endl;
    }
}