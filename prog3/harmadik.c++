#include <iostream>
using namespace std;

main(){
    //hátultesztelő ciklus 1...n alkalommal fut le
    //do - while
    int i=10;
    do{
        cout << i++ << endl;
    } while(i<10);

    //meghatározott/ előírt lépésszámú ciklus
    //for
    // for (ciklusváltozó inicializálása; futási feltétel; ciklusváltozó értékváltozása)
    for(int i = 0; i < 10; i++){
        cout << i << " ";
    }
    cout << endl;

    for(char c = 'z'; c >= 'a'; c--){
        cout << c;
    }
    cout << endl;

    for(char c = 'z'; c >= 'a'; c--){
        cout << char(toupper(c));
        cout << c;
    }
    cout << endl;

    for(char c = 'z'; c >= 'a'; c--){
        cout << char(c-('a'-'A')) << c;
    }
    cout << endl;

    for(char c = 'Z', x='z'; c >= 'a'; c--, x--){
        cout << c << x;
    }
    cout << endl;

    for(int i = 0;;){
        cout << ++i << " ";
        if(i == 5){
            break; //vezérlésátadó utasíás
        }
    }
    cout << endl;

    for(int i = 0; i < 10; i++){
        if((i%2==0) || (i%3==0)){
            continue; //vezérléstátadó utasítás
        }
        cout << i << " ";
    }
    cout << endl;

    //foreach
    //for(konténer 1 eleménk típusa. Változónév : konténer neve)
    int szamok[5]={1,2,3,4,5};

    for(int szam : szamok){
        cout << szam << " ";
    }
    cout << endl;

    //sizeof(szamok) ==> 20 byte ==> (int) 4byte * 5
    //sizeof(int) ==> 4byte
    for(int i=0; i< sizeof(szamok)/sizeof(int); i++){
        cout << szamok[i] << " ";
    } 
    cout << endl;

    int szamok2d[3][3]={
        {1,2,4},
        {4,5,7},
        {7,8,10}
    };

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << "szamok2d[" << i << "][" << j << "]:" << szamok2d[i][j] << endl;
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << szamok2d[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << szamok2d[i][j] << " ";
        }
        cout << endl;
    }

    //sorátlag
    for(int i = 0; i < 3; i++){
        int osszeg = 0;
        for(int j = 0; j < 3; j++){
            osszeg += szamok2d[i][j];
        }
        cout << osszeg/3.0f << endl;
    }
}