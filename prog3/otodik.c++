#include <iostream>

using namespace std;

//Eljárás
void print(int a, int b){
    cout << a << " " << b << endl;
}

//függvény
int multiply(int a, int b){
    return a*b;
}

void csere(int a, int b){
    int tmp = a;
    a=b;
    b=tmp;
    print(a,b);
}

//referencia szerinti paraméterátadás
void csere2(int& a, int& b){
    int tmp = a;
    a=b;
    b=tmp;
    //print(a,b);
}

//pointer
void csere3(int * a, int * b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void szoroz(int& a, int b){
    a=a*b++;
}

void tombkiir(int t[5]){
    for(int i=0; i<5; i++){
        cout << t[i]++ << " ";
    }
    cout << endl;
}

int minimum(int* t, int meret){
    int m=t[0];
    for(int i=0;i<meret;i++){
        if(t[i]<m){
            m=t[i];
        }
    }
    return m;
}
int feladat(int n){
    if(n>1){
        return n* feladat(n-1);
    } else {
        return 1;
    }
}
int fibo(int x){
    if((x==1)||(x==0)){
        return x;
    } else {
        return fibo(x-1) + fibo(x-2);
    }
}

int main(){
    //stack memória
    int a=1;
    int b[5];

    //heap memória
    //pointer-változó név=new típus
    //c malloc és free
    //c++ new és delete

    int* x = new int;
    int * tp = new int[5];

    int * p2 = new(nothrow) int;
    if(!p2){
        cout << "Memória allokáció nem sikerült" << endl;
    } else {
        *p2=10;
    }

    float *f = new float(11.12);
    *x = 5;

    for(int i=0; i<5; i++){
        tp[i]=i*2-1;
        cout << tp[i] << " ";
    }
    cout << endl;

    delete x;
    delete[] tp;
    delete p2;
    delete f;

    int y=2, z=4;

    //cout << y << " " << z << endl;
    print(y,z);

    int i = multiply(y,z);
    cout << i << endl;

    csere(y,z);
    print(y,z);

    csere2(y,z);
    print(y,z);

    csere3(&y, &z);
    print(y,z);

    szoroz(y,z);
    print(y,z);

    int t[5] = {1,3,5,7,9};

    tombkiir(t);
    //{2,5,7,9,11}
    tombkiir(t);
    //{3,5,7,9,11,13}

    cout << minimum(t,5) << endl;
    
    cout << feladat(5) << endl;
    cout << fibo(5) << endl;
}