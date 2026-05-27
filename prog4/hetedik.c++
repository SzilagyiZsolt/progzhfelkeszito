#include<iostream>
#include<vector>

using namespace std;

//túlterhelés - azonos nevű, eltérű paraméterezési függvények

int test(){return 0;}
int test(int a){return 0;}
float test(double d){return 0;}
int test(int a, double b){return 0;}

//double test(int a){return 0;}

int absolute(int a){
    if(a<0){
        return -a;
    }
    return a;
}

float absolute(float a){
    if(a<0.0f){
        return -a;
    }
    return a;
}

vector<int>& operator << (vector<int>& u, int i){
    u.push_back(i);
    return u;
}

vector<int> operator + (vector<int> a, vector<int> b){
    for(int i:b){
        a.push_back(i);
    }
    return a;
}

void operator ++ (vector<int> a){
    for(int i=0; i< a.size(); i++){
        cout << a.at(i) << " ";
    }
    cout << endl;
}

struct szemely{
    string nev;
    int kor;

    void operator()(string n, int e){
        nev=n;
        kor=e;
    }
};
ostream& operator<<(ostream& os, szemely sz) {
        os << sz.nev << " " << sz.kor ;
        return os;
    }

istream& operator>>(istream& is, szemely sz){
    is >> sz.nev >> sz.kor;
    return is;
}

int main(){
    test();
    test(1);
    test(1.0);
    test(1, 2.1);

    cout << absolute(-1) << " " << absolute(-2.1f) << endl;

    vector<int> v={1,2,3};

    v.push_back(4);

    v << 5;

    for(int i:v){
        cout << i << " ";
    }
    cout << endl;

    v << 6 << 7 << 8;
    for(int i:v){
        cout << i << " ";
    }
    cout << endl;

    vector<int> va = {1,2,3,4};
    vector<int> vb = {5,6,7,8};

    vector<int> o = va+vb;

    ++o;

    szemely sz1;
    sz1.nev="András";
    sz1.kor=23;

    szemely sz2;
    sz2("Kitti", 33);

    cout << sz1 << " " << sz2 << endl;

    int x,y;

    cout << "Adjon meg egy egész számot!" << endl;

    cin >> x;

    cout << "Adjon meg még egy egész számot!" << endl;

    cin >> y;

    cout << "A két szám összege: " << x+y << endl;

    cout << "Adjon meg két egész számot!" << endl;

    cin >> x >> y;

    cout << "A két szám összege: " << x+y << endl;

    szemely sz3;

    cout << "Adja meg az adatait: " << endl;

    cin >> sz3.nev >> sz3.kor;

    cout << sz3 << endl;

    cin >> sz3;

    cout << sz3 << endl;
}